//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11  //Gravitational constant

struct planet {
    char name[20];
    double mass;
    double radius;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
    double x_acc;
    double y_acc;
};

void simulate_gravity(struct planet *p, int n, double dt)
{
    for(int i=0; i<n; i++) {
        double x_acc=0.0, y_acc=0.0; //initialize acceleration to zero
        //calculating acceleration
        for(int j=0; j<n; j++) {
            if(i!=j) {
                double dist = sqrt(pow(p[j].x_pos - p[i].x_pos, 2) + pow(p[j].y_pos - p[i].y_pos, 2));
                double force = G * p[i].mass * p[j].mass / pow(dist, 2);
                x_acc += force * (p[j].x_pos - p[i].x_pos) / dist / p[i].mass;
                y_acc += force * (p[j].y_pos - p[i].y_pos) / dist / p[i].mass;
            }
        }
        p[i].x_acc = x_acc;
        p[i].y_acc = y_acc;
        //updating position and velocity
        p[i].x_vel += x_acc * dt;
        p[i].y_vel += y_acc * dt;
        p[i].x_pos += p[i].x_vel * dt;
        p[i].y_pos += p[i].y_vel * dt;
    }
}

int main()
{
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    struct planet *p = (struct planet*) malloc(n * sizeof(struct planet));
    printf("Enter the name, mass, radius, x_pos, y_pos, x_vel, and y_vel of each planet:\n");
    for(int i=0; i<n; i++) {
        scanf("%s %lf %lf %lf %lf %lf %lf", p[i].name, &p[i].mass, &p[i].radius, &p[i].x_pos, &p[i].y_pos, &p[i].x_vel, &p[i].y_vel);
        p[i].x_acc = 0.0;
        p[i].y_acc = 0.0;
    }
    double t = 0.0, dt = 0.01; //initialize time to zero and timestep to 0.01 seconds
    int steps = 10000; //simulate for 100 seconds
    for(int i=0; i<steps; i++) {
        t += dt;
        simulate_gravity(p, n, dt);
        printf("Time: %.2lf seconds\n", t);
        for(int j=0; j<n; j++) {
            printf("%s: position = (%.2lf, %.2lf), velocity = (%.2lf, %.2lf)\n", p[j].name, p[j].x_pos, p[j].y_pos, p[j].x_vel, p[j].y_vel);
        }
        printf("\n");
    }
    free(p);
    return 0;
}