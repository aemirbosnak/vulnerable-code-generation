//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000
#define PI 3.14159265

typedef struct{
    double r;
    double c;
    double v;
}RC;

void solve(RC *p, int n, double dt){
    for(int i=0; i<n; i++){
        p[i].v = p[i].v + dt*(p[i+1].v - 2*p[i].v);
    }
}

int main(){
    int n;
    printf("Enter the number of RC elements: ");
    scanf("%d", &n);

    if(n > MAX)
        printf("Error: Maximum number of RC elements allowed is %d.\n", MAX);
    else{
        RC *p;
        p = (RC *)malloc(n*sizeof(RC));

        printf("Enter the values of resistance (in ohms) and capacitance (in farads):\n");
        for(int i=0; i<n; i++){
            scanf("%lf %lf", &p[i].r, &p[i].c);
        }

        double t = 0, dt = 0.01;
        double v = 1;
        p[0].v = v;

        while(t <= 0.5){
            solve(p, n, dt);
            t += dt;
        }

        printf("Output voltage: %lf\n", p[n-1].v);
        free(p);
    }

    return 0;
}