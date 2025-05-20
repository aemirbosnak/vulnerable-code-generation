//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the grid
#define GRID_MAX_SIZE 10

// Define the movements for the GPS navigation
#define MOVE_UP 'U'
#define MOVE_DOWN 'D'
#define MOVE_LEFT 'L'
#define MOVE_RIGHT 'R'

// Grid structure
struct Grid {
    int size; // size of the grid
    int x; // current X coordinate
    int y; // current Y coordinate
    bool visited[GRID_MAX_SIZE][GRID_MAX_SIZE]; // visited cells
};


// Initialize the grid
void init_grid(struct Grid* grid, int size) {
    grid->size = size;
    grid->x = 0;
    grid->y = 0;
    memset(grid->visited, false, sizeof(grid->visited));
}

// Move the GPS navigation in the given direction
void move(struct Grid* grid, char direction) {
    switch(direction) {
        case MOVE_UP:
            if(grid->y > 0)
                grid->y--;
            break;
        case MOVE_DOWN:
            if(grid->y < grid->size-1)
                grid->y++;
            break;
        case MOVE_LEFT:
            if(grid->x > 0)
                grid->x--;
            break;
        case MOVE_RIGHT:
            if(grid->x < grid->size-1)
                grid->x++;
            break;
    }
}

// Print the current status of the GPS navigation on the grid
void print_status(struct Grid* grid) {
    printf("\nCurrent position: (%d,%d)\n", grid->x, grid->y);
    printf("Visited cells: ");
    for(int i = 0; i < grid->size; i++) {
        for(int j = 0; j < grid->size; j++) {
            if(grid->visited[i][j])
                printf("(%d,%d) ", i, j);
        }
    }
    printf("\n");
}

int main() {
    int size;
    char input;
    struct Grid grid;

    printf("Welcome to the Retro GPS Navigation Simulation!\n");
    printf("Enter the size of the grid (max %d): ", GRID_MAX_SIZE);
    scanf("%d", &size);

    if(size > GRID_MAX_SIZE) {
        printf("Grid size too large. Exiting...\n");
        return 1;
    }

    init_grid(&grid, size);

    // Main loop
    while(true) {
        printf("Enter a direction to move (U=up, D=down, L=left, R=right): ");
        scanf(" %c", &input);

        if(input == 'q') {
            printf("Exiting...\n");
            break;
        }

        move(&grid, input);
        grid.visited[grid.y][grid.x] = true;
        print_status(&grid);
    }

    return 0;
}