#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRID_SIZE 10

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    int x, y;

    printf("Enter the grid data (10x10 integers):\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter the starting coordinates (x y): ");
    scanf("%d %d", &x, &y);

    // Vulnerable to buffer overflow
    grid[x][y] = 99;

    return 0;
}
