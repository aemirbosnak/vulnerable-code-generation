//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define GRAVITY 9.81
#define TIME_STEP 0.1
#define MAX_TIME 10.0
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

void clear_screen() {
    printf("\033[H\033[J");
}

void display_trajectory(double angle, double velocity) {
    double radians = angle * (M_PI / 180.0);
    double time_of_flight = (2 * velocity * sin(radians)) / GRAVITY;
    double max_range = (velocity * cos(radians)) * time_of_flight;
    
    printf("Projectile launched with angle: %.2f degrees and velocity: %.2f m/s\n", angle, velocity);
    printf("Time of flight: %.2f s\n", time_of_flight);
    printf("Max range: %.2f m\n", max_range);
    printf("\nTrajectory:\n");

    for (double t = 0; t <= MAX_TIME; t += TIME_STEP) {
        double x = velocity * cos(radians) * t;
        double y = velocity * sin(radians) * t - 0.5 * GRAVITY * t * t;

        if (y < 0) {
            break; // If the projectile hits the ground, stop the simulation
        }
        
        int screen_x = (int)(x / max_range * SCREEN_WIDTH);
        int screen_y = SCREEN_HEIGHT - (int)(y / (velocity * sin(radians)) * SCREEN_HEIGHT);
        
        clear_screen();
        for (int row = 0; row < SCREEN_HEIGHT; row++) {
            for (int col = 0; col < SCREEN_WIDTH; col++) {
                if (row == screen_y && col == screen_x) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        usleep(100000); // Reduce the speed of the simulation
    }

    printf("\nSimulation complete. The projectile has hit the ground.\n");
}

int main() {
    double angle, velocity;

    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &angle);
    
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &velocity);

    if (angle < 0 || angle > 90 || velocity < 0) {
        printf("Invalid input! Angle should be between 0 and 90 degrees, velocity should be non-negative.\n");
        return -1;
    }

    display_trajectory(angle, velocity);
    
    return 0;
}