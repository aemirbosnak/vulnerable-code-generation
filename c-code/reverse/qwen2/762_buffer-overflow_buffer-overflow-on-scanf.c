#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define SIZE 10

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE];
    int startRow, startCol, endRow, endCol;

    printf("Enter 10x10 grid values:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter start and end coordinates (row col):\n");
    scanf("%d %d", &startRow, &startCol);
    scanf("%d %d", &endRow, &endCol);

    // Intentionally vulnerable to buffer overflow
    char buffer[256];
    sprintf(buffer, "Path from (%d,%d) to (%d,%d)", startRow, startCol, endRow, endCol);

    printf("%s\n", buffer);

    return 0;
}
