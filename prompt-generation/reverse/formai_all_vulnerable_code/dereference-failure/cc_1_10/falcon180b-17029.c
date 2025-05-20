//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674 //Gravitational constant

//Structure for planet
typedef struct {
    double x, y, z, vx, vy, vz;
    double mass;
} Planet;

//Function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

//Function to calculate gravitational force between two planets
void gravity(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = distance(p1, p2);
    double force = G * p1.mass * p2.mass / (r*r);
    p1.vx -= force*dx/r;
    p1.vy -= force*dy/r;
    p1.vz -= force*dz/r;
    p2.vx += force*dx/r;
    p2.vy += force*dy/r;
    p2.vz += force*dz/r;
}

//Function to update position and velocity of a planet
void update(Planet *p, double dt) {
    p->x += p->vx*dt;
    p->y += p->vy*dt;
    p->z += p->vz*dt;
}

//Main function
int main() {
    int num_planets;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    Planet *planets = malloc(num_planets * sizeof(Planet));

    for(int i=0; i<num_planets; i++) {
        printf("Enter mass for planet %d: ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter initial position for planet %d (x y z): ", i+1);
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }

    double dt = 0.01; //Time step

    while(1) {
        for(int i=0; i<num_planets; i++) {
            for(int j=i+1; j<num_planets; j++) {
                gravity(planets[i], planets[j]);
            }
            update(&planets[i], dt);
        }
    }

    return 0;
}