//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265358979323846
#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'
#define STOP 'x'
#define ROTATE_CW 'r'
#define ROTATE_CCW 'l'

typedef struct {
    double x;
    double y;
    double angle; // in radians
} Robot;

void move_forward(Robot *robot, double distance) {
    robot->x += distance * cos(robot->angle);
    robot->y += distance * sin(robot->angle);
    printf("Moved Forward: New Position (%.2f, %.2f)\n", robot->x, robot->y);
}

void move_backward(Robot *robot, double distance) {
    robot->x -= distance * cos(robot->angle);
    robot->y -= distance * sin(robot->angle);
    printf("Moved Backward: New Position (%.2f, %.2f)\n", robot->x, robot->y);
}

void rotate_cw(Robot *robot, double degrees) {
    robot->angle -= degrees * (PI / 180.0);
    printf("Rotated CW: New Angle (%.2f radians)\n", robot->angle);
}

void rotate_ccw(Robot *robot, double degrees) {
    robot->angle += degrees * (PI / 180.0);
    printf("Rotated CCW: New Angle (%.2f radians)\n", robot->angle);
}

void stop_robot(Robot *robot) {
    printf("Robot stopped at position (%.2f, %.2f) with angle (%.2f radians)\n", robot->x, robot->y, robot->angle);
}

void perform_movement(Robot *robot) {
    char command;
    double distance, angle;

    while (1) {
        printf("Command (w/a/s/d/x/r/l for degrees): ");
        command = getchar();
        while (getchar() != '\n'); // clear the buffer
        
        switch (command) {
            case FORWARD:
                printf("Enter distance: ");
                scanf("%lf", &distance);
                while (getchar() != '\n'); // clear the buffer
                move_forward(robot, distance);
                break;

            case BACKWARD:
                printf("Enter distance: ");
                scanf("%lf", &distance);
                while (getchar() != '\n'); // clear the buffer
                move_backward(robot, distance);
                break;

            case LEFT:
                printf("Enter angle (degrees): ");
                scanf("%lf", &angle);
                while (getchar() != '\n'); // clear the buffer
                rotate_ccw(robot, angle);
                break;

            case RIGHT:
                printf("Enter angle (degrees): ");
                scanf("%lf", &angle);
                while (getchar() != '\n'); // clear the buffer
                rotate_cw(robot, angle);
                break;

            case STOP:
                stop_robot(robot);
                return; // Exit the movement loop

            case ROTATE_CW:
                printf("Enter angle to rotate clockwise (degrees): ");
                scanf("%lf", &angle);
                while (getchar() != '\n'); // clear the buffer
                rotate_cw(robot, angle);
                break;

            case ROTATE_CCW:
                printf("Enter angle to rotate counter-clockwise (degrees): ");
                scanf("%lf", &angle);
                while (getchar() != '\n'); // clear the buffer
                rotate_ccw(robot, angle);
                break;
                
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }
}

int main() {
    Robot myRobot = {0.0, 0.0, 0.0}; // Initialize the robot in a cosmic dance on the origin
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Let your robotic dreams take flight through the universe of commands!\n");
    perform_movement(&myRobot);
    
    return 0; // The end of this journey! But remember, every ending is a new beginning.
}