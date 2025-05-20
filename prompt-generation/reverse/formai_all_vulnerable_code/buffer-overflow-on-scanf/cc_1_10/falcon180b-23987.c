//Falcon-180B DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];

    // initialize board with random symbols
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'A' + rand() % 26;
        }
    }

    printBoard(board);

    // ask for player input
    char playerMove;
    printf("Enter your move (row and column separated by a space): ");
    scanf("%c %c", &playerMove, &playerMove);

    // check if player won
    int row = playerMove - 'A';
    int col = playerMove - 'A';

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (board[row][col] == 'X') {
            printf("You win!\n");
        } else {
            printf("You lose.\n");
        }
    } else {
        printf("Invalid move.\n");
    }

    return 0;
}