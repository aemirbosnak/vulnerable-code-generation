//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100

int main() {
    // Create an array of commands
    char commands[MAX_COMMANDS][100];

    // Get the commands from the user
    printf("Enter the commands (max %d):\n", MAX_COMMANDS);
    for (int i = 0; i < MAX_COMMANDS; i++) {
        scanf("%s", commands[i]);
        if (strcmp(commands[i], "exit") == 0) {
            break;
        }
    }

    // Create a robot object
    struct Robot {
        int x;
        int y;
        int direction; // 0: north, 1: east, 2: south, 3: west
    } robot;

    // Initialize the robot's position and direction
    robot.x = 0;
    robot.y = 0;
    robot.direction = 0;

    // Execute the commands
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i], "move") == 0) {
            // Move the robot forward one unit in the current direction
            switch (robot.direction) {
                case 0:
                    robot.y++;
                    break;
                case 1:
                    robot.x++;
                    break;
                case 2:
                    robot.y--;
                    break;
                case 3:
                    robot.x--;
                    break;
            }
        } else if (strcmp(commands[i], "left") == 0) {
            // Turn the robot left 90 degrees
            robot.direction = (robot.direction + 3) % 4;
        } else if (strcmp(commands[i], "right") == 0) {
            // Turn the robot right 90 degrees
            robot.direction = (robot.direction + 1) % 4;
        } else if (strcmp(commands[i], "report") == 0) {
            // Report the robot's position and direction
            printf("Robot position: (%d, %d)\n", robot.x, robot.y);
            printf("Robot direction: ");
            switch (robot.direction) {
                case 0:
                    printf("north\n");
                    break;
                case 1:
                    printf("east\n");
                    break;
                case 2:
                    printf("south\n");
                    break;
                case 3:
                    printf("west\n");
                    break;
            }
        } else {
            // Invalid command
            printf("Invalid command: %s\n", commands[i]);
        }
    }

    return 0;
}