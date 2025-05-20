//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define LEFT  0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

int main() {
    int speed = 0;
    int direction = FORWARD;
    char command;

    printf("Enter a command (l/r/f/b): ");
    while (scanf(" %c", &command) != EOF) {
        switch (command) {
            case 'l':
                direction = LEFT;
                break;
            case 'r':
                direction = RIGHT;
                break;
            case 'f':
                direction = FORWARD;
                break;
            case 'b':
                direction = BACKWARD;
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        printf("Command: %c\n", command);

        // Update the speed and direction of the vehicle
        switch (direction) {
            case LEFT:
                speed -= 1;
                break;
            case RIGHT:
                speed += 1;
                break;
            case FORWARD:
                speed += 2;
                break;
            case BACKWARD:
                speed -= 2;
                break;
        }

        // Print the current speed and direction of the vehicle
        printf("Speed: %d\n", speed);
        printf("Direction: %s\n", direction == LEFT ? "LEFT" : direction == RIGHT ? "RIGHT" : direction == FORWARD ? "FORWARD" : "BACKWARD");

        printf("Enter a command (l/r/f/b): ");
    }

    return 0;
}