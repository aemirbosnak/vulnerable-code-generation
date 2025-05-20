//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define NUM_PIECES 12

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the pieces
char pieces[NUM_PIECES][2];

// Define the players
char player1 = 'X';
char player2 = 'O';

// Define the current player
char currentPlayer;

// Define the game state
int gameState;

// Define the function prototypes
void initBoard();
void printBoard();
void makeMove(int row, int col);
int checkForWin();
void switchPlayer();

int main() {
    srand(time(NULL));
    initBoard();
    while (gameState == 0) {
        printBoard();
        int playerRow, playerCol;
        scanf("%d %d", &playerRow, &playerCol);
        if (playerRow >= 0 && playerRow < BOARD_SIZE && playerCol >= 0 && playerCol < BOARD_SIZE) {
            if (board[playerRow][playerCol] == '-') {
                makeMove(playerRow, playerCol);
                if (checkForWin()) {
                    printf("Player %c wins!\n", currentPlayer);
                    gameState = 1;
                } else {
                    switchPlayer();
                }
            }
        }
    }
    return 0;
}

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    for (int i = 0; i < NUM_PIECES; i++) {
        pieces[i][0] = '1' + i;
        pieces[i][1] = player1;
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = currentPlayer;
        for (int i = 0; i < NUM_PIECES; i++) {
            if (pieces[i][0] == row && pieces[i][1] == col) {
                pieces[i][1] = currentPlayer;
                break;
            }
        }
    }
}

int checkForWin() {
    for (int i = 0; i < NUM_PIECES; i++) {
        int row = pieces[i][0] - '1';
        int col = pieces[i][1] - 'A';
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (board[row][col] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void switchPlayer() {
    if (currentPlayer == player1) {
        currentPlayer = player2;
    } else {
        currentPlayer = player1;
    }
}