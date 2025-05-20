//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_OF_PLANETS 8

struct planet {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double velocity_x;
    double velocity_y;
    double velocity_z;
};

typedef struct planet Planet;

void initialize_planet(Planet *p){
    printf("Enter name of planet: ");
    scanf("%s", p->name);
    printf("Enter mass of planet (kg): ");
    scanf("%lf", &p->mass);
    printf("Enter radius of planet (m): ");
    scanf("%lf", &p->radius);
    printf("Enter initial x-position of planet (m): ");
    scanf("%lf", &p->x);
    printf("Enter initial y-position of planet (m): ");
    scanf("%lf", &p->y);
    printf("Enter initial z-position of planet (m): ");
    scanf("%lf", &p->z);
    printf("Enter initial velocity of planet (m/s):\n");
    printf("velocity_x: ");
    scanf("%lf", &p->velocity_x);
    printf("velocity_y: ");
    scanf("%lf", &p->velocity_y);
    printf("velocity_z: ");
    scanf("%lf", &p->velocity_z);
}

void update_velocity(Planet *p, double ax, double ay, double az, double dt){
    p->velocity_x += ax*dt;
    p->velocity_y += ay*dt;
    p->velocity_z += az*dt;
}

void update_position(Planet *p, double dt){
    p->x += p->velocity_x*dt;
    p->y += p->velocity_y*dt;
    p->z += p->velocity_z*dt;
}

double distance(Planet *p1, Planet *p2){
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void gravitational_force(Planet *p1, Planet *p2, double *fx, double *fy, double *fz){
    const double G = 6.67408e-11; // gravitational constant (m^3.kg^-1.s^-2)
    double dist = distance(p1, p2);
    double force = G*p1->mass*p2->mass/(dist*dist);
    *fx = force*(p2->x - p1->x)/dist;
    *fy = force*(p2->y - p1->y)/dist;
    *fz = force*(p2->z - p1->z)/dist;
}

void update_acceleration_of_planet(Planet *planet, Planet *planets, int numOfPlanets){
    double ax = 0, ay = 0, az = 0;
    double fx, fy, fz;
    for(int i = 0; i < numOfPlanets; i++){
        if(planet != &planets[i]){
            gravitational_force(planet, &planets[i], &fx, &fy, &fz);
            ax += fx/planet->mass;
            ay += fy/planet->mass;
            az += fz/planet->mass;
        }
    }
    update_velocity(planet, ax, ay, az, 1);
}

int main(){
    Planet planets[NUM_OF_PLANETS];
    for(int i = 0; i < NUM_OF_PLANETS; i++){
        printf("Initializing planet %d\n", i+1);
        initialize_planet(&planets[i]);
    }
    
    double dt;
    printf("Enter time step (s): ");
    scanf("%lf", &dt);
    
    int t;
    printf("Enter number of time steps: ");
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        printf("Time step: %d\n", i+1);
        for(int j = 0; j < NUM_OF_PLANETS; j++){
            update_acceleration_of_planet(&planets[j], planets, NUM_OF_PLANETS);
        }
        for(int j = 0; j < NUM_OF_PLANETS; j++){
            update_position(&planets[j], dt);
        }
    }
    
    printf("\nResult:\n");
    for(int i = 0; i < NUM_OF_PLANETS; i++){
        printf("%s:\n", planets[i].name);
        printf("mass = %e kg\n", planets[i].mass);
        printf("radius = %e m\n", planets[i].radius);
        printf("position = (%e, %e, %e) m\n", planets[i].x, planets[i].y, planets[i].z);
        printf("velocity = (%e, %e, %e) m/s\n", planets[i].velocity_x, planets[i].velocity_y, planets[i].velocity_z);
        printf("\n");
    }
    
    return 0;
}