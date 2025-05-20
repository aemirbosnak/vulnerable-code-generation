//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the maximum speed of the robot
#define MAX_SPEED 10

// Define the direction of the robot
#define FORWARD 1
#define BACKWARD 2

// Define the maximum range of the robot
#define MAX_RANGE 100

// Define the direction of the robot
int direction = FORWARD;

int main() {
    // Initialize the robot's position
    int x = 0;
    int y = 0;

    // Initialize the speed of the robot
    int speed = MAX_SPEED;

    // Initialize the range of the robot
    int range = MAX_RANGE;

    // Loop until the user wants to exit
    while (1) {
        // Prompt the user for input
        printf("Enter command: ");
        char command[100];
        scanf("%s", command);

        // Handle different commands
        if (strcmp(command, "move") == 0) {
            // Prompt the user for the direction
            printf("Enter direction: ");
            char direction_str[100];
            scanf("%s", direction_str);

            // Handle different directions
            if (strcmp(direction_str, "forward") == 0) {
                direction = FORWARD;
            } else if (strcmp(direction_str, "backward") == 0) {
                direction = BACKWARD;
            } else {
                printf("Invalid direction.\n");
            }
        } else if (strcmp(command, "speed") == 0) {
            // Prompt the user for the speed
            printf("Enter speed: ");
            char speed_str[100];
            scanf("%s", speed_str);

            // Handle different speeds
            if (strcmp(speed_str, "slow") == 0) {
                speed = 5;
            } else if (strcmp(speed_str, "medium") == 0) {
                speed = 7;
            } else if (strcmp(speed_str, "fast") == 0) {
                speed = MAX_SPEED;
            } else {
                printf("Invalid speed.\n");
            }
        } else if (strcmp(command, "range") == 0) {
            // Prompt the user for the range
            printf("Enter range: ");
            char range_str[100];
            scanf("%s", range_str);

            // Handle different ranges
            if (strcmp(range_str, "short") == 0) {
                range = 50;
            } else if (strcmp(range_str, "medium") == 0) {
                range = 75;
            } else if (strcmp(range_str, "long") == 0) {
                range = MAX_RANGE;
            } else {
                printf("Invalid range.\n");
            }
        } else {
            printf("Invalid command.\n");
        }

        // Calculate the new position of the robot
        if (direction == FORWARD) {
            if (x + speed > range) {
                x = range - 1;
            } else {
                x += speed;
            }
        } else if (direction == BACKWARD) {
            if (x - speed < 0) {
                x = 0;
            } else {
                x -= speed;
            }
        }

        // Print the new position of the robot
        printf("Position: (%d, %d)\n", x, y);

        // Update the direction of the robot
        if (x == range) {
            direction = BACKWARD;
        } else if (x == 0) {
            direction = FORWARD;
        }

        // Delay for 100 milliseconds
        usleep(100000);
    }

    return 0;
}