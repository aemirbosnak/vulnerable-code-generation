//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Robot;

void move(Robot *robot, double distance) {
    robot->x += distance * cos(robot->theta);
    robot->y += distance * sin(robot->theta);
}

void turn(Robot *robot, double angle) {
    robot->theta += angle;
}

void main() {
    Robot robot = {0, 0, 0};
    int choice, distance, angle;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the distance to move forward:\n");
                scanf("%d", &distance);
                move(&robot, distance);
                break;
            case 2:
                printf("Enter the angle to turn left:\n");
                scanf("%d", &angle);
                turn(&robot, -angle);
                break;
            case 3:
                printf("Enter the angle to turn right:\n");
                scanf("%d", &angle);
                turn(&robot, angle);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("Current position: (%lf, %lf, %lf)\n", robot.x, robot.y, robot.theta);
    }
}