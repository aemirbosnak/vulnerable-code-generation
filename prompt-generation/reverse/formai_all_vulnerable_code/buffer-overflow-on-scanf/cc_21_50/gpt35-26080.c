//FormAI DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Robot Movement Control Program!\n");

    // define robot position and orientation variables
    int xPos = 0;
    int yPos = 0;
    char orientation = 'N';

    // define command variable
    char command;

    // Loop until user enters 'q' to quit
    while (command != 'q') {
        printf("\nEnter command [f]orward, [b]ackward, [l]eft, [r]ight, [q]uit: ");
        scanf("%c", &command);
        getchar(); // to clear buffer

        // Move the robot based on the command and current orientation
        switch (command) {
            case 'f':
                if (orientation == 'N') {
                    yPos++;
                } else if (orientation == 'E') {
                    xPos++;
                } else if (orientation == 'S') {
                    yPos--;
                } else if (orientation == 'W') {
                    xPos--;
                }
                break;
            case 'b':
                if (orientation == 'N') {
                    yPos--;
                } else if (orientation == 'E') {
                    xPos--;
                } else if (orientation == 'S') {
                    yPos++;
                } else if (orientation == 'W') {
                    xPos++;
                }
                break;
            case 'l':
                if (orientation == 'N') {
                    orientation = 'W';
                } else if (orientation == 'E') {
                    orientation = 'N';
                } else if (orientation == 'S') {
                    orientation = 'E';
                } else if (orientation == 'W') {
                    orientation = 'S';
                }
                break;
            case 'r':
                if (orientation == 'N') {
                    orientation = 'E';
                } else if (orientation == 'E') {
                    orientation = 'S';
                } else if (orientation == 'S') {
                    orientation = 'W';
                } else if (orientation == 'W') {
                    orientation = 'N';
                }
                break;
            case 'q':
                printf("Exiting C Robot Movement Control Program...\n");
                exit(0);
            default:
                printf("Invalid command, please try again.\n");
        }

        // Print robot's current position and orientation
        printf("Robot's current position: (%d,%d)\n", xPos, yPos);
        printf("Robot's current orientation: %c\n", orientation);
    }

    return 0;
}