//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int winner;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->board[0][0] = EMPTY_SPOT;
    board->board[0][1] = EMPTY_SPOT;
    board->board[0][2] = EMPTY_SPOT;
    board->board[1][0] = EMPTY_SPOT;
    board->board[1][1] = EMPTY_SPOT;
    board->board[1][2] = EMPTY_SPOT;
    board->board[2][0] = EMPTY_SPOT;
    board->board[2][1] = EMPTY_SPOT;
    board->board[2][2] = EMPTY_SPOT;
    board->currentPlayer = PLAYER_X;
    board->winner = EMPTY_SPOT;
}

void printGameBoard(GameBoard *board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%d ", board->board[r][c]);
        }
        printf("\n");
    }
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != EMPTY_SPOT) {
            return board->board[r][0];
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != EMPTY_SPOT) {
            return board->board[0][c];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_SPOT) {
        return board->board[0][0];
    }

    // If all spots are filled and there is no winner, it's a draw
    return EMPTY_SPOT;
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    printGameBoard(&board);

    int move = 0;
    while (board.winner == EMPTY_SPOT) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Validate move
        if (move < 1 || move > 9) {
            printf("Invalid move.\n");
            continue;
        }

        // Make move
        board.board[move - 1][move - 1] = board.currentPlayer;

        // Print updated board
        printGameBoard(&board);

        // Check for winner
        board.winner = checkWin(&board);

        // Switch player
        board.currentPlayer = (board.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    printGameBoard(&board);

    if (board.winner == PLAYER_X) {
        printf("You win!\n");
    } else if (board.winner == PLAYER_O) {
        printf("You lose!\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}