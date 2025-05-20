//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>

int main()
{
    // Initialize variables
    char input;
    int battery = 100;
    int altitude = 0;
    int direction = 0; // 0 = North, 1 = East, 2 = South, 3 = West

    // Loop until user exits
    while (1)
    {
        // Print menu options
        printf("Drone Remote Control\n");
        printf("--------------------\n");
        printf("Battery level: %d%%\n", battery);
        printf("Altitude: %d meters\n", altitude);
        printf("Direction: ");
        switch (direction)
        {
            case 0:
                printf("North\n");
                break;
            case 1:
                printf("East\n");
                break;
            case 2:
                printf("South\n");
                break;
            case 3:
                printf("West\n");
                break;
        }
        printf("Enter command (f=forward, b=backward, l=left, r=right, u=up, d=down, q=quit): ");

        // Read user input
        scanf(" %c", &input);

        // Handle input commands
        switch (input)
        {
            case 'f':
                printf("Forward\n");
                break;
            case 'b':
                printf("Backward\n");
                break;
            case 'l':
                printf("Left\n");
                break;
            case 'r':
                printf("Right\n");
                break;
            case 'u':
                printf("Up\n");
                altitude++;
                break;
            case 'd':
                printf("Down\n");
                altitude--;
                break;
            case 'q':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid command\n");
        }

        // Decrement battery level
        battery--;

        // Check if battery is empty and exit if true
        if (battery < 1)
        {
            printf("Battery empty, exiting...\n");
            return 0;
        }
    }
}