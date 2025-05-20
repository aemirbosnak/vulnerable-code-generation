//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Welcome message
    printf("Welcome to the C Drone Remote Control program!\n\n");

    // Initialize variables
    int up, down, left, right, speed, choice;

    // Prompt user for input
    printf("Please enter the speed of the drone (1-10): ");
    scanf("%d", &speed);

    // Validate input
    while (speed < 1 || speed > 10)
    {
        printf("Invalid input, please enter a speed between 1 and 10: ");
        scanf("%d", &speed);
    }

    // Prompt user for input
    printf("\nPlease choose a direction:\n");
    printf("\t1. Up\n");
    printf("\t2. Down\n");
    printf("\t3. Left\n");
    printf("\t4. Right\n");
    scanf("%d", &choice);

    // Validate input
    while (choice < 1 || choice > 4)
    {
        printf("Invalid input, please choose a direction between 1 and 4: ");
        scanf("%d", &choice);
    }

    // Set direction based on user input
    switch (choice)
    {
        case 1:
            up = speed;
            down = 0;
            left = 0;
            right = 0;
            printf("\nDrone is now moving up at speed %d.\n", speed);
            break;
        case 2:
            up = 0;
            down = speed;
            left = 0;
            right = 0;
            printf("\nDrone is now moving down at speed %d.\n", speed);
            break;
        case 3:
            up = 0;
            down = 0;
            left = speed;
            right = 0;
            printf("\nDrone is now moving left at speed %d.\n", speed);
            break;
        case 4:
            up = 0;
            down = 0;
            left = 0;
            right = speed;
            printf("\nDrone is now moving right at speed %d.\n", speed);
            break;
    }

    // Fly the drone for 10 seconds
    printf("\nFlying drone for 10 seconds...\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("Second %d...\n", i);
    }

    // Stop the drone
    printf("\nStopping drone...\n");
    up = 0;
    down = 0;
    left = 0;
    right = 0;

    // Exit message
    printf("\nThank you for using the C Drone Remote Control program!\n");

    return 0;
}