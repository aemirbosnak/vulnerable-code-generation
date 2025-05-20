//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaring variables
    int altitude = 0;
    int speed = 0;
    char direction = 'N';
    char action;

    // Displaying welcome message and instructions
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("To control the drone, use the following keys:\n");
    printf("W - increase altitude\n");
    printf("S - decrease altitude\n");
    printf("A - turn left\n");
    printf("D - turn right\n");
    printf("N - do nothing\n");

    // Reading user inputs and controlling drone
    do {
        printf("Enter your action: ");
        scanf(" %c", &action);

        switch (action) {
            case 'W':
                ++altitude;
                speed += 5;
                printf("Increasing altitude...\n");
                break;
            case 'S':
                --altitude;
                speed -= 5;
                printf("Decreasing altitude...\n");
                break;
            case 'A':
                direction = (direction == 'N') ? 'W' :
                            (direction == 'W') ? 'S' :
                            (direction == 'S') ? 'E' : 'N';
                printf("Turning left...\n");
                break;
            case 'D':
                direction = (direction == 'N') ? 'E' :
                            (direction == 'E') ? 'S' :
                            (direction == 'S') ? 'W' : 'N';
                printf("Turning right...\n");
                break;
            case 'N':
                printf("Nothing happened...\n");
                break;
            default:
                printf("Invalid input: %c\n", action);
                break;
        }

        // Displaying current status of drone
        printf("Altitude: %d\n", altitude);
        printf("Speed: %d\n", speed);
        printf("Direction: %c\n", direction);
    } while (action != 'Q');

    printf("Exiting program... Thank you for using C Drone Remote Control!\n");

    return 0;
}