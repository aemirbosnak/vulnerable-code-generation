//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define M 100

void rk4(double h,double t,double y[],void (*dydt)(double,void*,double*),void *params);

/* a simple model for protein-ligand interactions */
void dydt(double t,void *params,double *y)
{
    double *k = (double*)params;
    double k1 = k[0], k2 = k[1], k3 = k[2], E0 = k[3], L0 = k[4];
    double P = y[0], L = y[1], C = y[2];

    double dPdt = k1*(E0-P)*(L0-L) - k2*P;
    double dLdt = -k1*(E0-P)*(L0-L) - k3*L*(L0-L);
    double dCdt = k2*P - k3*L*(L0-L);

    y[0] += dPdt;
    y[1] += dLdt;
    y[2] += dCdt;
}

int main()
{
    double t = 0, h = 0.01;
    double y[3] = {N/2,M/2,0}, k[5] = {0.1,0.05,0.05,N-100,M/2};
    int i, j;

    printf("# time Protein Ligand Complex\n");
    for(i = 0; i < 1000; i++) {
        rk4(h, t, y, dydt, k);
        t += h;

        /* visualize the state of the system */
        printf("%f ",t);
        for(j = 0; j < 3; j++)
            printf("%f ",y[j]);
        printf("\n");
    }

    return 0;
}

/* 4th-order Runge-Kutta integration */
void rk4(double h,double t,double y[],void (*dydt)(double,void*,double*),void *params)
{
    double *k1 = malloc(3*sizeof(double));
    double *k2 = malloc(3*sizeof(double));
    double *k3 = malloc(3*sizeof(double));
    double *k4 = malloc(3*sizeof(double));
    double *tmp = malloc(3*sizeof(double));

    dydt(t, params, k1);
    int i;
    for(i = 0; i < 3; i++)
        tmp[i] = y[i] + h*k1[i]/2;
    dydt(t + h/2, params, k2);
    for(i = 0; i < 3; i++)
        tmp[i] = y[i] + h*k2[i]/2;
    dydt(t + h/2, params, k3);
    for(i = 0; i < 3; i++)
        tmp[i] = y[i] + h*k3[i];
    dydt(t + h, params, k4);
    for(i = 0; i < 3; i++)
        y[i] += h*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6;

    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(tmp);
}