//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Vehicle {
    int x, y, direction, speed;
    char color;
} Vehicle;

Vehicle createVehicle() {
    Vehicle v;
    v.x = 0;
    v.y = 0;
    v.direction = 0;
    v.speed = 0;
    v.color = 'r';
    return v;
}

void moveVehicle(Vehicle *v, int dx, int dy) {
    v->x += dx;
    v->y += dy;
    v->direction = (dx > 0) ? 1 : 0;
}

void updateVehicle(Vehicle *v) {
    switch (v->direction) {
        case 0:
            v->speed++;
            if (v->speed > MAX_SPEED) v->speed = MAX_SPEED;
            break;
        case 1:
            v->speed--;
            if (v->speed < 0) v->speed = 0;
            break;
    }
}

int main() {
    Vehicle car = createVehicle();

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        moveVehicle(&car, rand() % 2 - 1, rand() % 2 - 1);
        updateVehicle(&car);
        printf("%c car at (%d, %d) with speed %d\n", car.color, car.x, car.y, car.speed);
        sleep(1);
    }

    return 0;
}