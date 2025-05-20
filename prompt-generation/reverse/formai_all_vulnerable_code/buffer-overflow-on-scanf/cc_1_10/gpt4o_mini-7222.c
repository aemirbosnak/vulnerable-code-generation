//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 10
#define EMPTY ' '
#define VEHICLE 'V'

typedef struct {
    int x;
    int y;
} Position;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE], Position *vehicle) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    vehicle->x = GRID_SIZE / 2;
    vehicle->y = GRID_SIZE / 2;
    grid[vehicle->y][vehicle->x] = VEHICLE;
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool move_vehicle(char grid[GRID_SIZE][GRID_SIZE], Position *vehicle, int dx, int dy) {
    int new_x = vehicle->x + dx;
    int new_y = vehicle->y + dy;

    if (new_x >= 0 && new_x < GRID_SIZE && new_y >= 0 && new_y < GRID_SIZE) {
        grid[vehicle->y][vehicle->x] = EMPTY; // Clear old position
        vehicle->x = new_x;
        vehicle->y = new_y;
        grid[vehicle->y][vehicle->x] = VEHICLE; // Set new position
        return true;
    } else {
        printf("Move blocked! Vehicle cannot go outside the grid.\n");
        return false;
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position vehicle;
    char command;

    initialize_grid(grid, &vehicle);

    while (true) {
        print_grid(grid);
        printf("Enter command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move_vehicle(grid, &vehicle, 0, -1); // Move up
                break;
            case 's':
                move_vehicle(grid, &vehicle, 0, 1); // Move down
                break;
            case 'a':
                move_vehicle(grid, &vehicle, -1, 0); // Move left
                break;
            case 'd':
                move_vehicle(grid, &vehicle, 1, 0); // Move right
                break;
            case 'q':
                printf("Exiting simulation.\n");
                exit(0);
            default:
                printf("Invalid command! Use w/a/s/d to move or q to quit.\n");
                break;
        }
    }

    return 0;
}