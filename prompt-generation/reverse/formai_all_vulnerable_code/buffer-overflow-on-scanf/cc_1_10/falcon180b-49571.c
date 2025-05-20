//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Robot;

void move(Robot* robot, double distance, double angle) {
    double dx = distance * cos(angle - robot->theta);
    double dy = distance * sin(angle - robot->theta);
    robot->x += dx;
    robot->y += dy;
    robot->theta = angle;
}

void turn(Robot* robot, double angle) {
    robot->theta += angle;
}

void draw(Robot robot) {
    printf("%.2f, %.2f\n", robot.x, robot.y);
}

int main() {
    Robot robot = {0, 0, 0};
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Move\n");
        printf("2. Turn\n");
        printf("3. Draw\n");
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
            draw(robot);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}