//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    char board[MAX_ROWS][MAX_COLS] = {'\0'};

    printf("Welcome to the C Table Game!\n");
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Board dimensions are too large.\n");
        return 1;
    }

    printf("Please enter the initial board layout:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    int player = 1;
    int moves = 0;
    while (moves < rows * cols) {
        printf("\nPlayer %d's turn:\n", player);
        printf("Board:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        char move;
        printf("Please enter your move (row and column): ");
        scanf(" %c %c", &move, &move);
        int row = move - '0';
        int col = move - '0';

        if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == '\0') {
            board[row][col] = (player % 2 == 0)? 'X' : 'O';
            moves++;
            player++;
        } else {
            printf("Invalid move.\n");
        }
    }

    printf("\nGame over! Player %d wins!\n", (player % 2) + 1);

    return 0;
}