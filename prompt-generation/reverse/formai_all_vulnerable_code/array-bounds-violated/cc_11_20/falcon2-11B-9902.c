//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define MAX_VEHICLES 50

typedef struct {
    int x;
    int y;
    int speed;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int num_vehicles = 0;

int main(int argc, char *argv[]) {
    srand(time(0));

    int grid_size = 100;
    int num_vehicles = 20;
    int speed = rand() % 10 + 1;

    for (int i = 0; i < num_vehicles; i++) {
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        vehicles[i].x = x;
        vehicles[i].y = y;
        vehicles[i].speed = speed;
        num_vehicles++;
    }

    for (int i = 0; i < num_vehicles; i++) {
        int x = vehicles[i].x;
        int y = vehicles[i].y;

        if (x == 0 && y == 0) {
            printf("Start of the road\n");
        } else if (x == grid_size - 1 && y == grid_size - 1) {
            printf("End of the road\n");
        } else {
            printf("Cell (%d, %d)\n", x, y);
        }

        printf("Vehicle %d is at position (%d, %d) with speed %d\n", i+1, x, y, vehicles[i].speed);
    }

    for (int i = 0; i < num_vehicles; i++) {
        int x = vehicles[i].x;
        int y = vehicles[i].y;
        int new_x = x;
        int new_y = y;

        if (x == 0 && y == 0) {
            new_x = (rand() % grid_size) + 1;
            new_y = (rand() % grid_size) + 1;
            vehicles[i].x = new_x;
            vehicles[i].y = new_y;
            printf("Vehicle %d moved to (%d, %d)\n", i+1, new_x, new_y);
        } else if (x == grid_size - 1 && y == grid_size - 1) {
            new_x = (rand() % grid_size) + 1;
            new_y = (rand() % grid_size) + 1;
            vehicles[i].x = new_x;
            vehicles[i].y = new_y;
            printf("Vehicle %d moved to (%d, %d)\n", i+1, new_x, new_y);
        } else {
            if (y < grid_size - 1) {
                new_y = y + 1;
            } else {
                new_y = 0;
            }

            if (x < grid_size - 1) {
                new_x = x + 1;
            } else {
                new_x = 0;
            }

            vehicles[i].x = new_x;
            vehicles[i].y = new_y;
            printf("Vehicle %d moved to (%d, %d)\n", i+1, new_x, new_y);
        }
    }

    printf("Simulation complete!\n");

    return 0;
}