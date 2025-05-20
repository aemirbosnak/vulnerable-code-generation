//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS 100
#define MAXCOLS 100

int main(void)
{
    int rows, cols;
    char grid[MAXROWS][MAXCOLS];
    int i, j;
    int neighbors;

    printf("Enter the number of rows and columns in the grid: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the initial state of the grid (0 for dead, 1 for alive):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    printf("The grid after %d iterations:\n", 10);
    for (int k = 0; k < 10; k++) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                neighbors = 0;
                for (int m = i - 1; m <= i + 1; m++) {
                    for (int n = j - 1; n <= j + 1; n++) {
                        if (m >= 0 && m < rows && n >= 0 && n < cols && !(m == i && n == j) && grid[m][n] == '1') {
                            neighbors++;
                        }
                    }
                }
                if (grid[i][j] == '1' && (neighbors == 2 || neighbors == 3)) {
                    grid[i][j] = '1';
                } else if (grid[i][j] == '0' && neighbors == 3) {
                    grid[i][j] = '1';
                } else {
                    grid[i][j] = '0';
                }
            }
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}