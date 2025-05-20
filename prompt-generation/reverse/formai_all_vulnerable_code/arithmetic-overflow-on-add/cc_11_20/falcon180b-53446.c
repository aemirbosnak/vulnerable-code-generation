//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 24

int main() {
    int bingo_cards[ROWS][COLS];
    int i, j, k;
    int num;
    int player_num;
    char play_again;

    srand(time(NULL));

    // Initialize bingo cards
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingo_cards[i][j] = rand() % 75 + 1;
        }
    }

    // Print bingo cards
    printf("Bingo Cards:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    // Main game loop
    while (1) {
        printf("\nRound %d:\n", k + 1);

        // Call numbers
        for (i = 0; i < TOTAL_NUMBERS; i++) {
            num = rand() % 75 + 1;
            printf("%2d ", num);

            // Check for bingo
            for (j = 0; j < ROWS; j++) {
                for (k = 0; k < COLS; k++) {
                    if (bingo_cards[j][k] == num) {
                        printf("\nBingo! Player %d wins!\n", j + 1);
                        return 0;
                    }
                }
            }
        }

        // Check for full house
        for (j = 0; j < ROWS; j++) {
            for (k = 0; k < COLS; k++) {
                if (bingo_cards[j][k]!= 0) {
                    printf("\nFull house! Player %d wins!\n", j + 1);
                    return 0;
                }
            }
        }

        // Ask player for input
        printf("\nDo you want to play again? (y/n): ");
        scanf("%c", &play_again);

        if (play_again == 'n') {
            break;
        }
    }

    return 0;
}