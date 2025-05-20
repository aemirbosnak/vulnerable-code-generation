//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 100
#define MAX_TURN 100

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
} Robot;

void init_robot(Robot *r, double x, double y, double theta) {
    r->x = x;
    r->y = y;
    r->vx = 0;
    r->vy = 0;
    r->ax = 0;
    r->ay = 0;
}

void move_robot(Robot *r, double dt) {
    r->vx += r->ax * dt;
    r->vy += r->ay * dt;
    r->x += r->vx * dt;
    r->y += r->vy * dt;
}

void turn_left(Robot *r, double dt) {
    r->ax = -MAX_TURN;
    r->ay = 0;
}

void turn_right(Robot *r, double dt) {
    r->ax = MAX_TURN;
    r->ay = 0;
}

void move_forward(Robot *r, double dt) {
    r->vx = MAX_SPEED;
    r->ax = 0;
    r->ay = 0;
}

void stop(Robot *r) {
    r->vx = 0;
    r->ax = 0;
    r->ay = 0;
}

void main() {
    Robot r;
    init_robot(&r, 0, 0, 0);
    double dt = 0.1;

    while (1) {
        move_robot(&r, dt);
        printf("Current position: (%lf, %lf)\n", r.x, r.y);

        if (r.x > 10 || r.y > 10 || r.x < -10 || r.y < -10) {
            printf("Robot out of bounds!\n");
            break;
        }

        char command;
        scanf("%c", &command);

        switch (command) {
            case 'w':
                move_forward(&r, dt);
                break;
            case's':
                stop(&r);
                break;
            case 'a':
                turn_left(&r, dt);
                break;
            case 'd':
                turn_right(&r, dt);
                break;
            default:
                printf("Invalid command!\n");
        }
    }
}