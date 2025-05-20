//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WHEEL_DISTANCE 0.15
#define WHEEL_RADIUS 0.05
#define BODY_WIDTH 0.3
#define BODY_LENGTH 0.5
#define TURN_SPEED 0.2

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point position;
    double heading;
    double speed;
    int direction;
} Robot;

void init_robot(Robot* robot) {
    robot->position.x = 0;
    robot->position.y = 0;
    robot->heading = 0;
    robot->speed = 0;
    robot->direction = STOP;
}

void move_robot(Robot* robot) {
    double delta_heading = robot->direction * TURN_SPEED;
    robot->heading += delta_heading;
    robot->position.x += cos(robot->heading) * robot->speed;
    robot->position.y += sin(robot->heading) * robot->speed;
}

void turn_robot(Robot* robot, int direction) {
    robot->direction = direction;
}

void set_speed(Robot* robot, double speed) {
    robot->speed = speed;
}

int main() {
    Robot robot;
    init_robot(&robot);

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case FORWARD:
                set_speed(&robot, 0.2);
                turn_robot(&robot, FORWARD);
                break;
            case BACKWARD:
                set_speed(&robot, -0.2);
                turn_robot(&robot, BACKWARD);
                break;
            case LEFT:
                set_speed(&robot, 0.1);
                turn_robot(&robot, LEFT);
                break;
            case RIGHT:
                set_speed(&robot, 0.1);
                turn_robot(&robot, RIGHT);
                break;
            case STOP:
                set_speed(&robot, 0);
                turn_robot(&robot, STOP);
                break;
            default:
                printf("Invalid choice\n");
        }

        move_robot(&robot);

        printf("Current position: (%lf, %lf)\n", robot.position.x, robot.position.y);
        printf("Current heading: %lf\n", robot.heading);
    }

    return 0;
}