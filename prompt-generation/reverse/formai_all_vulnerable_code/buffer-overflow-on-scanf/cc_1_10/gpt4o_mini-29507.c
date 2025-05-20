//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define GRAVITY 9.81
#define TIME_INCREMENT 0.1
#define MAX_HEIGHT 20
#define MAX_LENGTH 100

void printTrajectory(float time, float x, float y) {
    printf("\033[H\033[J"); // Clear screen
    for (int row = MAX_HEIGHT; row >= 0; row--) {
        for (int col = 0; col <= MAX_LENGTH; col++) {
            if (col == 0 && row == 0) {
                printf("O"); // launch point
            } else if (col == (int)x && row == (int)y) {
                printf("*"); // projectile point
            } else if (row == 0) {
                printf("-"); // ground line
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    fflush(stdout);
    usleep(100000); // Sleep for 100 ms
}

int main() {
    float launchAngle, launchSpeed;

    printf("Enter launch angle (degrees): ");
    scanf("%f", &launchAngle);
    printf("Enter launch speed (m/s): ");
    scanf("%f", &launchSpeed);

    // Convert angle to radians
    float angleRad = launchAngle * (M_PI / 180.0);

    // Calculate time of flight, maximum height, and horizontal range
    float timeOfFlight = (2 * launchSpeed * sin(angleRad)) / GRAVITY;
    float maxHeight = (launchSpeed * sin(angleRad)) * (launchSpeed * sin(angleRad)) / (2 * GRAVITY);
    float horizontalRange = (launchSpeed * cos(angleRad)) * timeOfFlight;

    printf("Time of Flight: %.2f s\n", timeOfFlight);
    printf("Maximum Height: %.2f m\n", maxHeight);
    printf("Horizontal Range: %.2f m\n", horizontalRange);

    // Simulate the projectile motion
    float time = 0;
    while (time <= timeOfFlight) {
        float x = launchSpeed * cos(angleRad) * time;
        float y = (launchSpeed * sin(angleRad) * time) - (0.5 * GRAVITY * time * time);
        printTrajectory(time, x, y);
        time += TIME_INCREMENT;
    }

    return 0;
}