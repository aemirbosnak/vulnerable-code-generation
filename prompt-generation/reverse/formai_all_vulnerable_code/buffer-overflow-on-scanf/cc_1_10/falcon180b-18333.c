//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define BOARD_SIZE 3

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the players
char player1 = 'X';
char player2 = 'O';

// Define the functions
void initBoard();
void printBoard();
int checkWin();
void playGame();

int main() {
    srand(time(NULL));
    initBoard();
    playGame();
    return 0;
}

// Initialize the board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Print the board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if there is a winner
int checkWin() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j]!= '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Play the game
void playGame() {
    int player = 0;
    int choice;
    int x, y;

    do {
        printf("Player %c's turn:\n", player1);
        printBoard();
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);
        if (board[x][y]!= '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[x][y] = player1;
        player = 1;
    } while (!checkWin());

    printf("\nPlayer %c wins!\n", player1);
}