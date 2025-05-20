//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11
#define M 5.97219e24

int main() {
    double x, y, z, r;
    double dx, dy, dz, dr;
    double vx, vy, vz, v;
    double px, py, pz, p;
    double ax, ay, az, a;
    double e, i;
    int steps;

    printf("Enter the number of steps: ");
    scanf("%d", &steps);

    printf("Enter the initial x coordinate: ");
    scanf("%lf", &x);
    printf("Enter the initial y coordinate: ");
    scanf("%lf", &y);
    printf("Enter the initial z coordinate: ");
    scanf("%lf", &z);

    printf("Enter the initial velocity x component: ");
    scanf("%lf", &vx);
    printf("Enter the initial velocity y component: ");
    scanf("%lf", &vy);
    printf("Enter the initial velocity z component: ");
    scanf("%lf", &vz);

    printf("Enter the initial acceleration x component: ");
    scanf("%lf", &ax);
    printf("Enter the initial acceleration y component: ");
    scanf("%lf", &ay);
    printf("Enter the initial acceleration z component: ");
    scanf("%lf", &az);

    printf("Enter the initial momentum x component: ");
    scanf("%lf", &px);
    printf("Enter the initial momentum y component: ");
    scanf("%lf", &py);
    printf("Enter the initial momentum z component: ");
    scanf("%lf", &pz);

    for (int i = 0; i < steps; i++) {
        r = sqrt(x*x + y*y + z*z);
        e = 1 - (M * G) / (r * r);
        i = acos(e);
        v = sqrt(vx*vx + vy*vy + vz*vz);
        p = sqrt(px*px + py*py + pz*pz);
        px = p*sin(i);
        py = p*cos(i);
        pz = 0;
        a = (G * M * (px*px + py*py + pz*pz)) / r*r;
        ax = a*sin(i);
        ay = a*cos(i);
        az = 0;
        dx = v*sin(i);
        dy = v*cos(i);
        dz = 0;
        x += dx;
        y += dy;
        z += dz;
        vx += ax;
        vy += ay;
        vz += az;
    }

    printf("Final position x: %lf\n", x);
    printf("Final position y: %lf\n", y);
    printf("Final position z: %lf\n", z);
    printf("Final velocity x: %lf\n", vx);
    printf("Final velocity y: %lf\n", vy);
    printf("Final velocity z: %lf\n", vz);
    printf("Final acceleration x: %lf\n", ax);
    printf("Final acceleration y: %lf\n", ay);
    printf("Final acceleration z: %lf\n", az);

    return 0;
}