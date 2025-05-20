//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5
#define NUM_CARDS (ROWS * COLS)

int main() {
    int board[ROWS][COLS] = {0};
    int matches = 0;
    int attempts = 0;
    int score = 0;
    int i, j, k;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    while (matches < NUM_CARDS) {
        attempts++;

        printf("\nAttempt %d:\n", attempts);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        printf("Enter two indices (row, column): ");
        scanf("%d %d", &k, &k);
        i = k / COLS;
        j = k % COLS;

        if (board[i][j] == board[i][j + 1]) {
            matches++;
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
            board[i][j] = -1;
            board[i][j + 1] = -1;
        }
    }

    score = NUM_CARDS - attempts;
    printf("\nGame over! You made %d attempts and scored %d points.\n", attempts, score);

    return 0;
}