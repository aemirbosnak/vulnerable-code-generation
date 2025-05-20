//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBERS 75
#define BINGO_NUMBERS 5

int main() {
    int bingo_cards[ROWS][COLS];
    int numbers[MAX_NUMBERS];
    int i, j, k, num, count = 0;
    int player_won = 0;
    char input[2];

    srand(time(NULL));

    // Fill the bingo cards with random numbers
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % MAX_NUMBERS + 1;
            bingo_cards[i][j] = num;
        }
    }

    // Print the bingo cards
    printf("Bingo Cards:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    // Generate random bingo numbers
    for (k = 0; k < BINGO_NUMBERS; k++) {
        num = rand() % MAX_NUMBERS + 1;
        while (num == 0 || num > MAX_NUMBERS) {
            num = rand() % MAX_NUMBERS + 1;
        }
        numbers[k] = num;
        printf("%d ", numbers[k]);
    }
    printf("\n");

    // Check for player win
    while (player_won == 0) {
        printf("Enter your choice (row and column): ");
        scanf("%d%d", &i, &j);
        if (bingo_cards[i-1][j-1] == numbers[k]) {
            printf("You won!\n");
            player_won = 1;
        }
        else {
            printf("Try again.\n");
        }
    }

    return 0;
}