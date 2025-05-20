//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct particle{
    double x, y, vx, vy, ax, ay;
};

void draw(struct particle *p, int n){
    int i;
    system("clear");
    for(i=0; i<n; i++){
        printf("*");
        printf("%.2f %.2f\n", p[i].x, p[i].y);
    }
}

int main(){
    int n, i;
    struct particle p[100];
    printf("Enter number of particles: ");
    scanf("%d", &n);

    printf("Enter initial positions of particles:\n");
    for(i=0; i<n; i++){
        printf("Particle %d: ", i+1);
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    printf("Enter initial velocities of particles:\n");
    for(i=0; i<n; i++){
        printf("Particle %d: ", i+1);
        scanf("%lf %lf", &p[i].vx, &p[i].vy);
    }

    int m=0;
    double dt=0.01;

    while(1){
        draw(p, n);

        for(i=0; i<n; i++){
            p[i].x += p[i].vx*dt;
            p[i].y += p[i].vy*dt;
        }

        m++;
        if(m%10==0){
            dt*=0.9;
        }
    }

    return 0;
}