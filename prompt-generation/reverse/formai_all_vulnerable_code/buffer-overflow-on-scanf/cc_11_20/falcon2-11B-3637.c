//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[100][100];
    int i, j;
    int rows, cols;

    printf("Enter the number of rows and columns for the board: ");
    scanf("%d %d", &rows, &cols);

    srand(time(NULL));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }

    printf("Initial board:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    int num_active = 0;
    int num_iterations = 0;

    while (num_active < (rows * cols) / 2) {
        num_iterations++;

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (board[i][j] == 0 && num_active < (rows * cols) / 2) {
                    if (i > 0 && board[i-1][j] == 1) {
                        board[i][j] = 1;
                        num_active++;
                    }
                    if (j > 0 && board[i][j-1] == 1) {
                        board[i][j] = 1;
                        num_active++;
                    }
                    if (i < rows - 1 && board[i+1][j] == 1) {
                        board[i][j] = 1;
                        num_active++;
                    }
                    if (j < cols - 1 && board[i][j+1] == 1) {
                        board[i][j] = 1;
                        num_active++;
                    }
                }
            }
        }
    }

    printf("\nFinal board:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("Number of iterations: %d\n", num_iterations);

    return 0;
}