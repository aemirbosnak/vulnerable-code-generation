//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.674e-11 // Gravitational constant
#define PI 3.14159265358979323846 // Pi
#define DT 0.001 // Time step

// Define global variables
double x[100], y[100], vx[100], vy[100]; // Position and velocity of particles
int n; // Number of particles

// Function to calculate force between particles
void force(int i, int j) {
    double dx = x[j] - x[i];
    double dy = y[j] - y[i];
    double r = sqrt(dx*dx + dy*dy);
    double F = G * (x[i]*x[j] + y[i]*y[j]) / r*r;
    vx[i] -= F*dx/r;
    vy[i] -= F*dy/r;
    vx[j] += F*dx/r;
    vy[j] += F*dy/r;
}

// Function to update position and velocity of particles
void update() {
    for (int i=0; i<n; i++) {
        x[i] += vx[i]*DT;
        y[i] += vy[i]*DT;
    }
}

// Function to print particles
void print() {
    for (int i=0; i<n; i++) {
        printf("(%lf, %lf)\n", x[i], y[i]);
    }
}

int main() {
    printf("Enter number of particles: ");
    scanf("%d", &n);

    // Initialize positions and velocities of particles
    for (int i=0; i<n; i++) {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
        vx[i] = 0;
        vy[i] = 0;
    }

    // Run simulation
    for (int t=0; t<1000; t++) {
        printf("Time step %d:\n", t);
        print();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                force(i, j);
            }
        }
        update();
    }

    return 0;
}