//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

#define EMPTY_SPACE 0

typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int gameStatus;
} GameBoard;

void initializeBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->gameStatus = EMPTY_SPACE;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY_SPACE;
        }
    }
}

int isBoardFull(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == EMPTY_SPACE) {
                return 0;
            }
        }
    }

    return 1;
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != EMPTY_SPACE) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != EMPTY_SPACE) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_SPACE) {
        return board->board[0][0];
    }

    // If all else fails, it's a draw
    return EMPTY_SPACE;
}

void playTurn(GameBoard *board) {
    int row, column;

    // Get the player's move
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &column);

    // Validate the move
    if (board->board[row - 1][column - 1] != EMPTY_SPACE) {
        printf("Invalid move. Please try again.\n");
        return;
    }

    // Make the move
    board->board[row - 1][column - 1] = board->currentPlayer;

    // Check if the player has won or if the board is full
    if (checkWin(board) != EMPTY_SPACE) {
        printf("Congratulations! You have won!\n");
    } else if (isBoardFull(board) == 1) {
        printf("It's a draw!\n");
    } else {
        board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main() {
    GameBoard board;

    initializeBoard(&board);

    while (!isBoardFull(&board) && checkWin(&board) == EMPTY_SPACE) {
        playTurn(&board);
    }

    return 0;
}