//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct car_state {
    int x;
    int y;
    int direction;
    int speed;
};

void init_car(struct car_state *car) {
    car->x = 0;
    car->y = 0;
    car->direction = 0;
    car->speed = 0;
}

void print_car(struct car_state *car) {
    printf("Car is at (%d, %d), facing %d, speed %d\n", car->x, car->y, car->direction, car->speed);
}

void move_car(struct car_state *car, int direction, int speed) {
    car->direction = direction;
    car->speed = speed;
    if (car->direction == 0) {
        car->y += speed;
    } else if (car->direction == 1) {
        car->x += speed;
    } else if (car->direction == 2) {
        car->y -= speed;
    } else if (car->direction == 3) {
        car->x -= speed;
    }
}

int main() {
    struct car_state car;
    init_car(&car);

    int direction;
    int speed;

    while (1) {
        printf("Enter direction (0=up, 1=right, 2=down, 3=left): ");
        scanf("%d", &direction);
        printf("Enter speed: ");
        scanf("%d", &speed);
        move_car(&car, direction, speed);
        print_car(&car);
    }

    return 0;
}