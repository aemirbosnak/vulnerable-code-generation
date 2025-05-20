//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define DROPS 1000

int main() {
    int grid[ROWS][COLS];
    int drops = 0;
    int topRow = 0;
    int leftCol = 0;
    int rightCol = COLS - 1;
    int row, col;
    int choice;
    srand(time(NULL));

    printf("Welcome to the Percolation Simulator!\n");
    printf("Press 1 to start the simulation or 0 to exit.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                grid[row][col] = rand() % 2;
            }
        }

        while (drops < DROPS) {
            row = rand() % ROWS;
            col = rand() % COLS;

            if (row == topRow && col == leftCol) {
                grid[row][col] = 1;
                topRow++;
                leftCol++;
            } else if (row == topRow && col == rightCol) {
                grid[row][col] = 1;
                topRow++;
                rightCol--;
            } else if (col == leftCol && grid[row][col] == 1) {
                grid[row][col] = 1;
                leftCol++;
            } else if (col == rightCol && grid[row][col] == 1) {
                grid[row][col] = 1;
                rightCol--;
            }

            drops++;
        }

        printf("The simulation is complete!\n");
        printf("Would you like to see the grid? (y/n)\n");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            for (row = 0; row < ROWS; row++) {
                for (col = 0; col < COLS; col++) {
                    if (grid[row][col] == 1) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}