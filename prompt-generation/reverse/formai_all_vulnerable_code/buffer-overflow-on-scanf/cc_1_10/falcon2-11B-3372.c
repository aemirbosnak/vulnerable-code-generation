//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int cards[ROWS][COLS];
    int player_score = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cards[i][j] = rand() % 10;
        }
    }

    srand(time(NULL));

    printf("Welcome to the Memory Game!\n");
    printf("The cards are arranged in a %d x %d grid.\n", ROWS, COLS);
    printf("I will reveal a card. You have to guess which card matches it.\n");
    printf("Press 'r' to play again when you're done.\n");

    while (1) {
        int row, col;

        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (cards[i][j] == 0) {
                    printf("   ");
                } else {
                    printf("%d  ", cards[i][j]);
                }
            }
            printf("\n");
        }

        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);

        if (cards[row][col] == 0) {
            printf("Sorry, that's not the card I was thinking of.\n");
            player_score++;
            printf("Your score is now %d.\n", player_score);
        } else {
            printf("Congratulations, you guessed correctly!\n");
            player_score++;
            printf("Your score is now %d.\n", player_score);
        }

        printf("Press 'r' to play again when you're done.\n");
        scanf("%c", &cards[row][col]);
        if (cards[row][col] == 'r') {
            break;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}