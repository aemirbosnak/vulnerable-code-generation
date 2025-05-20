//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
int getRandom(int min, int max);

int main()
{
    // Randomize seed
    srand(time(0));

    // Variables declaration
    int speed = 0, direction = 0, gear = 1, distance = 0;
    char vehicle[20] = "RC Car";

    // Main loop
    while (1)
    {
        printf("\n%s Control Panel\n", vehicle);
        printf("---------------------\n");
        printf("Current Speed: %d mph\n", speed);
        printf("Current Direction: %d degrees\n", direction);
        printf("Current Gear: %d\n", gear);
        printf("Current Distance: %d ft\n", distance);
        printf("---------------------\n");

        // Menu options
        printf("\nMenu:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Change direction\n");
        printf("4. Change gear\n");
        printf("5. Exit control panel\n");

        // User input
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Options execution
        switch (choice)
        {
            case 1:
                // Increase speed
                speed += getRandom(1, 5);
                break;
            case 2:
                // Decrease speed
                speed -= getRandom(1, 5);
                speed = (speed < 0) ? 0 : speed;
                break;
            case 3:
                // Change direction
                printf("\nEnter new direction (in degrees): ");
                scanf("%d", &direction);
                break;
            case 4:
                // Change gear
                printf("\nEnter new gear: ");
                scanf("%d", &gear);
                break;
            case 5:
                // Exit control panel
                printf("\nExiting control panel...\n\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        // Distance traveled calculation
        int time = getRandom(1, 10);
        distance += speed * time;

        printf("\nTime elapsed: %d secs\n", time);
        printf("Distance traveled: %d ft\n", distance);
    }

    return 0;
}

// Function definition for generating random numbers
int getRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}