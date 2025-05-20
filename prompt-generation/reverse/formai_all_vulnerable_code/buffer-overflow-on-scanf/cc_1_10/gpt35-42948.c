//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Print the board
void printBoard() {
    printf("   1 2 3\n");
    printf("  -------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Initialize the board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Check if the game is over
bool isGameOver() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }
    // Check for tie
    bool tie = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                tie = false;
            }
        }
    }
    if (tie) {
        return true;
    }
    //Game still ongoing
    return false;
}

// Check if the move is valid
bool isValidMove(char row, char col) {
    if ((row < 'A' || row > 'C') || (col < '1' || col > '3')) {
        return false;
    }
    int i = row - 'A';
    int j = col - '1';
    if (board[i][j] != ' ') {
        return false;
    }
    return true;
}

// Get the computer's move
void getComputerMove(char* row, char* col) {
    srand(time(NULL)); // Seed the random generator
    do {
        int i = rand() % BOARD_SIZE;
        int j = rand() % BOARD_SIZE;
        if (board[i][j] == ' ') {
            *row = 'A' + i;
            *col = '1' + j;
            return;
        }
    } while (true);
}

// Get the player's move
void getPlayerMove(char* row, char* col) {
    do {
        printf("Enter your move (e.g. A1): ");
        scanf(" %c%c", row, col);
    } while (!isValidMove(*row, *col));
}

int main() {
    bool playerTurn = true;
    char row, col;
    initBoard();
    printBoard();
    while (!isGameOver()) {
        if (playerTurn) {
            getPlayerMove(&row, &col);
            int i = row - 'A';
            int j = col - '1';
            board[i][j] = 'X';
        } else {
            getComputerMove(&row, &col);
            int i = row - 'A';
            int j = col - '1';
            board[i][j] = 'O';
            printf("The computer played: %c%c\n", row, col);
        }
        printBoard();
        playerTurn = !playerTurn;
    }
    printf("GameOver!\n");
    return 0;
}