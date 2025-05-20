//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
    int dir;
} Car;

int rand_dir() {
    int dir = rand() % 4;
    if (dir == 0)
        dir = 1;
    return dir;
}

int move_car(Car *c) {
    int new_x = c->x + c->speed * c->dir;
    int new_y = c->y;
    if (new_x < 0 || new_x >= 30 || new_y < 0 || new_y >= 20)
        return 0;
    else
        return 1;
}

int main() {
    srand(time(NULL));

    int cars = 50;
    Car *road = malloc(cars * sizeof(Car));

    for (int i = 0; i < cars; i++) {
        road[i].x = rand() % 31;
        road[i].y = rand() % 21;
        road[i].speed = rand() % 11 + 1;
        road[i].dir = rand_dir();
    }

    int collisions = 0;

    while (1) {
        system("clear");
        for (int i = 0; i < cars; i++) {
            if (road[i].x < 0 || road[i].x >= 31 || road[i].y < 0 || road[i].y >= 21) {
                road[i].x = rand() % 31;
                road[i].y = rand() % 21;
                road[i].speed = rand() % 11 + 1;
                road[i].dir = rand_dir();
            }

            if (move_car(&road[i])) {
                road[i].x += road[i].speed * road[i].dir;
                road[i].y += road[i].speed * road[i].dir;
            } else {
                collisions++;
                road[i].x = rand() % 31;
                road[i].y = rand() % 21;
                road[i].speed = rand() % 11 + 1;
                road[i].dir = rand_dir();
            }

            printf("\033[31mC\033[0m");
        }

        printf("\nCollisions: %d\n", collisions);
        usleep(100000);
    }

    return 0;
}