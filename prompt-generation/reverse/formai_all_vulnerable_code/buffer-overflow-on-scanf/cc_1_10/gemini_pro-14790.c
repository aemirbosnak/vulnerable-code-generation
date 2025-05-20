//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Initialises the game board
void initBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Prints the game board
void printBoard(char board[][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Checks if the game is over
int isGameOver(char board[][SIZE]) {
    // Check rows for win
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns for win
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals for win
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check for draw
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 2;
}

// Gets the best move for the AI
int getBestMove(char board[][SIZE], int player) {
    // If the AI can win, return the winning move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (isGameOver(board) == 1) {
                    return i * SIZE + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // If the human can win, block the winning move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = (player == 'X') ? 'O' : 'X';
                if (isGameOver(board) == 1) {
                    return i * SIZE + j;
                }
                board[i][j] = ' ';
            }
        }
    }

    // If the center is empty, take it
    if (board[1][1] == ' ') {
        return 4;
    }

    // Otherwise, take the first empty corner
    for (int i = 0; i < SIZE; i += 2) {
        for (int j = 0; j < SIZE; j += 2) {
            if (board[i][j] == ' ') {
                return i * SIZE + j;
            }
        }
    }

    // Otherwise, take the first empty side
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            if (board[i][j] == ' ') {
                return i * SIZE + j;
            }
        }
    }

    return -1;
}

// Main game loop
int main() {
    char board[SIZE][SIZE];
    int player = 'X';
    int gameOver = 0;

    initBoard(board);

    while (!gameOver) {
        if (player == 'X') {
            printf("Your move (row, column): ");
            int row, column;
            scanf("%d %d", &row, &column);
            if (board[row][column] != ' ') {
                printf("Invalid move, try again\n");
                continue;
            }
            board[row][column] = player;
        } else {
            int move = getBestMove(board, player);
            if (move == -1) {
                gameOver = 2;
                break;
            }
            board[move / SIZE][move % SIZE] = player;
        }

        printBoard(board);

        gameOver = isGameOver(board);

        if (gameOver == 1) {
            printf("%c wins!\n", player);
        } else if (gameOver == 2) {
            printf("Draw!\n");
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}