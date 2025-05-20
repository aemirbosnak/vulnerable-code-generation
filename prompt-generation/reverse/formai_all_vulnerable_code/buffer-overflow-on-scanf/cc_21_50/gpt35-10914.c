//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main() {
    int xPos = 0;
    int yPos = 0;
    int direction = FORWARD;

    bool running = true;

    while (running) {
        printf("Current position: (%d,%d)\n", xPos, yPos);
        printf("Direction: ");

        if (direction == FORWARD) {
            printf("Forward\n");
        } else if (direction == BACKWARD) {
            printf("Backward\n");
        } else if (direction == LEFT) {
            printf("Left\n");
        } else if (direction == RIGHT) {
            printf("Right\n");
        }

        printf("Enter command (f/b/l/r/x): ");
        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'f':
                if (direction == FORWARD) {
                    yPos++;
                } else if (direction == BACKWARD) {
                    yPos--;
                } else if (direction == LEFT) {
                    xPos--;
                } else if (direction == RIGHT) {
                    xPos++;
                }
                break;
            case 'b':
                if (direction == FORWARD) {
                    yPos--;
                } else if (direction == BACKWARD) {
                    yPos++;
                } else if (direction == LEFT) {
                    xPos++;
                } else if (direction == RIGHT) {
                    xPos--;
                }
                break;
            case 'l':
                if (direction == FORWARD) {
                    direction = LEFT;
                } else if (direction == BACKWARD) {
                    direction = RIGHT;
                } else if (direction == LEFT) {
                    direction = BACKWARD;
                } else if (direction == RIGHT) {
                    direction = FORWARD;
                }
                break;
            case 'r':
                if (direction == FORWARD) {
                    direction = RIGHT;
                } else if (direction == BACKWARD) {
                    direction = LEFT;
                } else if (direction == LEFT) {
                    direction = FORWARD;
                } else if (direction == RIGHT) {
                    direction = BACKWARD;
                }
                break;
            case 'x':
                running = false;
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}