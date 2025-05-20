//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameStatus;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
    board->currentPlayer = PLAYER_X;
    board->gameStatus = 0;
}

void displayGameBoard(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int hasPlayerWon(GameBoard *board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }

    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

void makeMove(GameBoard *board, int row, int column) {
    if (board->board[row][column] != ' ') {
        return;
    }
    board->board[row][column] = board->currentPlayer;
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    displayGameBoard(&board);

    while (!isBoardFull(&board) && !hasPlayerWon(&board, board.currentPlayer)) {
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);
        makeMove(&board, row, column);
        displayGameBoard(&board);
    }

    if (hasPlayerWon(&board, board.currentPlayer)) {
        printf("Congratulations, %c, you won!\n", board.currentPlayer);
    } else if (isBoardFull(&board)) {
        printf("It's a draw!\n");
    }

    return 0;
}