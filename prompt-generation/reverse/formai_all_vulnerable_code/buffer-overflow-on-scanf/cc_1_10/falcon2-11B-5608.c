//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to print the Tic Tac Toe board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", (board[i][j] == 1)? 'X' : 'O');
        }
        printf("\n");
    }
}

// Function to check if the game is over
bool isGameOver(int board[3][3], char player) {
    // Check for a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0) {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move
void makeMove(int board[3][3], char player, int move) {
    if (isGameOver(board, player)) {
        printf("Game Over!\n");
        return;
    }
    board[move / 3][move % 3] = player;
    printf("Player %c made a move at (%d, %d)\n", player, move / 3 + 1, move % 3 + 1);
    printBoard(board);
}

// Main function
int main() {
    // Initialize the board
    int board[3][3] = {0, 0, 0,
                        0, 0, 0,
                        0, 0, 0};

    // Randomly choose the first player
    srand(time(0));
    char player = 'X';

    // Play the game until the end
    while (!isGameOver(board, player)) {
        int move;
        printf("Player %c's turn. Enter a move (1-9): ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9) {
            makeMove(board, player, move);
        } else {
            printf("Invalid move. Try again.\n");
        }
        player = (player == 'X')? 'O' : 'X';
    }

    printf("Game Over!\n");
    return 0;
}