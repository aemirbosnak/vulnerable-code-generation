//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

typedef struct {
    double v, w;
} Twist;

Vector robot_pos;
Twist robot_vel;

double move(double v, double w) {
    double dt = 0.1;
    robot_vel.v = v * cos(robot_pos.theta) + w * sin(robot_pos.theta);
    robot_vel.w = -v * sin(robot_pos.theta) + w * cos(robot_pos.theta);

    robot_pos.x += dt * robot_vel.v * cos(robot_pos.theta) - dt * robot_vel.w * sin(robot_pos.theta);
    robot_pos.y += dt * robot_vel.v * sin(robot_pos.theta) + dt * robot_vel.w * cos(robot_pos.theta);
    robot_pos.theta += dt * robot_vel.w;

    return sqrt(pow(robot_pos.x, 2) + pow(robot_pos.y, 2));
}

int main() {
    srand(time(NULL));

    robot_pos.x = rand() % 1000;
    robot_pos.y = rand() % 1000;
    robot_pos.theta = rand() % 360;

    int choice;
    double v, w;

    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter speed: ");
                scanf("%lf", &v);
                w = 0;
                break;
            case 2:
                printf("Enter speed: ");
                scanf("%lf", &v);
                w = -1;
                break;
            case 3:
                printf("Enter speed: ");
                scanf("%lf", &v);
                w = 1;
                break;
            case 4:
                v = 0;
                w = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        move(v, w);
        printf("Distance traveled: %lf\n", move(v, w));
    } while(1);

    return 0;
}