//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_CELL 0
#define PLAYER_CELL 1
#define COMPUTER_CELL 2

typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int gameStatus;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_CELL;
    board->gameStatus = EMPTY_CELL;
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board->board[r][c] = EMPTY_CELL;
        }
    }
}

int isBoardFull(GameBoard *board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board->board[r][c] == EMPTY_CELL) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != EMPTY_CELL) {
            return board->board[r][0];
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != EMPTY_CELL) {
            return board->board[0][c];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_CELL) {
        return board->board[0][0];
    }

    // No win, so it's a draw
    return EMPTY_CELL;
}

void makeMove(GameBoard *board, int row, int column) {
    if (board->board[row][column] != EMPTY_CELL) {
        return;
    }

    board->board[row][column] = board->currentPlayer;
    board->currentPlayer = (board->currentPlayer == PLAYER_CELL) ? COMPUTER_CELL : PLAYER_CELL;
}

int main() {
    GameBoard gameBoard;
    initializeGameBoard(&gameBoard);

    while (!isBoardFull(&gameBoard) && checkWin(&gameBoard) == EMPTY_CELL) {
        int moveRow, moveColumn;
        printf("Enter move row: ");
        scanf("%d", &moveRow);
        printf("Enter move column: ");
        scanf("%d", &moveColumn);
        makeMove(&gameBoard, moveRow, moveColumn);
    }

    checkWin(&gameBoard) == PLAYER_CELL ? printf("You win!") : printf("Computer wins!");
    return 0;
}