//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G  6.674e-11  // Gravitational constant

// Function to calculate gravitational force
double force(double m1, double m2, double r){
    return G * m1 * m2 / (r * r);
}

// Function to calculate acceleration of given particle
double acceleration(double F, double m){
    return F / m;
}

// Function to calculate distance between two particles
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

// Function to update velocity of given particle
double uVelocity(double u, double a, double t){
    return u + a * t;
}

// Function to update position of given particle
double uPosition(double s, double u, double a, double t){
    return s + u * t + 0.5 * a * t * t;
}

int main(){
    // Defining particles
    double x[3] = {0, 0, 5e7};  // x-coordinates
    double y[3] = {0, 5e7, 0};  // y-coordinates
    double vx[3] = {0, 3000, 0};  // x-velocity
    double vy[3] = {0, 0, 3000};  // y-velocity
    double m[3] = {6e24, 6e24, 1e5};  // mass

    // Defining simulation parameters
    double t = 0;  // current time
    double dt = 100;  // time step

    while(t <= 3.154e7){ // Run simulation for one year (3.154e7 seconds)
        // Calculate pairwise forces between particles
        double F[3][3] = {0};  // initialize force matrix to zero
        for(int i = 0; i < 3; i++){
            for(int j = i+1; j < 3; j++){
                double r = distance(x[i], y[i], x[j], y[j]);
                double Fij = force(m[i], m[j], r);
                F[i][j] = Fij;
                F[j][i] = -Fij;
            }
        }

        // Update velocities and positions of particles
        for(int i = 0; i < 3; i++){
            double ax = 0, ay = 0;  // initialize accelerations to zero
            for(int j = 0; j < 3; j++){
                if(i != j){ // Don't calculate acceleration due to particle itself
                    double Fij = F[i][j];
                    double aij = acceleration(Fij, m[i]);
                    double theta = atan2((y[j]-y[i]), (x[j]-x[i])); // angle between particles
                    ax += aij * cos(theta); // acceleration in x-direction
                    ay += aij * sin(theta); // acceleration in y-direction
                }
            }
            vx[i] = uVelocity(vx[i], ax, dt); // update x-velocity
            vy[i] = uVelocity(vy[i], ay, dt); // update y-velocity
            x[i] = uPosition(x[i], vx[i], ax, dt); // update x-position
            y[i] = uPosition(y[i], vy[i], ay, dt); // update y-position
        }

        // Print current positions of particles
        printf("Time: %g seconds\n", t);
        for(int i = 0; i < 3; i++){
            printf("Particle %d: (%g, %g)\n", i+1, x[i], y[i]);
        }
        printf("\n");

        // Update time
        t += dt;
    }
    return 0;
}