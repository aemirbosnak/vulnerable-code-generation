//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("Current Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                printf("---");
                if (k < BOARD_SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
}

int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) return 0;
        }
    }
    return 1;
}

int checkVictory() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && 
            board[i][0] == board[i][1] && 
            board[i][0] == board[i][2] && 
            board[i][0] == board[i][3]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != EMPTY && 
            board[0][j] == board[1][j] && 
            board[0][j] == board[2][j] && 
            board[0][j] == board[3][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && 
        board[0][0] == board[1][1] && 
        board[0][0] == board[2][2] && 
        board[0][0] == board[3][3]) {
        return 1;
    }
    if (board[0][3] != EMPTY && 
        board[0][3] == board[1][2] && 
        board[0][3] == board[2][1] && 
        board[0][3] == board[3][0]) {
        return 1;
    }

    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void playGame() {
    int row, col;

    while (1) {
        printBoard();
        if (isBoardFull()) {
            printf("The game is a draw!\n");
            break;
        }

        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkVictory()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        switchPlayer();
    }
}

int main() {
    srand(time(NULL));
    currentPlayer = (rand() % 2) ? PLAYER_X : PLAYER_O; // Randomly choose first player
    initializeBoard();
    playGame();
    return 0;
}