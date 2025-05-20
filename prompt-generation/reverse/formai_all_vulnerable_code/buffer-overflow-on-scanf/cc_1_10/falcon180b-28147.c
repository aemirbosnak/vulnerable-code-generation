//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct {
    double x, y, theta;
} Vector;

void move(Vector* robot, double distance, double turn) {
    double turn_distance = distance * turn / 180.0 * PI;
    robot->x += cos(robot->theta) * distance + sin(robot->theta) * turn_distance;
    robot->y += sin(robot->theta) * distance - cos(robot->theta) * turn_distance;
    robot->theta += turn;
}

void turn(Vector* robot, double turn) {
    robot->theta += turn;
}

int main() {
    Vector robot = {0, 0, 0};
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter distance to move: ");
                double distance = 0;
                scanf("%lf", &distance);
                move(&robot, distance, 0);
                break;
            case 2:
                printf("Enter angle to turn: ");
                double angle = 0;
                scanf("%lf", &angle);
                turn(&robot, angle);
                break;
            case 3:
                printf("Enter angle to turn: ");
                double angle2 = 0;
                scanf("%lf", &angle2);
                turn(&robot, -angle2);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Current position: (%.2lf, %.2lf, %.2lf)\n", robot.x, robot.y, robot.theta);

    } while(choice!= 4);

    return 0;
}