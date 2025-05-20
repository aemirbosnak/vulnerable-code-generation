//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

void move(Vector* v, double distance, double direction) {
    Vector temp;
    temp.x = v->x + distance * cos(direction);
    temp.y = v->y + distance * sin(direction);
    v->theta += direction;
    v->x = temp.x;
    v->y = temp.y;
}

void turn(Vector* v, double angle) {
    v->theta += angle;
}

int main() {
    srand(time(NULL));

    Vector robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    int choice;
    double distance, angle;

    do {
        printf("Enter 1 to move forward, 2 to turn left, 3 to turn right, 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter distance: ");
            scanf("%lf", &distance);
            move(&robot, distance, 0);
        } else if (choice == 2) {
            printf("Enter angle: ");
            scanf("%lf", &angle);
            turn(&robot, angle);
        } else if (choice == 3) {
            printf("Enter angle: ");
            scanf("%lf", &angle);
            turn(&robot, -angle);
        }

        printf("Current position: (%lf, %lf)\n", robot.x, robot.y);
        printf("Current heading: %lf\n", robot.theta);
    } while (choice!= 0);

    return 0;
}