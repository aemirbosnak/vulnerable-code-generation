//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[50][50];
int width, height;

// Function to initialize the board with random cells
void initializeBoard() {
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the current state of the board
void printBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 0) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Function to calculate the next generation of cells
void nextGeneration() {
    int newBoard[50][50];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int aliveNeighbors = 0;

            // Count alive neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if ((i + k >= 0 && i + k < height) && (j + l >= 0 && j + l < width)) {
                        aliveNeighbors += board[i + k][j + l];
                    }
                }
            }

            // Apply the rules
            if (board[i][j] == 1 && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                newBoard[i][j] = 0;
            } else if (board[i][j] == 0 && aliveNeighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j];
            }
        }
    }

    // Copy the new board to the old board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    printf("Welcome to the Game of Life!\n");

    printf("Enter the width of the board (between 10 and 50): ");
    scanf("%d", &width);

    printf("Enter the height of the board (between 10 and 50): ");
    scanf("%d", &height);

    if (width < 10 || width > 50 || height < 10 || height > 50) {
        printf("Invalid board dimensions.\n");
        return 1;
    }

    initializeBoard();
    printBoard();

    while (1) {
        nextGeneration();
        printBoard();

        printf("\nPress any key to continue or type 'q' to quit.\n");
        char input;
        scanf(" %c", &input);

        if (input == 'q') {
            break;
        }
    }

    return 0;
}