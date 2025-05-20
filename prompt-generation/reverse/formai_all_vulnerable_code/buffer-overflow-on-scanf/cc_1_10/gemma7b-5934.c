//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

#define EMPTY_SPACE ' '

typedef struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameStatus;
} Board;

void initializeBoard(Board *board) {
    board->currentPlayer = PLAYER_X;
    board->gameStatus = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY_SPACE;
        }
    }
}

int isBoardFull(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == EMPTY_SPACE) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != EMPTY_SPACE) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != EMPTY_SPACE) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_SPACE) {
        return 1;
    }

    // If all cells are filled and no winner, it's a draw
    return 2;
}

int main() {
    Board board;
    initializeBoard(&board);

    while (!isBoardFull(&board) && board.gameStatus == 0) {
        // Get the player's move
        int moveX, moveY;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Validate the move
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece
        board.board[moveX][moveY] = board.currentPlayer;

        // Switch the current player
        board.currentPlayer = (board.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if there is a winner or a draw
    switch (checkWin(&board)) {
        case 1:
            printf("Congratulations! You won!\n");
            break;
        case 2:
            printf("It's a draw.\n");
            break;
        default:
            printf("Error.\n");
    }

    return 0;
}