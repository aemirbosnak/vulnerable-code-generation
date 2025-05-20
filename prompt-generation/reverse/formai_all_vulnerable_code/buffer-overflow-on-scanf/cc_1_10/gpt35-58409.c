//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>

int main()
{
    // Welcome message
    printf("Welcome to the C Drone Remote Control!\n");

    // Initialize variables
    int altitude = 0;
    int speed = 0;
    int direction = 0;
    char input;

    // Main loop
    while (1) {
        // Print current drone status
        printf("Current altitude: %d meters\n", altitude);
        printf("Current speed: %d km/h\n", speed);
        printf("Current direction: %d degrees\n", direction);

        // Get user input
        printf("Enter a command (u/d/f/b/l/r): ");
        scanf(" %c", &input);

        // Handle user input
        switch (input) {
            case 'u':
                altitude += 10;
                printf("Ascending to %d meters.\n", altitude);
                break;
            case 'd':
                if (altitude >= 10) {
                    altitude -= 10;
                    printf("Descending to %d meters.\n", altitude);
                } else {
                    printf("Cannot descend below ground level!\n");
                }
                break;
            case 'f':
                speed += 10;
                printf("Increasing speed to %d km/h.\n", speed);
                break;
            case 'b':
                if (speed >= 10) {
                    speed -= 10;
                    printf("Decreasing speed to %d km/h.\n", speed);
                } else {
                    printf("Cannot go slower than 0 km/h!\n");
                }
                break;
            case 'l':
                direction -= 10;
                printf("Turning left to %d degrees.\n", direction);
                break;
            case 'r':
                direction += 10;
                printf("Turning right to %d degrees.\n", direction);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}