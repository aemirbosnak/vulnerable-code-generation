//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initializations
    int battery_level = 100;
    int altitude = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int throttle = 0;

    // Introduction
    printf("Welcome to C Drone Remote Control Program\n\n");

    // User input for battery level
    printf("Enter the current battery level (0 - 100): ");
    scanf("%d", &battery_level);

    // Check if battery level is valid
    if (battery_level < 0 || battery_level > 100) {
        printf("Invalid battery level! Please enter a number between 0 and 100.\n");
        exit(0);
    }

    // User input for altitude
    printf("Enter the current altitude (in meters): ");
    scanf("%d", &altitude);

    // User input for pitch, roll and yaw
    printf("Enter the pitch (in degrees): ");
    scanf("%d", &pitch);
    printf("Enter the roll (in degrees): ");
    scanf("%d", &roll);
    printf("Enter the yaw (in degrees): ");
    scanf("%d", &yaw);

    // User input for throttle
    printf("Enter the throttle (0 - 100): ");
    scanf("%d", &throttle);

    // Check if throttle is valid
    if (throttle < 0 || throttle > 100) {
        printf("Invalid throttle! Please enter a number between 0 and 100.\n");
        exit(0);
    }

    // Display entered values
    printf("\nEntered values:\n");
    printf("Battery level: %d%%\n", battery_level);
    printf("Altitude: %d meters\n", altitude);
    printf("Pitch: %d degrees\n", pitch);
    printf("Roll: %d degrees\n", roll);
    printf("Yaw: %d degrees\n", yaw);
    printf("Throttle: %d%%\n", throttle);

    // Drone movements
    printf("\nDrone movements:\n");
    printf("Moving forward with pitch of %d degrees\n", pitch);
    printf("Moving left with roll of %d degrees\n", roll);
    printf("Turning left with yaw of %d degrees\n", yaw);
    printf("Ascending with throttle of %d%%\n", throttle);

    // Landing the drone
    printf("\nLanding the drone...\n");
    for (int i = altitude; i >= 0; i--) {
        printf("Descending to altitude: %d meters\n", i);
    }
    printf("Drone has landed.\n");

    return 0;
}