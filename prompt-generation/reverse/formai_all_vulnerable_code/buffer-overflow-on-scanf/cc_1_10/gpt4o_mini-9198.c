//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81
#define TIME_STEP 0.1
#define MAX_TIME 10.0
#define GROUND_LEVEL 20
#define WIDTH 70

void print_ground(int height) {
    for (int i = 0; i < WIDTH; i++) {
        printf(" ");
    }
    printf("|\n");
    for (int i = 0; i < height; i++) {
        printf(" ");
    }
    for (int i = 0; i < WIDTH; i++) {
        printf(" ");
    }
    printf("|\n");
}

void plot_trajectory(float initial_velocity, float angle) {
    float radians = angle * (M_PI / 180);
    float initial_velocity_x = initial_velocity * cos(radians);
    float initial_velocity_y = initial_velocity * sin(radians);
  
    float time = 0.0;
    float height, position_x;

    while (time <= MAX_TIME) {
        height = (initial_velocity_y * time) - (0.5 * GRAVITY * time * time);
        position_x = initial_velocity_x * time;

        if (height < 0) break; // Stop if the projectile hits the ground

        int height_display = (int)(GROUND_LEVEL - height);
        int position_x_display = (int)position_x;

        printf("\033[H\033[J"); // Clear the screen
        print_ground(height_display);
        for (int i = 0; i <= height_display; i++) {
            printf(" ");
        }
        for (int i = 0; i < position_x_display; i++) {
            printf(" ");
        }
        printf("o\n"); // The projectile

        usleep(50000); // Delay to visualize the projectile's motion
        time += TIME_STEP;
    }
}

int main() {
    float initial_velocity;
    float angle;

    printf("Enter the initial velocity (m/s): ");
    scanf("%f", &initial_velocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%f", &angle);

    // Validate user input
    if (initial_velocity <= 0 || angle < 0 || angle > 90) {
        printf("Invalid input. Please ensure that velocity is greater than 0 and angle is between 0 and 90 degrees.\n");
        return 1;
    }

    plot_trajectory(initial_velocity, angle);
    printf("Simulation finished.\n");

    return 0;
}