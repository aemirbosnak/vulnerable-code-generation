//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Constants for maximum speed and turn angle
    const int MAX_SPEED = 5;
    const int MAX_TURN_ANGLE = 45;

    // Create a robot
    struct Robot {
        int x, y;  // Coordinates of robot
        int speed;  // Speed of robot
        int angle;  // Angle of robot
    } robot;

    // Initialize the robot
    robot.x = 0;
    robot.y = 0;
    robot.speed = 0;
    robot.angle = 0;

    // Main loop
    while (1) {
        // Get user input
        printf("Enter a command (w, a, s, d, q): ");
        char command;
        scanf(" %c", &command);

        // Process the command
        switch (command) {
            case 'w':  // Move forward
                robot.speed += 1;
                if (robot.speed > MAX_SPEED) {
                    robot.speed = MAX_SPEED;
                }
                break;
            case 'a':  // Turn left
                robot.angle -= 1;
                if (robot.angle < -MAX_TURN_ANGLE) {
                    robot.angle = -MAX_TURN_ANGLE;
                }
                break;
            case 's':  // Move backward
                robot.speed -= 1;
                if (robot.speed < 0) {
                    robot.speed = 0;
                }
                break;
            case 'd':  // Turn right
                robot.angle += 1;
                if (robot.angle > MAX_TURN_ANGLE) {
                    robot.angle = MAX_TURN_ANGLE;
                }
                break;
            case 'q':  // Quit
                exit(0);
                break;
            default:
                printf("Invalid command\n");
        }

        // Update robot position
        robot.x += robot.speed * cos(robot.angle * M_PI / 180);
        robot.y += robot.speed * sin(robot.angle * M_PI / 180);

        // Display robot position
        printf("Robot position: (%d, %d)\n", robot.x, robot.y);
    }

    return 0;
}