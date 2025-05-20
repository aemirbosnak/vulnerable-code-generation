//FormAI DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>

int main() {
    int x = 0, y = 0; // Initial coordinates of robot
    char direction = 'N'; // Initial direction of robot is North
    printf("Robot Movement Control\n-----------------------\n");
    printf("Enter commands (F-forward, L-left, R-right, Q-quit): \n");
    while (1) {
        char command;
        scanf("%c", &command);
        if (command == 'Q') { // Stop command
            printf("Stopping robot...\n");
            break;
        } else if (command == 'F') { // Forward command
            if (direction == 'N') { // Move North
                y++;
            } else if (direction == 'E') { // Move East
                x++;
            } else if (direction == 'S') { // Move South
                y--;
            } else if (direction == 'W') { // Move West
                x--;
            }
            printf("Moved forward. Current position: (%d,%d)\n", x, y);
        } else if (command == 'L') { // Left command
            if (direction == 'N') { // Turn West
                direction = 'W';
            } else if (direction == 'E') { // Turn North
                direction = 'N';
            } else if (direction == 'S') { // Turn East
                direction = 'E';
            } else if (direction == 'W') { // Turn South
                direction = 'S';
            }
            printf("Turned left. New direction: %c\n", direction);
        } else if (command == 'R') { // Right command
            if (direction == 'N') { // Turn East
                direction = 'E';
            } else if (direction == 'E') { // Turn South
                direction = 'S';
            } else if (direction == 'S') { // Turn West
                direction = 'W';
            } else if (direction == 'W') { // Turn North
                direction = 'N';
            }
            printf("Turned right. New direction: %c\n", direction);
        } else {
            printf("Invalid command: %c\n", command);
        }
    }
    return 0;
}