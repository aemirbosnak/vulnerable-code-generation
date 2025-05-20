//Gemma-7B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char board[6][6] = {
        {'S', 'O', 'R', 'A', 'R', 'D'},
        {'A', 'R', 'T', 'A', 'C', 'H'},
        {'R', 'E', 'B', 'O', 'T', 'M'},
        {'D', 'S', 'A', 'R', 'E', 'C'},
        {'R', 'A', 'T', 'E', 'O', 'P'},
        {'A', 'C', 'H', 'R', 'T', 'S'}
    };

    // Draw the board
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    // Get the player's move
    int row, column;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &column);

    // Check if the move is valid
    if (row < 0 || row >= 6) {
        printf("Invalid row.\n");
    } else if (column < 0 || column >= 6) {
        printf("Invalid column.\n");
    } else if (board[row][column] != 'S') {
        printf("Invalid move.\n");
    }

    // Make the move
    board[row][column] = 'O';

    // Draw the board again
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    // Check if the player has won
    if (board[0][0] == 'O' || board[0][1] == 'O' || board[0][2] == 'O' ||
        board[1][0] == 'O' || board[1][1] == 'O' || board[1][2] == 'O' ||
        board[2][0] == 'O' || board[2][1] == 'O' || board[2][2] == 'O' ||
        board[3][0] == 'O' || board[3][1] == 'O' || board[3][2] == 'O' ||
        board[4][0] == 'O' || board[4][1] == 'O' || board[4][2] == 'O' ||
        board[5][0] == 'O' || board[5][1] == 'O' || board[5][2] == 'O') {
        printf("You have won!\n");
    } else {
        printf("It is a draw.\n");
    }

    return 0;
}