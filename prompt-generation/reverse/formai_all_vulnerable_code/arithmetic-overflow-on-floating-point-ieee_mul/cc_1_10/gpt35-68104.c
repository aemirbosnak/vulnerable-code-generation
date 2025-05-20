//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743 * pow(10, -11)

//a structure to hold planet data
typedef struct Planet {
    char name[20];
    double mass;
    double pos[3];
    double vel[3];
    double acc[3];
} planet_t;

//function to initialize planets
void initPlanet(planet_t *p, char name[], double mass, double pos[], double vel[]) {
    strcpy(p->name, name);
    p->mass = mass;
    for (int i = 0; i < 3; i++) {
        p->pos[i] = pos[i];
        p->vel[i] = vel[i];
        p->acc[i] = 0.0;
    }
}

//function to calculate distance between 2 planets
double dist(planet_t *p1, planet_t *p2) {
    double distance = 0.0;
    for (int i = 0; i < 3; i++) {
        distance += pow(p1->pos[i] - p2->pos[i], 2);
    }
    return sqrt(distance);
}

//function to update acceleration for each planet
void updateAcc(planet_t p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double d = dist(&p[i], &p[j]);
                double f = G * p[i].mass * p[j].mass / pow(d, 2);
                double coef = f / d;
                for (int k = 0; k < 3; k++) {
                    p[i].acc[k] += coef * (p[j].pos[k] - p[i].pos[k]);
                }
            }
        }
    }
}

//function to update velocity for each planet
void updateVel(planet_t p[], int n, double dt) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            p[i].vel[j] += p[i].acc[j] * dt;
        }
    }
}

//function to update position for each planet
void updatePos(planet_t p[], int n, double dt) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            p[i].pos[j] += p[i].vel[j] * dt;
        }
    }
}

int main() {
    //creating 3 planets
    planet_t earth, moon, mars;

    //initializing planets
    double pos1[] = {0, 0, 0};
    double vel1[] = {0, 0, 0};
    initPlanet(&earth, "Earth", 5.9722 * pow(10, 24), pos1, vel1);

    double pos2[] = {384400000, 0, 0};
    double vel2[] = {0, 1022, 0};
    initPlanet(&moon, "Moon", 7.34 * pow(10, 22), pos2, vel2);

    double pos3[] = {0, 227920000, 0};
    double vel3[] = {24130, 0, 0};
    initPlanet(&mars, "Mars", 6.4171 * pow(10, 23), pos3, vel3);

    //simulation parameters
    double dt = 3600 * 24;
    int steps = 365;

    //run simulation
    for (int i = 0; i < steps; i++) {
        updateAcc(&earth, 1);
        updateAcc(&moon, 1);
        updateAcc(&mars, 1);

        updatePos(&earth, 1, dt);
        updateVel(&earth, 1, dt);
        updatePos(&moon, 1, dt);
        updateVel(&moon, 1, dt);
        updatePos(&mars, 1, dt);
        updateVel(&mars, 1, dt);

        printf("Day %d: Earth x=%f, y=%f, z=%f\n", i+1, earth.pos[0], earth.pos[1], earth.pos[2]);
        printf("Day %d: Moon x=%f, y=%f, z=%f\n", i+1, moon.pos[0], moon.pos[1], moon.pos[2]);
        printf("Day %d: Mars x=%f, y=%f, z=%f\n", i+1, mars.pos[0], mars.pos[1], mars.pos[2]);
    }

    return 0;
}