#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRID_SIZE 10

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    int startX, startY, endX, endY;
    int i, j;

    // Populate the grid with user input
    printf("Enter the grid (10x10 integers, use 0 for empty and non-zero for obstacles):\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Get start and end coordinates from the user
    printf("Enter start coordinates (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter end coordinates (x y): ");
    scanf("%d %d", &endX, &endY);

    // Check if start and end points are within bounds and not obstacles
    if (startX < 0 || startX >= GRID_SIZE || startY < 0 || startY >= GRID_SIZE || grid[startX][startY] != 0) {
        printf("Start point is invalid.\n");
        return 1;
    }
    if (endX < 0 || endX >= GRID_SIZE || endY < 0 || endY >= GRID_SIZE || grid[endX][endY] != 0) {
        printf("End point is invalid.\n");
        return 1;
    }

    // Placeholder for pathfinding algorithm
    printf("Pathfinding algorithm goes here.\n");

    return 0;
}
