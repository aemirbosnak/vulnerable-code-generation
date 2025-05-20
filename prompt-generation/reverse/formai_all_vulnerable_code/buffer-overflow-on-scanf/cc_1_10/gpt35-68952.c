//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("Welcome to the Remote Control Vehicle Simulation\n\n");

    // Initialize variables
    int speed = 0;
    int direction = 0;
    int x = 0, y = 0;
    char command;

    // Seed the random number generator
    srand(time(NULL));

    // Main loop
    while (1) {

        // Prompt the user for a command
        printf("Enter a command (w = forward, s = backward, a = left, d = right, q = quit): ");
        scanf("%c", &command);
        fflush(stdin);

        // Process the command
        switch (command) {
            case 'w':
                speed = rand() % 10 + 1;
                direction = rand() % 360;
                x += speed * cos(direction);
                y += speed * sin(direction);
                printf("Moving forward at speed %d in direction %d degrees\n", speed, direction);
                printf("Position: x = %d, y = %d\n\n", x, y);
                break;
            case 's':
                speed = rand() % 10 + 1;
                direction = rand() % 360;
                x -= speed * cos(direction);
                y -= speed * sin(direction);
                printf("Moving backward at speed %d in direction %d degrees\n", speed, direction);
                printf("Position: x = %d, y = %d\n\n", x, y);
                break;
            case 'a':
                direction -= 10;
                printf("Turning left\n");
                printf("Direction: %d degrees\n\n", direction);
                break;
            case 'd':
                direction += 10;
                printf("Turning right\n");
                printf("Direction: %d degrees\n\n", direction);
                break;
            case 'q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n\n");
                break;
        }
    }

    return 0;
}