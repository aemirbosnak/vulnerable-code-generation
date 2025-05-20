//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
    double launch_velocity, launch_angle, gravity, time;
    int num_steps;
    
    // Prompt the user for input
    printf("Enter the launch velocity (m/s): ");
    scanf("%lf", &launch_velocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launch_angle);
    printf("Enter the acceleration due to gravity (m/s^2): ");
    scanf("%lf", &gravity);
    printf("Enter the number of steps to simulate (integer): ");
    scanf("%d", &num_steps);
    
    // Calculate the initial position and velocity of the projectile
    double initial_position = 0;
    double initial_velocity = launch_velocity * cos(launch_angle * M_PI / 180);
    double initial_time = 0;
    
    // Simulate the motion of the projectile using a 4th order Runge-Kutta method
    double h = 0.01; // step size
    for (int i = 0; i < num_steps; i++) {
        // Calculate the position at the current time step
        double x = initial_position + h * initial_velocity;
        double y = initial_position + h * initial_velocity * sin(launch_angle * M_PI / 180);
        double z = initial_position + h * gravity * (i + 1);
        
        // Calculate the velocity at the current time step
        double vx = initial_velocity + h * gravity / 2;
        double vy = initial_velocity * sin(launch_angle * M_PI / 180) + h * gravity / 2;
        double vz = initial_velocity * cos(launch_angle * M_PI / 180) - h * gravity;
        
        // Calculate the acceleration at the current time step
        double ax = -gravity * cos(launch_angle * M_PI / 180);
        double ay = -gravity * sin(launch_angle * M_PI / 180);
        double az = 0;
        
        // Calculate the new position and velocity at the current time step
        initial_position = x + h * vx;
        initial_velocity = vy + h * vz;
        
        // Print the current position and velocity of the projectile
        printf("Step %d: x=%lf, y=%lf, z=%lf, vx=%lf, vy=%lf, vz=%lf\n", i + 1, x, y, z, vx, vy, vz);
    }
    
    return 0;
}