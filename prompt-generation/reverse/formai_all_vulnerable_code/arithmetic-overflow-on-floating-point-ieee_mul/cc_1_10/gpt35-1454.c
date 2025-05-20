//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 10
#define Dim 3
#define G 6.67408e-11

double mass[N] = {1.989e30, 5.98e24, 6.39e23, 3.30e23, 4.87e24, 5.97e24, 6.42e23, 1.90e27, 5.68e26, 8.68e25};
double pos[N][Dim] = {{0,0,0}, {1.496e11,0,0}, {0,2.279e11,0}, {-2.066e11,0,0}, {0,-5.79e10,0}, {0,0,3.844e8}, {0,0,-2.278e11}, {7.78e11,0,0}, {1.431e12,0,0}, {-1.775e12,0,0}};
double vel[N][Dim] = {{0,0,0}, {0,2.978e4,0}, {-2.41e4,0,0}, {0,-2.99e4,0}, {-4.47e4,0,0}, {1022,0,0}, {0,0,3.51e4}, {0,1.074e4,0}, {0,-6.09e3,0}, {0,6.24e3,0}};

double distance(double pos1[Dim], double pos2[Dim]);
void gravitational_force(double pos1[Dim], double pos2[Dim], double F[Dim]);
void acceleration(double F[N][Dim], double acc[N][Dim]);
void update_state(double x[N][Dim], double v[N][Dim], double a[N][Dim], double dt);
void print_state(double x[N][Dim], double v[N][Dim]);

int main()
{
    double F[N][Dim], a[N][Dim], t, dt = 24*3600;
    int i, j;

    for(t=0; t<86400*365*10; t+=dt)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(j==i)
                    continue;
                double F_temp[Dim];
                gravitational_force(pos[i], pos[j], F_temp);
                F[i][0] += F_temp[0];
                F[i][1] += F_temp[1];
                F[i][2] += F_temp[2];
            }
        }
        acceleration(F, a);
        update_state(pos, vel, a, dt);
        print_state(pos, vel);
    }
    return 0;
}

double distance(double pos1[Dim], double pos2[Dim])
{
    double d = 0;
    int i;
    for(i=0; i<Dim; i++)
        d += pow((pos1[i]-pos2[i]), 2);
    return sqrt(d);
}

void gravitational_force(double pos1[Dim], double pos2[Dim], double F[Dim])
{
    double dist, f;
    int i;
    dist = distance(pos1, pos2);
    f = G*mass[0]*mass[1]/pow(dist, 2);
    for(i=0; i<Dim; i++)
        F[i] = f*(pos2[i]-pos1[i])/dist;
}

void acceleration(double F[N][Dim], double acc[N][Dim])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<Dim; j++)
        {
            acc[i][j] = F[i][j]/mass[i];
        }
    }
}

void update_state(double x[N][Dim], double v[N][Dim], double a[N][Dim], double dt)
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<Dim; j++)
        {
            x[i][j] += v[i][j]*dt + 0.5*a[i][j]*pow(dt, 2);
            v[i][j] += a[i][j]*dt;
        }
    }
}

void print_state(double x[N][Dim], double v[N][Dim])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        printf("Body %d:\n", i);
        printf("Position: ");
        for(j=0; j<Dim; j++)
            printf("%.2e ", x[i][j]);
        printf("\nVelocity: ");
        for(j=0; j<Dim; j++)
            printf("%.2e ", v[i][j]);
        printf("\n");
    }
    printf("\n");
}