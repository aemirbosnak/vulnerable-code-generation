//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n, m, i, j, k, l, count = 0;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    // Allocate memory for the grid
    int **grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }

    // Simulate Percolation
    printf("Enter the number of iterations: ");
    scanf("%d", &k);
    for (l = 0; l < k; l++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    // Randomly choose a neighbor
                    int r = rand() % 4;
                    switch (r) {
                        case 0:
                            if (grid[i - 1][j] == 1) {
                                grid[i][j] = 1;
                                count++;
                            }
                            break;
                        case 1:
                            if (grid[i + 1][j] == 1) {
                                grid[i][j] = 1;
                                count++;
                            }
                            break;
                        case 2:
                            if (grid[i][j - 1] == 1) {
                                grid[i][j] = 1;
                                count++;
                            }
                            break;
                        case 3:
                            if (grid[i][j + 1] == 1) {
                                grid[i][j] = 1;
                                count++;
                            }
                            break;
                    }
                }
            }
        }
    }

    // Print the results
    printf("The number of sites occupied after %d iterations: ", k);
    printf("%d\n", count);

    // Free memory
    for (i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}