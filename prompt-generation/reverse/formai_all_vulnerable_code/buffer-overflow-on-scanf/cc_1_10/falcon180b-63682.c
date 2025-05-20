//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} robot;

robot createRobot(double x, double y, double theta) {
    robot r;
    r.x = x;
    r.y = y;
    r.theta = theta;
    return r;
}

void moveRobot(robot *r, double v, double w) {
    r->x += v * cos(r->theta);
    r->y += v * sin(r->theta);
    r->theta += w;
}

void senseRobot(robot *r) {
    printf("Robot at (%lf, %lf) with orientation %lf\n", r->x, r->y, r->theta);
}

int main() {
    srand(time(NULL));
    robot r = createRobot(0, 0, rand() % 360);
    int choice;
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Sense\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter distance to move: ");
                double v = rand() % 100; // Random velocity between 0 and 100
                moveRobot(&r, v, 0);
                break;
            case 2:
                printf("Enter angle to turn: ");
                double w = rand() % 360; // Random angle between 0 and 360
                moveRobot(&r, 0, w);
                break;
            case 3:
                printf("Enter angle to turn: ");
                w = rand() % 360; // Random angle between 0 and 360
                moveRobot(&r, 0, -w);
                break;
            case 4:
                senseRobot(&r);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}