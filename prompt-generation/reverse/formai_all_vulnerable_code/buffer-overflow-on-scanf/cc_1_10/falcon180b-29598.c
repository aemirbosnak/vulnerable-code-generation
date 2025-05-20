//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Robot;

void robot_init(Robot* r) {
    r->x = 0;
    r->y = 0;
    r->theta = 0;
}

void robot_move(Robot* r, double v, double w) {
    double dt = 0.01;
    double dx = v * cos(r->theta) * dt;
    double dy = v * sin(r->theta) * dt;
    double dtheta = w * dt;
    r->x += dx;
    r->y += dy;
    r->theta += dtheta;
}

void robot_turn(Robot* r, double w) {
    r->theta += w;
}

void robot_print(Robot* r) {
    printf("Robot: (%f, %f, %f)\n", r->x, r->y, r->theta);
}

int main() {
    Robot r;
    robot_init(&r);

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Print robot position\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter speed (m/s): ");
            double v = 0;
            scanf("%lf", &v);
            printf("Enter angular speed (rad/s): ");
            double w = 0;
            scanf("%lf", &w);
            robot_move(&r, v, w);
            break;
        case 2:
            printf("Enter angular speed (rad/s): ");
            double w1 = 0;
            scanf("%lf", &w1);
            robot_turn(&r, w1);
            break;
        case 3:
            printf("Enter angular speed (rad/s): ");
            double w2 = 0;
            scanf("%lf", &w2);
            robot_turn(&r, w2);
            break;
        case 4:
            robot_print(&r);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}