//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
int player = 0; // 0 for X, 1 for O
int winningCombinations[8][3] = { {0, 1, 2}, {0, 3, 6}, {0, 4, 8}, {1, 4, 7}, {2, 4, 6}, {3, 4, 5}, {0, 3, 6}, {0, 1, 2} };
int winningCount = 0;

void printBoard() {
    printf("X | O | X\n");
    printf("---+---+---\n");
    printf("O | X | O\n");
    printf("---+---+---\n");
    printf("X | O | X\n");
}

void move(int row, int col) {
    board[row][col] = player;
    player = (player == 0)? 1 : 0; // Switch player
    winningCount = 0; // Reset winning count
}

int isWinningMove(int row, int col) {
    int i;
    for (i = 0; i < 8; i++) {
        if (board[row][col] == board[winningCombinations[i][0]][winningCombinations[i][1]] &&
            board[row][col] == board[winningCombinations[i][0]][winningCombinations[i][2]]) {
            winningCount++; // Update winning count
            return 1; // Winning move
        }
    }
    return 0; // Not a winning move
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int choice, row, col;

    do {
        printBoard();
        printf("Player %d, make your move (row col): ", player == 0? 1 : 2);
        scanf("%d %d", &row, &col);
        move(row, col);
    } while (isWinningMove(row, col));

    if (winningCount > 0) {
        printf("Player %d wins!\n", player);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}