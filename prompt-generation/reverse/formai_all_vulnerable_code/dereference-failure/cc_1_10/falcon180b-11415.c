//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Car;

void move_car(Car *car) {
    if (car->direction == 0) {
        car->y += car->speed;
    } else {
        car->y -= car->speed;
    }
}

int check_collision(Car *car1, Car *car2) {
    if (car1->x == car2->x && car1->y == car2->y) {
        return 1;
    } else {
        return 0;
    }
}

void change_direction(Car *car) {
    if (car->direction == 0) {
        car->direction = 1;
    } else {
        car->direction = 0;
    }
}

void print_car(Car *car) {
    printf("Car at (%d, %d) moving %d units every %d seconds\n", car->x, car->y, car->speed, 5);
}

int main() {
    srand(time(NULL));
    int num_cars = rand() % 10 + 1;
    Car cars[num_cars];

    for (int i = 0; i < num_cars; i++) {
        cars[i].x = rand() % 20 + 1;
        cars[i].y = rand() % 20 + 1;
        cars[i].speed = rand() % 10 + 1;
        cars[i].direction = rand() % 2;
    }

    while (1) {
        for (int i = 0; i < num_cars; i++) {
            move_car(&cars[i]);
            if (check_collision(&cars[i], &cars[i-1]) == 1) {
                change_direction(&cars[i]);
            }
        }
        printf("Cars on the road:\n");
        for (int i = 0; i < num_cars; i++) {
            print_car(&cars[i]);
        }
        sleep(5);
    }

    return 0;
}