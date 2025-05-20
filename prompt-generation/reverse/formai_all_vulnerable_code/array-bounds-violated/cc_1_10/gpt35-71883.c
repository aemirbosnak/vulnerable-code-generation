//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("Memory Game Board: \n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

void reveal_card(int row, int col, int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    revealed[row][col] = 1;
    print_board(board, revealed);
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0}; // 0 is unrevealed, 1 is revealed

    // fill board with random numbers
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }

    print_board(board, revealed);

    // game loop
    int num_revealed = 0;
    while(num_revealed < ROWS*COLS) {
        int row1, col1, row2, col2;

        // prompt user for first card
        printf("Enter the row and column of the first card to reveal: ");
        scanf("%d %d", &row1, &col1);

        reveal_card(row1, col1, board, revealed);

        // prompt user for second card
        printf("Enter the row and column of the second card to reveal: ");
        scanf("%d %d", &row2, &col2);

        reveal_card(row2, col2, board, revealed);

        // evaluate if the two cards match
        if (board[row1][col1] == board[row2][col2]) {
            printf("Matched! You get to keep these cards.\n");
            num_revealed += 2;
        } else {
            printf("Sorry, these cards don't match. Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    printf("Congratulations! You won the game!\n");

    return 0;
}