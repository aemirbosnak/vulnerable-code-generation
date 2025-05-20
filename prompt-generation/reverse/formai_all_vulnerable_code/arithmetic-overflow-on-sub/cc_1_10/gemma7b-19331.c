//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_CARS 2

typedef struct Car {
    int x, y;
    char direction;
    int speed;
} Car;

Car cars[NUM_CARS];

void initialize_cars() {
    cars[0].x = 0;
    cars[0].y = 0;
    cars[0].direction = 'N';
    cars[0].speed = 1;

    cars[1].x = 10;
    cars[1].y = 0;
    cars[1].direction = 'S';
    cars[1].speed = 2;
}

void move_cars() {
    switch (cars[0].direction) {
        case 'N':
            cars[0].y++;
            break;
        case 'S':
            cars[0].y--;
            break;
        case 'E':
            cars[0].x++;
            break;
        case 'W':
            cars[0].x--;
            break;
    }

    switch (cars[1].direction) {
        case 'N':
            cars[1].y++;
            break;
        case 'S':
            cars[1].y--;
            break;
        case 'E':
            cars[1].x++;
            break;
        case 'W':
            cars[1].x--;
            break;
    }
}

void display_cars() {
    printf("Cars:\n");
    for (int i = 0; i < NUM_CARS; i++) {
        printf("Car %d: (%d, %d) Direction: %c Speed: %d\n", i + 1, cars[i].x, cars[i].y, cars[i].direction, cars[i].speed);
    }
}

int main() {
    initialize_cars();

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        move_cars();
        display_cars();
        sleep(1);
    }

    return 0;
}