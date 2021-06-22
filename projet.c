#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//--------------------Taille max--------------------------

#define MAXMAT 100


//--------------------TYPEDEF DE MATRICE--------------------------
typedef float matrice [MAXMAT] [MAXMAT];
struct matrfloat {
	int n;
	matrice m;
} ;
typedef struct matrfloat mat_t;

/*---------------Affichage-----------------------*/
void pritMat(mat_t m)
{
	for(int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			if (m.m[j][i]!=0)
			{
	printf("%f ", m.m[j][i]);	

			}


			else


			printf("");
		}
		printf("\n");
	}
}
/*--------------------Transposé------------------------------*/
void traspose(mat_t m)
{
	mat_t inv;
	int i, j;
	for (i = 0; i < m.n; ++i)
	{
		for (j = 0; j < m.n; ++j)
		{
			inv.m[i][j] = m.m[j][i];
		}
	}
	for (i = 0; i < m.n; ++i)
	{
		for (j = 0; j < m.n; ++j)
		{
			m.m[i][j] = inv.m[j][i];
		}
	}
}




/*---------------------------------------------------------*/
mat_t chol(mat_t m)
{
	mat_t r;
	r.n = m.n;
	int i, j, k;
	float somme, s, som;
        for(i = 0; i < m.n; i++)
	{
		somme = 0;
                for (j = 0; j <m.n; j++)
		{
			somme += r.m[j][i] * r.m[j][i];
		}
		s = m.m[i][i] - somme;
                printf("%f\n ", s);
		if (s <= 0)     //si s <= 0 la matrice n'est pas definie positive

		{
			printf("non positive\n");
			exit(-1);
		}
		else
		{
			r.m[i][i] = sqrt(s);
                        for (j = i+1; j < m.n; j++)
			{
				som = 0;
                                for (k = 0; k <= i-1; k++)
				{
					som += r.m[k][i] * r.m[k][j];
				}
				r.m[i][j] = (m.m[i][j] - som)/r.m[i][i];
			}
		}
	}
	return r;
}

//--------------------METHODE CREER--------------------------


mat_t creer (int nb) {
	mat_t m;
	int i, j, k, l, z, zi;
	m.n = nb;
	for (i = 0, k=nb; i < nb; i++) {
		l = k;
		if (i & 0x01)
		 k--;
		m.m[i][i] = (float) l;
		l >>= 2;
		for (j = i+1, z=1, zi = 0; j < nb; j++) {
			if (z == zi) {
				m.m[i][j] = (float) -l;
				m.m[j][i] = (float) -l;
				l >>= 2;
				z <<= 1;
				zi = 0;
			}else {
				m.m[i][j] = 0.0;
				m.m[j][i] = 0.0;
				zi++;
			}
		}
	}
return m;
}





///-------------------------------
int main (){


mat_t m;
int nb=MAXMAT;

m = creer(nb);

traspose(m);


pritMat(m);
mat_t n = chol(m);
pritMat(n);


}
