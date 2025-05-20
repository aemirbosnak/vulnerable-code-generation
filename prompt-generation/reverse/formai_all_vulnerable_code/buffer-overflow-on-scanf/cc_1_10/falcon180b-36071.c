//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define DEG_TO_RAD (PI/180.0)

typedef struct {
    double x;
    double y;
    double theta;
} Vector;

void move(Vector* robot, double v, double w) {
    robot->x += v*cos(robot->theta)*sin(w*DEG_TO_RAD);
    robot->y += v*sin(robot->theta)*sin(w*DEG_TO_RAD);
    robot->theta += v*cos(w*DEG_TO_RAD);
}

void turn(Vector* robot, double v, double w) {
    robot->theta += w*DEG_TO_RAD;
}

int main() {
    srand(time(NULL));
    Vector robot = {0, 0, 0};
    double speed = 1.0;
    double turnSpeed = 1.0;
    int choice;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Move backward\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move(&robot, speed, 0);
                break;
            case 2:
                turn(&robot, 0, turnSpeed);
                break;
            case 3:
                turn(&robot, 0, -turnSpeed);
                break;
            case 4:
                move(&robot, -speed, 0);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("Current position: (%lf, %lf)\n", robot.x, robot.y);
        printf("Current heading: %lf degrees\n", robot.theta*180/PI);
    }

    return 0;
}