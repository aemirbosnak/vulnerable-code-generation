//FormAI DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int main()
{
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE];
    int row1, row2, col1, col2, i, j, count = 0;

    srand(time(NULL));

    // initialize board and revealed arrays
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 10;
            revealed[i][j] = 0;
        }
    }

    printf("Welcome to Memory Game!\n");

    // game loop
    while (1) {
        printf("\nMemory Board:\n");

        // print board
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (revealed[i][j]) {
                    printf("%d ", board[i][j]);
                } else {
                    printf("* ");
                }
            }
            printf("\n");
        }

        // prompt user for first card
        printf("\nSelect first card (row column): ");
        scanf("%d %d", &row1, &col1);

        // reveal first card
        revealed[row1][col1] = 1;

        // prompt user for second card
        printf("Select second card (row column): ");
        scanf("%d %d", &row2, &col2);

        // reveal second card
        revealed[row2][col2] = 1;

        // check if cards match
        if (board[row1][col1] == board[row2][col2]) {
            printf("Match!\n");
            count++;
            // check if game is over
            if (count == SIZE * SIZE / 2) {
                printf("Congratulations, you won!\n");
                return 0;
            }
        } else {
            printf("No match.\n");
            // hide cards
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    return 0;
}