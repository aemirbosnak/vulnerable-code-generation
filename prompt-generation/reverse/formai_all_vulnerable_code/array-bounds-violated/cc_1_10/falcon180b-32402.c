//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define NUM_VEHICLES 1

char maze[NUM_ROWS][NUM_COLS];
int num_vehicles = NUM_VEHICLES;
int vehicle_row, vehicle_col;
int vehicle_direction = 0;

void initialize_maze() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    vehicle_row = rand() % NUM_ROWS;
    vehicle_col = rand() % NUM_COLS;
    vehicle_direction = rand() % 4;
}

void print_maze() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

void move_vehicle() {
    int new_row = vehicle_row + (vehicle_direction == 0? 1 : 0);
    int new_col = vehicle_col + (vehicle_direction == 1? 1 : 0);

    if (maze[new_row][new_col] == 0) {
        maze[vehicle_row][vehicle_col] = 0;
        vehicle_row = new_row;
        vehicle_col = new_col;
    }
}

int main() {
    srand(time(NULL));
    initialize_maze();

    while (1) {
        print_maze();
        move_vehicle();
        printf("\n");
        usleep(100000);
    }

    return 0;
}