//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function to print the tic tac toe board
void printBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won the game
int checkWin(char board[SIZE][SIZE], char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return 1;
    }

    return 0;
}

// Function to get a valid move from the user
void getMove(int *row, int *col, char board[SIZE][SIZE]) {
    int validInput = 0;
    while (!validInput) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", row, col);
        if (*row >= 0 && *row < SIZE && *col >= 0 && *col < SIZE && board[*row][*col] == '\0') {
            validInput = 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    board[*row][*col] = (*row + *col) % 2 + '0';
}

// Function to play a game of tic tac toe
void playGame(char board[SIZE][SIZE]) {
    int player = 0;
    while (1) {
        printf("Player %d's turn.\n", player + 1);
        printBoard(board);
        getMove(&board[player][0], &board[0][player], board);
        if (checkWin(board, board[player][0])) {
            printf("Player %d wins!\n", player + 1);
            break;
        }
        player =!player;
    }
}

int main() {
    char board[SIZE][SIZE] = { {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'} };
    playGame(board);
    return 0;
}