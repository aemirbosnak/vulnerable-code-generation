//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define WHEEL_RADIUS 0.1
#define WHEEL_BASE 0.3
#define MAX_SPEED 5.0
#define MAX_TORQUE 100.0

struct vehicle {
    double x, y, theta;
    double v, omega;
};

void draw_vehicle(struct vehicle v) {
    double r = v.theta * WHEEL_RADIUS + v.x;
    double c = v.x + v.y * WHEEL_RADIUS;
    double a = v.theta - M_PI / 2;

    printf("%.2f %.2f l ", r, c);
    printf("%.2f %.2f l ", r + WHEEL_BASE * cos(a), c + WHEEL_BASE * sin(a));
    printf("%.2f %.2f l ", r + WHEEL_BASE * cos(a + M_PI), c + WHEEL_BASE * sin(a + M_PI));
    printf("z\n");
}

void update_vehicle(struct vehicle *v, double dt) {
    double F = MAX_TORQUE * v->omega;
    double R = WHEEL_RADIUS * v->omega;
    double alpha = F / R;

    v->v += v->omega * cos(v->theta) * dt;
    v->omega += alpha * dt;

    if (v->omega > MAX_SPEED) {
        v->omega = MAX_SPEED;
    } else if (v->omega < -MAX_SPEED) {
        v->omega = -MAX_SPEED;
    }

    v->theta += v->omega * dt;
}

int main() {
    struct vehicle v = {0, 0, 0, 0, 0};

    while (1) {
        system("clear");
        printf("Enter command (f/b/l/r/q): ");
        char command;
        scanf("%c", &command);

        switch (command) {
        case 'f':
            v.omega = MAX_SPEED;
            break;
        case 'b':
            v.omega = -MAX_SPEED;
            break;
        case 'l':
            v.omega = -v.omega;
            break;
        case 'r':
            v.omega = -v.omega;
            break;
        case 'q':
            exit(0);
        default:
            break;
        }

        update_vehicle(&v, 0.1);
        draw_vehicle(v);
    }

    return 0;
}