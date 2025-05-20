//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int x, y, z;
    int **percolation_array;
    int num_iter = 0;
    srand(time(NULL));

    // Allocate memory for the percoltion array
    percolation_array = (int **)malloc(50 * sizeof(int *));
    for (x = 0; x < 50; x++) {
        percolation_array[x] = (int *)malloc(50 * sizeof(int));
    }

    // Initialize the percoltion array
    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            percolation_array[x][y] = 0;
        }
    }

    // Randomly fill the percoltion array
    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            percolation_array[x][y] = rand() % 2;
        }
    }

    // Percolation algorithm
    while (!percolation_array[24][24]) {
        num_iter++;
        for (x = 0; x < 50; x++) {
            for (y = 0; y < 50; y++) {
                if (percolation_array[x][y] == 1) {
                    // Check if the cell above is open
                    if (percolation_array[x][y - 1] == 1) {
                        percolation_array[x][y] = 2;
                    }
                    // Check if the cell to the right is open
                    if (percolation_array[x + 1][y] == 1) {
                        percolation_array[x][y] = 2;
                    }
                }
            }
        }
    }

    // Print the percoltion array
    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            printf("%d ", percolation_array[x][y]);
        }
        printf("\n");
    }

    // Free the memory allocated for the percoltion array
    for (x = 0; x < 50; x++) {
        for (y = 0; y < 50; y++) {
            free(percolation_array[x][y]);
        }
        free(percolation_array[x]);
    }
    free(percolation_array);

    // Print the number of iterations
    printf("Number of iterations: %d\n", num_iter);

    return 0;
}