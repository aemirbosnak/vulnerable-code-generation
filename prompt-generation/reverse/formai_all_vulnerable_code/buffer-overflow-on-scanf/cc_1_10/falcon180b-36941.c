//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: authentic
// This program simulates the motion of a projectile under the influence of gravity.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 // Acceleration due to gravity in m/s^2

// Function to calculate the time of flight of the projectile
double time_of_flight(double v0, double theta) {
    double g = G;
    double t = 2*v0*sin(theta)/g;
    return t;
}

// Function to calculate the maximum height reached by the projectile
double max_height(double v0, double theta) {
    double g = G;
    double h = v0*v0*sin(theta)*sin(theta)/(2*g);
    return h;
}

// Function to calculate the range of the projectile
double range(double v0, double theta) {
    double g = G;
    double v = v0*cos(theta);
    double t = 2*v0*sin(theta)/g;
    double x = v*t;
    double y = v0*sin(theta)*t - 0.5*g*t*t;
    double R = sqrt(x*x + y*y);
    return R;
}

int main() {
    double v0, theta, t, h, R;
    printf("Enter the initial velocity (in m/s): ");
    scanf("%lf", &v0);
    printf("Enter the launch angle (in degrees): ");
    scanf("%lf", &theta);

    // Convert the launch angle to radians
    theta = theta*M_PI/180;

    // Calculate the time of flight
    t = time_of_flight(v0, theta);

    // Calculate the maximum height reached by the projectile
    h = max_height(v0, theta);

    // Calculate the range of the projectile
    R = range(v0, theta);

    // Print the results
    printf("\nInitial velocity = %.2lf m/s\n", v0);
    printf("Launch angle = %.2lf degrees\n", theta*180/M_PI);
    printf("Time of flight = %.2lf s\n", t);
    printf("Maximum height = %.2lf m\n", h);
    printf("Range = %.2lf m\n", R);

    return 0;
}