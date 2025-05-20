#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int grid[10][10];
    int x, y;

    printf("Enter the grid (10x10):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter starting coordinates (x y): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        grid[x][y] += 100;
    } else {
        printf("Invalid coordinates.\n");
    }

    return 0;
}
