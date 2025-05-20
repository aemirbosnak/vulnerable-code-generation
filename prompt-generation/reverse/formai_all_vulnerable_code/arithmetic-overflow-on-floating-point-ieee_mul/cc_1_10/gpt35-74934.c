//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Exciting Physics Simulation */
/* By Chatbot */

/* Let's simulate a cannonball being fired at a target */
int main()
{
    srand(time(NULL));  // Seed for random numbers
    double v0, theta, t, x, y;  // Declare variables
    const double g = 9.8;  // Acceleration due to gravity

    printf("Welcome to the Cannonball Simulator!\n");
    printf("\nEnter initial velocity in m/s: ");
    scanf("%lf", &v0);  // Read in initial velocity
    printf("Enter firing angle in degrees: ");
    scanf("%lf", &theta);  // Read in firing angle

    theta = theta * M_PI / 180;  // Convert degrees to radians
    
    t = 0;  // Initialize time to zero
    x = 0;  // Initialize x position to zero
    y = 0;  // Initialize y position to zero
    
    printf("\n==============================================\n");
    printf("FIRING CANNONBALL!!!\n");
    printf("Initial Velocity: %.2fm/s\n", v0);
    printf("Firing Angle: %.2f degrees = %.2f radians\n", theta * 180 / M_PI, theta);
    printf("==============================================\n\n");
    
    while (y >= 0) {  // Simulate cannonball flight until it hits ground
        printf("t=%.2f, x=%.2f, y=%.2f\n", t, x, y);  // Display current time, x position, and y position
        x = v0 * cos(theta) * t;  // Calculate x position
        y = v0 * sin(theta) * t - 0.5 * g * t * t;  // Calculate y position
        t += 0.1;  // Increment time by 0.1 seconds
        double randnum = (double)rand() / RAND_MAX;  // Random number between 0 and 1
        if (randnum < 0.05) {  // Add some randomness to the simulation
            printf("\n==============================================\n");
            printf("WIND GUST DETECTED!!!\n");
            printf("==============================================\n\n");
            v0 += randnum * 10;  // Increase velocity by up to 10%
        }
    }
    
    printf("\n==============================================\n");
    printf("CANNONBALL HIT GROUND!!!\n");
    printf("Final time: %.2f seconds\n", t);
    printf("Final x position: %.2f meters\n", x);
    printf("==============================================\n\n");
    
    return 0;
}