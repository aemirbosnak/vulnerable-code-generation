//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// function prototypes
void printTable(int** table, int rows, int cols);
void fillTable(int** table, int rows, int cols);
int checkWin(int** table, int rows, int cols, int player);

int main() {
    srand(time(NULL)); // seed random number generator

    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int** table = (int**) malloc(rows * sizeof(int*)); // allocate memory for table
    for (int i=0; i<rows; i++) {
        table[i] = (int*) malloc(cols * sizeof(int));
    }

    fillTable(table, rows, cols); // fill table with random numbers
    printTable(table, rows, cols); // print initial table

    int player = 1;
    int winner = 0;
    while (winner == 0) { // repeat until there is a winner
        int row, col, validMove = 0;
        while (validMove == 0) { // repeat until the move is valid
            printf("Player %d's turn: ", player);
            scanf("%d %d", &row, &col);

            if (row >= 0 && row < rows && col >= 0 && col < cols && table[row][col] != -1) {
                validMove = 1;
            } else {
                printf("Invalid move. Please try again.\n");
            }
        }

        table[row][col] = -1; // mark move as used
        printTable(table, rows, cols); // print updated table

        winner = checkWin(table, rows, cols, player); // check if player has won
        if (winner != 0) { // display winner and end game
            printf("Player %d wins!\n", player);
        } else {
            player = (player == 1) ? 2 : 1; // switch players
        }
    }

    // free memory
    for (int i=0; i<rows; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

void fillTable(int** table, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            table[i][j] = (rand() % 3) + 1; // generate random number between 1 and 3
        }
    }
}

void printTable(int** table, int rows, int cols) {
    printf("  ");
    for (int j=0; j<cols; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i=0; i<rows; i++) {
        printf("%d ", i);
        for (int j=0; j<cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int checkWin(int** table, int rows, int cols, int player) {
    // check rows
    for (int i=0; i<rows; i++) {
        int sum = 0;
        for (int j=0; j<cols; j++) {
            if (table[i][j] == -1) {
                sum = 0;
            } else {
                sum += table[i][j];
                if (sum == 15) {
                    return player;
                }
            }
        }
    }

    // check columns
    for (int j=0; j<cols; j++) {
        int sum = 0;
        for (int i=0; i<rows; i++) {
            if (table[i][j] == -1) {
                sum = 0;
            } else {
                sum += table[i][j];
                if (sum == 15) {
                    return player;
                }
            }
        }
    }

    // check diagonal (top-left to bottom-right)
    for (int i=0; i<rows-2; i++) {
        for (int j=0; j<cols-2; j++) {
            int sum = table[i][j] + table[i+1][j+1] + table[i+2][j+2];
            if (sum == 15) {
                return player;
            }
        }
    }

    // check diagonal (bottom-left to top-right)
    for (int i=rows-1; i>=2; i--) {
        for (int j=0; j<cols-2; j++) {
            int sum = table[i][j] + table[i-1][j+1] + table[i-2][j+2];
            if (sum == 15) {
                return player;
            }
        }
    }

    return 0; // no winner yet
}