//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WHEEL_RADIUS 0.05
#define BODY_WIDTH 0.2
#define BODY_LENGTH 0.3
#define MAX_SPEED 0.2
#define MAX_TURN_SPEED 0.6

typedef struct {
    double x, y, theta;
} robot;

robot init_robot(double x, double y, double theta) {
    robot r;
    r.x = x;
    r.y = y;
    r.theta = theta;
    return r;
}

void move_robot(robot *r, double v, double w) {
    double dx = v * cos(r->theta);
    double dy = v * sin(r->theta);
    r->x += dx;
    r->y += dy;
    r->theta += w;
    if (r->theta > 2 * PI) {
        r->theta -= 2 * PI;
    } else if (r->theta < 0) {
        r->theta += 2 * PI;
    }
}

void turn_robot(robot *r, double w) {
    r->theta += w;
    if (r->theta > 2 * PI) {
        r->theta -= 2 * PI;
    } else if (r->theta < 0) {
        r->theta += 2 * PI;
    }
}

int main() {
    robot r = init_robot(0, 0, 0);
    double v = 0, w = 0;
    while (1) {
        printf("Enter v (speed): ");
        scanf("%lf", &v);
        printf("Enter w (turn speed): ");
        scanf("%lf", &w);
        if (v > MAX_SPEED) {
            v = MAX_SPEED;
        }
        if (w > MAX_TURN_SPEED) {
            w = MAX_TURN_SPEED;
        }
        move_robot(&r, v, w);
        printf("Current position: (%lf, %lf)\n", r.x, r.y);
        printf("Current orientation: %lf\n", r.theta);
    }
    return 0;
}