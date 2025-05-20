//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
/* This physics simulation program simulates the motion of a pendulum. */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {

    float length, mass, initial_angle, time_elapsed, time_step, damping_ratio, angular_frequency;
    float theta, theta_dot, theta_prev;

    printf("Enter the length of the pendulum (in meters): ");
    scanf("%f", &length);

    printf("Enter the mass of the pendulum (in kilograms): ");
    scanf("%f", &mass);

    printf("Enter the initial angle (in degrees): ");
    scanf("%f", &initial_angle);

    printf("Enter the time elapsed (in seconds): ");
    scanf("%f", &time_elapsed);

    printf("Enter the time step (in seconds): ");
    scanf("%f", &time_step);

    printf("Enter the damping ratio: ");
    scanf("%f", &damping_ratio);

    angular_frequency = sqrt(9.81/length);

    theta = initial_angle * PI / 180;
    theta_dot = 0;

    printf("Time (s) \t Angle (radians) \n");

    for (float t = 0; t <= time_elapsed; t += time_step) {

        float force = -mass * 9.81 * sin(theta) - damping_ratio * theta_dot;

        theta_prev = theta;
        theta = 2*theta - theta_prev + (time_step*time_step*force)/(mass*length*length);
        theta_dot = (theta - theta_prev)/time_step;

        printf("%.2f \t %.3f\n", t, theta);

    }

    return 0;
}