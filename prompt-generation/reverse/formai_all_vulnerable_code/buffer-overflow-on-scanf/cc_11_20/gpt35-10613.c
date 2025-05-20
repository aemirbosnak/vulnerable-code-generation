//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program is a configurable C table game example.
 * The game is played on a square matrix of size N x N.
 * The objective is to visit all the cells of the matrix exactly once.
 * The player starts at a random cell and moves in a randomly chosen direction.
 * At each step, the player chooses a direction that has not been visited yet.
 * If the player reaches a dead end, they retreat to the previous cell and choose a different direction.
 * The game ends when all cells have been visited.
 * The user can specify the size of the matrix and the seed to generate random numbers.
 */

// Constants
const int MAX_SIZE = 10;
const int MIN_SIZE = 3;
const int MAX_SEED = 10000;

// Function prototypes
void printMatrix(int matrix[][MAX_SIZE], int size);
int move(int matrix[][MAX_SIZE], int size, int row, int col, int visitedCount, int seed);

// Main function
int main() {
    // Variable declaration
    int size, seed, visitedCount, row, col, direction, i, j;
    int matrix[MAX_SIZE][MAX_SIZE];

    // Get inputs from user
    printf("Enter the size of the matrix (minimum %d, maximum %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size. Terminating program.\n");
        return 1;
    }

    printf("Enter the seed for random number generator (maximum %d): ", MAX_SEED);
    scanf("%d", &seed);
    srand(seed);

    // Initialize matrix to -1
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = -1;
        }
    }

    // Start at a random cell
    row = rand() % size;
    col = rand() % size;
    matrix[row][col] = 0;
    visitedCount = 1;

    // Play the game
    while (visitedCount < size * size) {
        direction = rand() % 4; // 0=up, 1=right, 2=down, 3=left

        switch (direction) {
        case 0: // up
            if (row > 0 && matrix[row-1][col] == -1) {
                row--;
                visitedCount++;
                matrix[row][col] = visitedCount;
            }
            break;
        case 1: // right
            if (col < size-1 && matrix[row][col+1] == -1) {
                col++;
                visitedCount++;
                matrix[row][col] = visitedCount;
            }
            break;
        case 2: // down
            if (row < size-1 && matrix[row+1][col] == -1) {
                row++;
                visitedCount++;
                matrix[row][col] = visitedCount;
            }
            break;
        case 3: // left
            if (col > 0 && matrix[row][col-1] == -1) {
                col--;
                visitedCount++;
                matrix[row][col] = visitedCount;
            }
            break;
        }

        // If reached dead end, retreat to previous cell
        if (visitedCount < size * size && (row == 0 || matrix[row-1][col] != -1) &&
            (col == size-1 || matrix[row][col+1] != -1) &&
            (row == size-1 || matrix[row+1][col] != -1) &&
            (col == 0 || matrix[row][col-1] != -1)) {
            visitedCount--;
            matrix[row][col] = -1;
            if (col > 0 && matrix[row][col-1] == visitedCount-1) {
                col--;
            } else if (row > 0 && matrix[row-1][col] == visitedCount-1) {
                row--;
            } else if (col < size-1 && matrix[row][col+1] == visitedCount-1) {
                col++;
            } else if (row < size-1 && matrix[row+1][col] == visitedCount-1) {
                row++;
            }
        }
    }

    // Print the matrix
    printMatrix(matrix, size);

    return 0;
}

// Print the matrix
void printMatrix(int matrix[][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}