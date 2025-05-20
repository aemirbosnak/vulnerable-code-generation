//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define PLAYER_X "X"
#define PLAYER_O "O"

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameState;
} GameBoard;

void InitializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->gameState = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
}

int CheckWin(GameBoard *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
        return 1;
    }

    // If all cells are filled and there is no winner, it's a draw
    if (board->gameState == 0 && board->board[0][0] != ' ') {
        return 2;
    }

    return 0;
}

void PlayTurn(GameBoard *board) {
    int row, column;

    // Get the player's move
    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &column);

    // Check if the move is valid
    if (board->board[row - 1][column - 1] != ' ') {
        printf("Invalid move. Please try again.\n");
        return;
    }

    // Make the move
    board->board[row - 1][column - 1] = board->currentPlayer;

    // Check if the player has won or there is a draw
    int winner = CheckWin(board);

    // If the player has won, they are the winner
    if (winner == 1) {
        printf("You have won! Congratulations!\n");
    }

    // If there is a draw, it's a draw
    else if (winner == 2) {
        printf("It's a draw. Sorry.\n");
    }

    // Switch to the next player
    board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int main() {
    GameBoard board;

    InitializeGameBoard(&board);

    while (!CheckWin(&board) && board.gameState == 0) {
        PlayTurn(&board);
    }

    return 0;
}