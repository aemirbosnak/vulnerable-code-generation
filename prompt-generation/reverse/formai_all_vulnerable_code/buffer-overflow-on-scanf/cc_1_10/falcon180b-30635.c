//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} robot_position;

void move(robot_position* robot, double distance, double angle) {
    double dx = distance * cos(angle - robot->theta);
    double dy = distance * sin(angle - robot->theta);
    robot->x += dx;
    robot->y += dy;
    robot->theta = angle;
}

void turn(robot_position* robot, double angle) {
    robot->theta += angle;
}

void print_position(robot_position* robot) {
    printf("X: %.2f, Y: %.2f, Theta: %.2f\n", robot->x, robot->y, robot->theta * 180 / PI);
}

int main() {
    robot_position robot = {0, 0, 0};
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Move\n");
        printf("2. Turn\n");
        printf("3. Print position\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter distance and angle (in degrees): ");
            double distance, angle;
            scanf("%lf %lf", &distance, &angle);
            move(&robot, distance, angle * PI / 180);
            break;
        case 2:
            printf("Enter angle (in degrees): ");
            double turn_angle;
            scanf("%lf", &turn_angle);
            turn(&robot, turn_angle * PI / 180);
            break;
        case 3:
            print_position(&robot);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}