//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdbool.h>

// Function to check if a cell is occupied
bool isOccupied(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return true;
    }

    return false;
}

// Function to check if a player has won
bool isWinner(int row, int col) {
    if (row == col && row == 0 && col == 1 && col == 2) {
        return true;
    }

    if (row == col && row == 1 && col == 2 && col == 3) {
        return true;
    }

    if (row == col && row == 2 && col == 3 && col == 4) {
        return true;
    }

    if (row == col && row == 2 && col == 3 && col == 5) {
        return true;
    }

    if (row == col && row == 0 && col == 3 && col == 6) {
        return true;
    }

    if (row == col && row == 1 && col == 4 && col == 7) {
        return true;
    }

    if (row == col && row == 2 && col == 5 && col == 8) {
        return true;
    }

    if (row == col && row == 2 && col == 6 && col == 7) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool isDraw(int board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }

    return true;
}

// Function to get the next move
int getMove(int board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == 0) {
                return row * 3 + col;
            }
        }
    }

    return -1;
}

// Function to update the board
void updateBoard(int board[3][3], int move) {
    board[move / 3][move % 3] = 1;
}

// Function to print the board
void printBoard(int board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", board[row][col]);
        }

        printf("\n");
    }

    printf("\n");
}

// Main function
int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int move;

    while (true) {
        printBoard(board);

        printf("Player 1: Enter your move (1-9): ");
        scanf("%d", &move);

        if (isOccupied(move / 3, move % 3)) {
            printf("Invalid move!\n");
            continue;
        }

        updateBoard(board, move);

        if (isWinner(move / 3, move % 3)) {
            printf("Player 1 wins!\n");
            break;
        }

        if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }

        printf("Player 2: Enter your move (1-9): ");
        scanf("%d", &move);

        if (isOccupied(move / 3, move % 3)) {
            printf("Invalid move!\n");
            continue;
        }

        updateBoard(board, move);

        if (isWinner(move / 3, move % 3)) {
            printf("Player 2 wins!\n");
            break;
        }

        if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}