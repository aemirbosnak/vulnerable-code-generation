//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, speed, direction;

    printf("Welcome to the Ultimate RC Vehicle Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");
    printf("5. Stop\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            speed = 5;
            direction = 1;
            break;
        case 2:
            speed = 5;
            direction = -1;
            break;
        case 3:
            speed = 3;
            direction = -1;
            break;
        case 4:
            speed = 3;
            direction = 1;
            break;
        case 5:
            speed = 0;
            direction = 0;
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    // Simulate vehicle movement
    for (int i = 0; i < speed; i++)
    {
        printf("The vehicle is moving %d %s at a speed of %d.\n", direction, "straight", speed);
    }

    // Stop the vehicle
    printf("The vehicle has stopped.\n");

    return 0;
}