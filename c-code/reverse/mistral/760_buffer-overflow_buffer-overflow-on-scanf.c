#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

int main() {
    int grid[ROWS][COLS];
    int start_x, start_y, end_x, end_y;
    char input[10];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("Enter grid value at (%d, %d): ", i, j);
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%d", &grid[i][j]);
        }
    }

    printf("Enter start coordinates (x y): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &start_x, &start_y);

    printf("Enter end coordinates (x y): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &end_x, &end_y);

    // Your path finding algorithm here...

    return 0;
}
