//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int main() {
    // Create a robot
    struct robot {
        int x;
        int y;
        int direction;
    } robot;

    // Initialize the robot
    robot.x = 0;
    robot.y = 0;
    robot.direction = NORTH;

    // Get the user's input
    char input[10];
    printf("Enter a command (N, E, S, W, L, R, Q): ");
    scanf("%s", input);

    // Process the user's input
    while (strcmp(input, "Q") != 0) {
        switch (input[0]) {
            case 'N':
                robot.y++;
                break;
            case 'E':
                robot.x++;
                break;
            case 'S':
                robot.y--;
                break;
            case 'W':
                robot.x--;
                break;
            case 'L':
                robot.direction = (robot.direction + 3) % 4;
                break;
            case 'R':
                robot.direction = (robot.direction + 1) % 4;
                break;
            default:
                printf("Invalid command\n");
        }

        // Print the robot's position
        printf("Robot is at (%d, %d)\n", robot.x, robot.y);

        // Get the user's input
        printf("Enter a command (N, E, S, W, L, R, Q): ");
        scanf("%s", input);
    }

    return 0;
}