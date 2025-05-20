//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char symbol);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1; // Player 1 starts
    int row, col;
    int moves = 0;

    initializeBoard(board);
    printBoard(board);

    while (1) {
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if (makeMove(board, player, row, col)) {
            moves++;
            printBoard(board);

            if (checkWin(board, player == 1 ? 'X' : 'O')) {
                printf("Player %d wins!\n", player);
                break;
            }

            // Check for a draw
            if (moves == BOARD_SIZE * BOARD_SIZE) {
                printf("It's a draw!\n");
                break;
            }

            // Switch players
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move, try again!\n");
        }
    }

    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '.';
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '.') {
        board[row][col] = (player == 1) ? 'X' : 'O';
        return 1; // Move successful
    }
    return 0; // Invalid move
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    // Check horizontal and vertical lines
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1; // Win detected
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][BOARD_SIZE - 1] == symbol && board[1][BOARD_SIZE - 2] == symbol && board[2][BOARD_SIZE - 3] == symbol)) {
        return 1; // Win detected
    }

    return 0; // No win
}