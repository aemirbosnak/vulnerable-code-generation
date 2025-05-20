//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the size of the 2D grid and the maximum number of moves for the RC vehicle
#define GRID_SIZE 10
#define MAX_MOVES 15

// Define the struct to store the RC vehicle location and orientation
struct Vehicle {
    int row;
    int col;
    char orientation;
};

// Utility function to print the 2D grid with the RC vehicle
void print_grid(char grid[][GRID_SIZE], struct Vehicle vehicle) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == vehicle.row && j == vehicle.col) {
                printf("%c ", vehicle.orientation);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the 2D grid with spaces
    char grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }

    // Initialize the RC vehicle at the center of the grid, facing north
    struct Vehicle vehicle = { GRID_SIZE / 2, GRID_SIZE / 2, '^' };

    // Print the initial grid with the RC vehicle
    printf("Initial grid:\n");
    print_grid(grid, vehicle);

    // Loop through the maximum number of moves and prompt the user for input
    for (int i = 1; i <= MAX_MOVES; i++) {
        printf("Move %d: Enter a command (F/B/L/R): ", i);

        // Read the user input and update the RC vehicle accordingly
        char command;
        scanf(" %c", &command);
        if (command == 'F' || command == 'B') {
            // Move forward or backward in the direction the RC vehicle is facing
            int row_diff = (vehicle.orientation == 'v' && command == 'F')
                         || (vehicle.orientation == '^' && command == 'B')
                         ? 1
                         : (vehicle.orientation == '^' && command == 'F')
                         || (vehicle.orientation == 'v' && command == 'B')
                         ? -1
                         : 0;
            int col_diff = (vehicle.orientation == '>' && command == 'F')
                         || (vehicle.orientation == '<' && command == 'B')
                         ? 1
                         : (vehicle.orientation == '<' && command == 'F')
                         || (vehicle.orientation == '>' && command == 'B')
                         ? -1
                         : 0;
            int new_row = vehicle.row + row_diff;
            int new_col = vehicle.col + col_diff;
            if (new_row >= 0 && new_row < GRID_SIZE && new_col >= 0 && new_col < GRID_SIZE) {
                vehicle.row = new_row;
                vehicle.col = new_col;
            }
        } else if (command == 'L' || command == 'R') {
            // Turn left or right by changing the orientation of the RC vehicle
            vehicle.orientation = command == 'L'
                                 ? vehicle.orientation == 'v'
                                   ? '>'
                                   : vehicle.orientation == '>'
                                     ? '^'
                                     : vehicle.orientation == '^'
                                       ? '<'
                                       : '<'
                                 : vehicle.orientation == '<'
                                   ? '^'
                                   : vehicle.orientation == '^'
                                     ? '>'
                                     : vehicle.orientation == '>'
                                       ? 'v'
                                       : 'v';
        }

        // Print the current grid with the updated RC vehicle
        printf("Current grid:\n");
        print_grid(grid, vehicle);
    }

    return 0;
}