#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    int start_x, start_y, end_x, end_y;

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter starting coordinates (x y): ");
    scanf("%d%*c%d", &start_x, &start_y);

    printf("Enter ending coordinates (x y): ");
    scanf("%d%*c%d", &end_x, &end_y);

    // Pathfinding algorithm implementation here (intentionally omitted)

    return 0;
}
