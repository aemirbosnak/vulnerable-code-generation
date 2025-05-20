//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int speed = 0; // Speed of the vehicle, in MPH
    int direction = 0; // Direction of the vehicle, in degrees
    int battery_life = 100; // Battery life remaining, in percentage
    int distance_traveled = 0; // Distance traveled, in miles

    // Main loop
    while (battery_life > 0)
    {
        printf("Battery life remaining: %d%%\n", battery_life);
        printf("Distance traveled: %d miles\n", distance_traveled);

        // Ask user for input
        printf("Enter speed in MPH (0-100): ");
        scanf("%d", &speed);

        // Check for valid input
        if (speed < 0 || speed > 100)
        {
            printf("Invalid speed. Please enter a value between 0 and 100.\n");
            continue;
        }

        printf("Enter direction in degrees (0-359): ");
        scanf("%d", &direction);

        // Check for valid input
        if (direction < 0 || direction > 359)
        {
            printf("Invalid direction. Please enter a value between 0 and 359.\n");
            continue;
        }

        // Update distance traveled based on speed and direction
        distance_traveled += speed * (rand() % 10 + 1);
        battery_life -= rand() % 10 + 1;

        printf("Distance traveled: %d miles\n", distance_traveled);
        printf("Battery life remaining: %d%%\n", battery_life);
    }

    printf("Battery life has run out. Vehicle is no longer in operation.\n");

    return 0;
}