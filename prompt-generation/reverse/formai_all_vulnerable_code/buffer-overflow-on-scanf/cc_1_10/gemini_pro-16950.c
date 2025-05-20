//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MAX_ANGLE 90
#define DT 0.1

typedef struct {
    double x, y;
} vec2d;

typedef struct {
    vec2d pos;
    double speed;
    double angle;
} car;

void init_car(car *c) {
    c->pos.x = 0;
    c->pos.y = 0;
    c->speed = 0;
    c->angle = 0;
}

void update_car(car *c) {
    c->pos.x += c->speed * DT * cos(c->angle);
    c->pos.y += c->speed * DT * sin(c->angle);
}

void set_speed(car *c, double speed) {
    c->speed = speed;
    if (c->speed > MAX_SPEED) c->speed = MAX_SPEED;
    if (c->speed < 0) c->speed = 0;
}

void set_angle(car *c, double angle) {
    c->angle = angle;
    if (c->angle > MAX_ANGLE) c->angle = MAX_ANGLE;
    if (c->angle < -MAX_ANGLE) c->angle = -MAX_ANGLE;
}

void print_car(car *c) {
    printf("Car position: (%f, %f)\n", c->pos.x, c->pos.y);
    printf("Car speed: %f\n", c->speed);
    printf("Car angle: %f\n", c->angle);
}

int main() {
    car c;
    init_car(&c);

    while (1) {
        char command;
        double value;
        scanf(" %c %lf", &command, &value);

        switch (command) {
            case 's':
                set_speed(&c, value);
                break;
            case 'a':
                set_angle(&c, value);
                break;
            case 'p':
                print_car(&c);
                break;
            case 'e':
                exit(0);
        }

        update_car(&c);
    }

    return 0;
}