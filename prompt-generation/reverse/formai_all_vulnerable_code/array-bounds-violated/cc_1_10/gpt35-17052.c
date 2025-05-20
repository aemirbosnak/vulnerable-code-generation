//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3];
int player = 1;
int winner = 0;


// Function to create the board
void createBoard() {
    int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to display the board
void displayBoard() {
    int i, j;
    printf("\n");

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == 0) {
                printf(" - ");
            } else if (board[i][j] == 1) {
                printf(" X ");
            } else if (board[i][j] == 2) {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

// Function to check if there is a winner
void checkWinner() {
    int i, j;

    // Check rows
    for (i=0; i<3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            if (board[i][0] != 0) {
                winner = board[i][0];
                return;
            }
        }
    }

    // Check columns
    for (j=0; j<3; j++) {
        if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j])) {
            if (board[0][j] != 0) {
                winner = board[0][j];
                return;
            }
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        if (board[0][0] != 0) {
            winner = board[0][0];
            return;
        }
    }

    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        if (board[0][2] != 0) {
            winner = board[0][2];
            return;
        }
    }
}

// Function to get the computer player move
void getComputerMove(int* x, int* y) {
    srand(time(NULL));
    *x = rand() % 3;
    *y = rand() % 3;
    while (board[*x][*y] != 0) {
        *x = rand() % 3;
        *y = rand() % 3;
    }
}

// Main function
int main() {
    int i, j;
    int x, y;

    createBoard();
    displayBoard();

    while (winner == 0) {
        if (player == 1) {
            printf("\nEnter row (0-2), column (0-2) of your move as x,y: ");
            scanf("%d,%d", &x, &y);
            if (board[x][y] != 0) {
                printf("\nInvalid move. Try again.");
                continue;
            }
            board[x][y] = 1;
        } else {
            printf("\nComputer's move...");
            getComputerMove(&x, &y);
            board[x][y] = 2;
        }

        player = (player == 1) ? 2 : 1;
        displayBoard();
        checkWinner();
    }

    if (winner == 1) {
        printf("\nCongrats! You win!");
    } else if (winner == 2) {
        printf("\nSorry, you lost. Better luck next time!");
    } else {
        printf("\nIt's a tie!");
    }

    return 0;
}