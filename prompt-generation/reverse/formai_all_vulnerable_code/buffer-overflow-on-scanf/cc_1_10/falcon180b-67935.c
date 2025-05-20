//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159
#define SPEED 5
#define TURN_SPEED 2
#define TURN_TIME 0.5
#define FORWARD_TIME 1.0
#define BACKWARD_TIME 1.0
#define STOP_TIME 1.0

typedef struct {
    double x;
    double y;
    double theta;
} robot_t;

void move_forward(robot_t *robot) {
    robot->x += cos(robot->theta) * SPEED;
    robot->y += sin(robot->theta) * SPEED;
}

void turn_left(robot_t *robot) {
    robot->theta -= TURN_SPEED;
}

void turn_right(robot_t *robot) {
    robot->theta += TURN_SPEED;
}

void move_backward(robot_t *robot) {
    robot->x -= cos(robot->theta) * SPEED;
    robot->y -= sin(robot->theta) * SPEED;
}

void stop(robot_t *robot) {
    robot->x = 0;
    robot->y = 0;
}

int main() {
    srand(time(NULL));
    robot_t robot;
    robot.x = rand() % 100;
    robot.y = rand() % 100;
    robot.theta = rand() % 360;

    while (1) {
        printf("Current position: x = %.2f, y = %.2f, theta = %.2f\n", robot.x, robot.y, robot.theta);
        printf("Enter command: f for forward, b for backward, l for left, r for right, s for stop\n");
        char command;
        scanf("%c", &command);

        switch (command) {
            case 'f':
                move_forward(&robot);
                printf("Moving forward...\n");
                break;
            case 'b':
                move_backward(&robot);
                printf("Moving backward...\n");
                break;
            case 'l':
                turn_left(&robot);
                printf("Turning left...\n");
                break;
            case 'r':
                turn_right(&robot);
                printf("Turning right...\n");
                break;
            case's':
                stop(&robot);
                printf("Stopping...\n");
                break;
            default:
                printf("Invalid command\n");
        }

        printf("Waiting for %.2f seconds...\n", rand() % 5 + 1);
        sleep(rand() % 5 + 1);
    }

    return 0;
}