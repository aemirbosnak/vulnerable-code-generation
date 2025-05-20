//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the gravitational force between two objects
double gravity(double m1, double m2, double d) {
    return G * m1 * m2 / pow(d, 2);
}

// Function to calculate the acceleration of an object due to gravity
double acceleration(double m1, double m2, double d, double vx, double vy) {
    double f = gravity(m1, m2, d);
    double ax = f * cos(atan2(vy, vx));
    double ay = f * sin(atan2(vy, vx));
    return ax;
}

// Function to update the position and velocity of an object
void update(double *x, double *y, double *vx, double *vy, double dt, double ax, double ay) {
    *x += *vx * dt;
    *y += *vy * dt;
    *vx += ax * dt;
    *vy += ay * dt;
}

// Function to simulate the motion of a planet
void planet(double m, double x, double y, double vx, double vy, double dt) {
    srand(time(NULL));
    int count = 0;
    double ax, ay;
    while (count < 100) {
        ax = acceleration(m, 1, distance(x, y, 0, 0), vx, vy);
        ay = 0;
        update(&x, &y, &vx, &vy, dt, ax, ay);
        count++;
    }
}

// Main function
int main() {
    double m = 1;
    double x = 0;
    double y = 0;
    double vx = 0;
    double vy = 0;
    double dt = 0.01;
    planet(m, x, y, vx, vy, dt);
    return 0;
}