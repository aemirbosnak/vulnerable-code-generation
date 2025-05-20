//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the tic-tac-toe board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", (board[i][j] == 1? 'X' : 'O'));
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(int board[3][3]) {
    int player = 1; // Player 1 (X)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] == board[i][2] == player) {
            return 1; // Player 1 has won
        }
        if (board[0][i] == board[1][i] == board[2][i] == player) {
            return 1; // Player 1 has won
        }
        if (board[0][0] == board[1][1] == board[2][2] == player) {
            return 1; // Player 1 has won
        }
        if (board[0][2] == board[1][1] == board[2][0] == player) {
            return 1; // Player 1 has won
        }
        player *= -1; // Change player
    }
    player = 2; // Player 2 (O)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] == board[i][2] == player) {
            return 2; // Player 2 has won
        }
        if (board[0][i] == board[1][i] == board[2][i] == player) {
            return 2; // Player 2 has won
        }
        if (board[0][0] == board[1][1] == board[2][2] == player) {
            return 2; // Player 2 has won
        }
        if (board[0][2] == board[1][1] == board[2][0] == player) {
            return 2; // Player 2 has won
        }
    }
    return 0; // No one has won
}

// Function to choose a random empty cell on the board
int chooseRandomCell(int board[3][3]) {
    int cell = -1; // Index of the chosen cell
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                cell = i * 3 + j; // Cell index
                break; // Choose the first empty cell
            }
        }
        if (cell!= -1) {
            break; // Choose the first empty cell
        }
    }
    return cell;
}

// Function to get user input
void getUserInput(int board[3][3]) {
    int row, col;
    printf("Enter the row and column of the cell you want to mark: ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0) {
        board[row][col] = 1; // Player 1 (X) marks the cell
        printf("Cell (%d, %d) marked with X.\n", row, col);
    } else {
        printf("Invalid input.\n");
    }
}

// Main function
int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1; // Player 1 (X)
    int moves = 0; // Number of moves made by both players

    while (moves < 9) {
        printBoard(board);
        printf("Player %d's turn.\n", player);
        getUserInput(board);
        if (checkWin(board)!= 0) {
            printf("Player %d wins!\n", checkWin(board));
            break;
        }
        moves++;
        player *= -1; // Change player
    }
    if (moves == 9) {
        printf("It's a draw!\n");
    }

    return 0;
}