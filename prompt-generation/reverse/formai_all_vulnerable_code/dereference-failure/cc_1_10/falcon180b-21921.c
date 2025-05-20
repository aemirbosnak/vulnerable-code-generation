//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define DEG_TO_RAD (PI/180.0)

typedef struct {
    double x;
    double y;
    double theta;
} robot_t;

robot_t* robot_create(double x, double y, double theta) {
    robot_t* r = (robot_t*) malloc(sizeof(robot_t));
    r->x = x;
    r->y = y;
    r->theta = theta;
    return r;
}

void robot_destroy(robot_t* r) {
    free(r);
}

void robot_move(robot_t* r, double v, double w) {
    double dt = 0.1;
    double dx = v*cos(r->theta)*dt;
    double dy = v*sin(r->theta)*dt;
    double dtheta = w*dt;

    r->x += dx;
    r->y += dy;
    r->theta += dtheta;
}

void robot_turn(robot_t* r, double w) {
    r->theta += w*DEG_TO_RAD;
}

double robot_distance(robot_t* r1, robot_t* r2) {
    double dx = r2->x - r1->x;
    double dy = r2->y - r1->y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    robot_t* r1 = robot_create(0, 0, 0);
    robot_t* r2 = robot_create(10, 0, 0);

    int i;
    for(i = 0; i < 100; i++) {
        robot_move(r1, 1, 0);
        robot_move(r2, 1, 0);

        if(robot_distance(r1, r2) < 1) {
            printf("Collision detected!\n");
            break;
        }
    }

    robot_destroy(r1);
    robot_destroy(r2);

    return 0;
}