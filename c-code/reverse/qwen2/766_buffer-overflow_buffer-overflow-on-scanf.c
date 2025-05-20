#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int grid[10][10];
    int x, y;

    printf("Enter 100 integers for a 10x10 grid:\n");
    for (int i = 0; i < 100; i++) {
        scanf("%d", &grid[i / 10][i % 10]);
    }

    printf("Enter coordinates (x y) to access the grid:\n");
    while (scanf("%d %d", &x, &y) == 2) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            printf("Value at (%d, %d): %d\n", x, y, grid[x][y]);
        } else {
            printf("Buffer overflow attempt detected!\n");
        }
    }

    return 0;
}
