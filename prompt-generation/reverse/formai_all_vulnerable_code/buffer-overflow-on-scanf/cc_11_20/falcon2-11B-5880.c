//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    srand(time(NULL)); // seed random number generator with current time

    // size of the grid
    printf("Enter size of grid: ");
    scanf("%d", &n);

    // create a grid of cells, each initially empty
    int grid[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }

    // perform percolation until there is a connected path from top to bottom
    int connected = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // flip a random coin to decide if this cell is connected
            int flip = rand() % 2;
            if (flip) {
                grid[i][j] = 1; // make the cell connected
                // check if the cell is connected to the top
                if (i > 0 && grid[i - 1][j] == 1) {
                    connected = 1;
                    break;
                }
                // check if the cell is connected to the left
                if (j > 0 && grid[i][j - 1] == 1) {
                    connected = 1;
                    break;
                }
            }
        }
    }

    // output the result
    if (connected) {
        printf("There is a connected path from top to bottom.\n");
    } else {
        printf("There is no connected path from top to bottom.\n");
    }

    return 0;
}