//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8
#define MATCH_POINTS 10
#define MISMATCH_POINTS -5

int main() {
    int board[ROWS][COLS];
    int matches = 0;
    int mismatches = 0;
    int points = 0;
    int choice;
    int card1, card2;
    int flag = 0;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % TOTAL_CARDS + 1;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }

    while (flag == 0) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= TOTAL_CARDS) {
            flag = 1;
        } else {
            printf("Invalid choice.\n");
        }
    }

    card1 = choice;
    flag = 0;
    while (flag == 0) {
        printf("\nFlip card 1: ");
        scanf("%d", &choice);

        if (choice == card1) {
            flag = 1;
        } else {
            printf("Mismatch!\n");
            mismatches++;
        }
    }

    flag = 0;
    while (flag == 0) {
        printf("\nFlip card 2: ");
        scanf("%d", &choice);

        if (choice == card1) {
            flag = 1;
            matches++;
            points += MATCH_POINTS;
        } else {
            printf("Mismatch!\n");
            mismatches++;
        }
    }

    if (matches == TOTAL_CARDS / 2) {
        printf("\nCongratulations! You won the game with %d points.\n", points);
    } else {
        printf("\nSorry, you lost the game with %d points.\n", points);
    }

    return 0;
}