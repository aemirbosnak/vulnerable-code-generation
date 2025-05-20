//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int moveCount;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->moveCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
}

int isValidMove(GameBoard *board, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (board->board[x][y] != ' ') {
        return 0;
    }
    return 1;
}

void makeMove(GameBoard *board, int x, int y) {
    board->board[x][y] = board->currentPlayer;
    board->moveCount++;
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->currentPlayer &&
            board->board[1][i] == board->currentPlayer &&
            board->board[2][i] == board->currentPlayer) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->currentPlayer &&
            board->board[j][1] == board->currentPlayer &&
            board->board[j][2] == board->currentPlayer) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->currentPlayer &&
        board->board[1][1] == board->currentPlayer &&
        board->board[2][2] == board->currentPlayer) {
        return 1;
    }

    if (board->moveCount == BOARD_SIZE * BOARD_SIZE) {
        return 0;
    }

    return -1;
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    // Play the game
    int gameStatus = 0;
    while (!gameStatus) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate the move
        if (!isValidMove(&board, x, y)) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        makeMove(&board, x, y);

        // Check if the player has won
        gameStatus = checkWin(&board);

        // Print the board
        printf("Board:\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board.board[i][j]);
            }
            printf("\n");
        }

        // Switch to the next player
        board.currentPlayer = (board.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    printf("Game over! The winner is: %c\n", board.currentPlayer);

    return 0;
}