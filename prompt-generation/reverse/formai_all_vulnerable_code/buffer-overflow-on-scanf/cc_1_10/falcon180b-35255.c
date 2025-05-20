//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 1

#define MAX_TURN_RATE 100
#define MIN_TURN_RATE 1

typedef struct {
    float x;
    float y;
    float theta;
    float v;
    float w;
} Vehicle;

void move(Vehicle *v, float dt) {
    float r = v->v * cos(v->theta);
    float l = v->v * sin(v->theta);
    v->x += r * cos(v->theta + v->w * dt) - l * sin(v->theta + v->w * dt);
    v->y += l * cos(v->theta + v->w * dt) + r * sin(v->theta + v->w * dt);
    v->theta += v->w * dt;
    v->v += (MAX_SPEED - v->v) * dt;
    if (v->v > MAX_SPEED) {
        v->v = MAX_SPEED;
    } else if (v->v < MIN_SPEED) {
        v->v = MIN_SPEED;
    }
}

void turn(Vehicle *v, float dt, float turn_rate) {
    v->w += turn_rate * dt;
    if (v->w > MAX_TURN_RATE) {
        v->w = MAX_TURN_RATE;
    } else if (v->w < MIN_TURN_RATE) {
        v->w = MIN_TURN_RATE;
    }
}

int main() {
    srand(time(NULL));

    Vehicle v = {0, 0, 0, 0, 0};
    int running = 1;

    while (running) {
        system("clear");
        printf("Current position: (%f, %f)\n", v.x, v.y);
        printf("Current speed: %f\n", v.v);
        printf("Current heading: %f\n", v.theta);

        char command;
        scanf("%c", &command);

        switch (command) {
            case 'w':
                move(&v, 0.1);
                break;
            case's':
                move(&v, 0.1);
                break;
            case 'a':
                turn(&v, 0.1, 50);
                break;
            case 'd':
                turn(&v, 0.1, -50);
                break;
            case 'q':
                running = 0;
                break;
            default:
                printf("Invalid command\n");
        }

        usleep(100000);
    }

    return 0;
}