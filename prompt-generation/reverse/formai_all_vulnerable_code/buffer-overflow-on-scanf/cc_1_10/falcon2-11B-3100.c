//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define EMPTY 0
#define X 1
#define O 2

// Function to print the board
void printBoard(int board[][3], int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(int board[][3], int move, int boardSize) {
    int row = move / 3;
    int col = move % 3;
    return (board[row][col] == EMPTY);
}

// Function to check if there is a winner
bool isWinner(int board[][3], int boardSize, int move) {
    int row = move / 3;
    int col = move % 3;
    if (board[row][col] == X && board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2]) {
        return true;
    }
    if (board[row][col] == O && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col]) {
        return true;
    }
    if (board[row][col] == X && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col]) {
        return true;
    }
    if (board[row][col] == O && board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 2]) {
        return true;
    }
    if (board[row][col] == X && board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 2]) {
        return true;
    }
    return false;
}

// Function to check if the game is a tie
bool isTie(int board[][3], int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move
void makeMove(int board[][3], int move, int boardSize, bool isAI) {
    int row = move / 3;
    int col = move % 3;
    if (isAI) {
        // Make a move based on AI strategy
        // TODO: Implement AI logic
    } else {
        // Player's turn
        board[row][col] = X;
        printBoard(board, boardSize);
    }
}

// Function to get player's move
int getMove(int board[][3], int boardSize) {
    int move = 0;
    while (1) {
        printf("Enter your move (0-8): ");
        scanf("%d", &move);
        if (isValidMove(board, move, boardSize)) {
            break;
        }
        printf("Invalid move. Please try again.\n");
    }
    return move;
}

// Function to play the game
void playGame(int board[][3], int boardSize, bool isAI) {
    while (!isTie(board, boardSize)) {
        int move = getMove(board, boardSize);
        makeMove(board, move, boardSize, isAI);
        if (isWinner(board, boardSize, move)) {
            printf("Player %c wins!\n", (char)(move + 'A'));
            break;
        }
        if (isTie(board, boardSize)) {
            printf("It's a tie!\n");
            break;
        }
    }
}

int main() {
    int board[3][3] = { {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY} };
    int boardSize = 3;
    bool isAI = true;
    playGame(board, boardSize, isAI);
    return 0;
}