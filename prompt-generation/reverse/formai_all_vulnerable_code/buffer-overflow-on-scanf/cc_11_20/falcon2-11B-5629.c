//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int grid[9][9];
    int row, col, num;
    int i, j;
    int find;
    int set;
    int check;

    // Reading the grid
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solving the grid
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            // Checking if the cell is empty
            if (grid[i][j] == 0) {
                // Finding the next possible number
                for (num = 1; num <= 9; num++) {
                    // Checking if the number is valid
                    for (row = 0; row < 9; row++) {
                        if (grid[row][j] == num || grid[i][row] == num || grid[3 * (i / 3) + row / 3][3 * (j / 3) + row % 3] == num) {
                            break;
                        }
                    }
                    if (row == 9) {
                        grid[i][j] = num;
                        break;
                    }
                }
            }
        }
    }

    // Printing the grid
    printf("Solution: \n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}