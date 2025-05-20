//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define NUM_BALLS 75

int main() {
    srand(time(NULL));
    int bingo_cards[NUM_ROWS][NUM_COLS];
    int called_balls[NUM_BALLS];
    int num_players = 0;
    int num_winners = 0;
    int current_ball = 1;
    int i, j, k;

    printf("Welcome to Bingo Simulator!\n");
    printf("How many players do you have? ");
    scanf("%d", &num_players);

    // Initialize bingo cards
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            bingo_cards[i][j] = rand() % 15 + 1;
        }
    }

    // Print bingo cards
    printf("\nBingo Cards:\n");
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    // Call bingo balls
    for (i = 0; i < NUM_BALLS; i++) {
        called_balls[i] = rand() % 15 + 1;
        printf("\nBall %d: %d", current_ball++, called_balls[i]);

        // Check for winners
        for (j = 0; j < num_players; j++) {
            for (k = 0; k < NUM_ROWS; k++) {
                if (bingo_cards[k][j] == called_balls[i]) {
                    printf("\nPlayer %d wins!\n", j + 1);
                    num_winners++;
                    break;
                }
            }
            if (num_winners == num_players) {
                break;
            }
        }
    }

    if (num_winners < num_players) {
        printf("\nNo winners this round.\n");
    }

    return 0;
}