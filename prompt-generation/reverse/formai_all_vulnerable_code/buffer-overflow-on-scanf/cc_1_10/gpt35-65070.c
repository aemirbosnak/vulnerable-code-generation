//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11

typedef struct {
    double x, y, z;
    double mass;
    double vx, vy, vz;
} Body;

typedef struct {
    double x, y, z;
    double vx, vy, vz;
} Acc;

int main() {
    int n = 3; //number of bodies
    double dt = 3600; //time step in seconds
    int steps = 24; //number of time steps to simulate
    int i, j, k;
    double d;
    Acc *acc = malloc(n * sizeof(Acc));
    Body *body = malloc(n * sizeof(Body));

    printf("Enter the initial properties of %d bodies:\n", n);
    for(i = 0; i < n; i++) {
        printf("Body %d:\n", i + 1);
        printf("   X: ");
        scanf("%lf", &body[i].x);
        printf("   Y: ");
        scanf("%lf", &body[i].y);
        printf("   Z: ");
        scanf("%lf", &body[i].z);
        printf("   Mass: ");
        scanf("%lf", &body[i].mass);
        printf("   VX: ");
        scanf("%lf", &body[i].vx);
        printf("   VY: ");
        scanf("%lf", &body[i].vy);
        printf("   VZ: ");
        scanf("%lf", &body[i].vz);
    }

    //simulation loop
    for(k = 0; k < steps; k++) {
        printf("#%d\n", k + 1);
        //calculate acceleration of each body
        for(i = 0; i < n; i++) {
            acc[i].x = acc[i].y = acc[i].z = 0;
            for(j = 0; j < n; j++) {
                if(i == j) continue;
                d = sqrt(pow(body[j].x - body[i].x, 2) + pow(body[j].y - body[i].y, 2) + pow(body[j].z - body[i].z, 2));
                acc[i].x += G * body[j].mass * (body[j].x - body[i].x) / pow(d, 3);
                acc[i].y += G * body[j].mass * (body[j].y - body[i].y) / pow(d, 3);
                acc[i].z += G * body[j].mass * (body[j].z - body[i].z) / pow(d, 3);
            }
        }
        //update velocity and position of each body
        for(i = 0; i < n; i++) {
            body[i].vx += dt * acc[i].x;
            body[i].vy += dt * acc[i].y;
            body[i].vz += dt * acc[i].z;
            body[i].x += dt * body[i].vx;
            body[i].y += dt * body[i].vy;
            body[i].z += dt * body[i].vz;
            printf("Body %d: (%.2f, %.2f, %.2f)\n", i + 1, body[i].x, body[i].y, body[i].z);
        }
    }

    free(body);
    free(acc);
    return 0;
}