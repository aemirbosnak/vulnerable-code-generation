//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 100
#define MAX_TURN_RATE 0.1
#define SENSOR_RANGE 0.5

enum {
    FORWARD = 1,
    BACKWARD = 2,
    LEFT = 4,
    RIGHT = 8
};

struct vector {
    double x, y;
};

struct robot {
    double x, y, theta;
    int speed;
    int turn_rate;
    int direction;
};

void init_robot(struct robot *r) {
    r->x = 0;
    r->y = 0;
    r->theta = 0;
    r->speed = 0;
    r->turn_rate = 0;
    r->direction = FORWARD;
}

void move_robot(struct robot *r, int dt) {
    double dx = r->speed * cos(r->theta);
    double dy = r->speed * sin(r->theta);
    r->x += dx * dt;
    r->y += dy * dt;
}

void turn_robot(struct robot *r, int dt) {
    r->theta += r->turn_rate * dt;
    if (r->theta > 2 * PI) {
        r->theta -= 2 * PI;
    } else if (r->theta < 0) {
        r->theta += 2 * PI;
    }
}

int check_collision(struct robot *r, struct vector *obstacle) {
    double dx = r->x - obstacle->x;
    double dy = r->y - obstacle->y;
    double d = sqrt(dx * dx + dy * dy);
    if (d < SENSOR_RANGE) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    struct robot r;
    init_robot(&r);
    struct vector obstacle;
    obstacle.x = rand() % 100;
    obstacle.y = rand() % 100;
    while (1) {
        printf("Speed: ");
        scanf("%d", &r.speed);
        printf("Direction: ");
        scanf("%d", &r.direction);
        move_robot(&r, 100);
        if (check_collision(&r, &obstacle)) {
            printf("Collision detected!\n");
            break;
        }
    }
    return 0;
}