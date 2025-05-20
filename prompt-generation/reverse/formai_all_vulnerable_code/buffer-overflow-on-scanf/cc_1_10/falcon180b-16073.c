//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, angle;
} point;

void move(point *p, double distance, double angle) {
    double dx, dy, da;
    dx = distance * cos(angle - p->angle);
    dy = distance * sin(angle - p->angle);
    p->x += dx;
    p->y += dy;
    p->angle = angle;
}

void turn(point *p, double angle) {
    p->angle += angle;
}

int main() {
    point robot;
    robot.x = 0;
    robot.y = 0;
    robot.angle = 0;
    int choice;
    double distance, angle;

    do {
        printf("Enter your choice:\n");
        printf("1. Move\n");
        printf("2. Turn\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter distance and angle (in degrees): ");
                scanf("%lf %lf", &distance, &angle);
                move(&robot, distance, angle * PI / 180);
                printf("Robot moved to (%lf, %lf) with angle %lf\n", robot.x, robot.y, robot.angle);
                break;
            case 2:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &angle);
                turn(&robot, angle * PI / 180);
                printf("Robot turned to angle %lf\n", robot.angle);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}