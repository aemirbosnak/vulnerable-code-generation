//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Point;

void move(double dx, double dy, Point* p) {
    double r = sqrt(p->x*p->x + p->y*p->y);
    double new_x = p->x + dx*cos(p->theta) - dy*sin(p->theta);
    double new_y = p->y + dx*sin(p->theta) + dy*cos(p->theta);
    p->x = new_x;
    p->y = new_y;
    p->theta = atan2(new_y - p->y, new_x - p->x);
}

void turn(double dtheta, Point* p) {
    p->theta += dtheta;
}

int main() {
    Point robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                double distance;
                printf("Enter the distance to move forward (in meters): ");
                scanf("%lf", &distance);
                move(distance, 0, &robot);
                printf("Robot moved %lf meters forward.\n", distance);
                break;
            }
            case 2: {
                double angle;
                printf("Enter the angle to turn left (in degrees): ");
                scanf("%lf", &angle);
                turn(angle, &robot);
                printf("Robot turned %lf degrees left.\n", angle);
                break;
            }
            case 3: {
                double angle;
                printf("Enter the angle to turn right (in degrees): ");
                scanf("%lf", &angle);
                turn(angle, &robot);
                printf("Robot turned %lf degrees right.\n", angle);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(choice!= 4);

    return 0;
}