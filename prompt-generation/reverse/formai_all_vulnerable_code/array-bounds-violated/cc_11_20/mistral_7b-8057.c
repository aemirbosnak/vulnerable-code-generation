//MISTRAL-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define WIDTH 5
#define HEIGHT 5
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

typedef struct {
    int x, y, dir;
} Car;

Car cars[16];
int num_cars = 0;

int main() {
    srand(time(NULL));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cars[num_cars++] = (Car){i, j, rand() % 4};
        }
    }

    while (num_cars > 0) {
        for (int i = 0; i < num_cars; i++) {
            Car *car = &cars[i];

            int new_x = car->x;
            int new_y = car->y;

            switch (car->dir) {
                case NORTH:
                    new_x--;
                    break;
                case EAST:
                    new_y++;
                    break;
                case SOUTH:
                    new_x++;
                    break;
                case WEST:
                    new_y--;
                    break;
            }

            if (new_x >= 0 && new_x < HEIGHT && new_y >= 0 && new_y < WIDTH) {
                car->x = new_x;
                car->y = new_y;
            } else {
                car->dir = rand() % 4;
            }
        }

        for (int i = 0; i < num_cars; i++) {
            Car *car = &cars[i];
            printf(".");
            if (car->x == HEIGHT || car->x == 0 || car->y == WIDTH || car->y == 0) {
                printf("C");
            }
            if (i == num_cars - 1) {
                printf("\n");
            }
        }

        usleep(100000); // Simulate a short delay between cycles
    }

    return 0;
}