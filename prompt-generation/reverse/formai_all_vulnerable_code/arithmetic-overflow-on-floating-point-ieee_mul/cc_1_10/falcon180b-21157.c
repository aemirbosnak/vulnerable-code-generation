//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 6.674e-11
#define DAY 86400

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    double m;
    Vector p;
    Vector v;
} Body;

Body sun, earth, moon;

void init() {
    srand(time(NULL));

    sun.m = 1.9885e30;
    sun.p.x = 0;
    sun.p.y = 0;
    sun.p.z = 0;
    sun.v.x = 0;
    sun.v.y = 0;
    sun.v.z = 0;

    earth.m = 5.972e24;
    earth.p.x = 1.496e11;
    earth.p.y = 0;
    earth.p.z = 0;
    earth.v.x = 0;
    earth.v.y = 0;
    earth.v.z = 0;

    moon.m = 7.347e22;
    moon.p.x = 6.773e10;
    moon.p.y = 0;
    moon.p.z = 0;
    moon.v.x = 0;
    moon.v.y = 0;
    moon.v.z = 0;
}

void update() {
    Vector r_e = {earth.p.x, 0, 0};
    Vector r_m = {moon.p.x, 0, 0};
    Vector v_e = {earth.v.x, 0, 0};
    Vector v_m = {moon.v.x, 0, 0};
    Vector a_m = {0, 0, 0};

    double F_g = G * sun.m / pow(earth.p.x, 2);
    earth.v.x += F_g * cos(earth.p.x / earth.p.x);

    F_g = G * earth.m / pow(moon.p.x, 2);
    moon.v.x += F_g * cos(moon.p.x / moon.p.x);

    double F_e = G * earth.m / pow(moon.p.x, 2);
    moon.v.x += F_e * cos(moon.p.x / moon.p.x);
}

void draw() {
    printf("Sun\n");
    printf("Earth\n");
    printf("Moon\n");
}

int main() {
    init();

    while (1) {
        update();
        draw();
        sleep(1);
    }

    return 0;
}