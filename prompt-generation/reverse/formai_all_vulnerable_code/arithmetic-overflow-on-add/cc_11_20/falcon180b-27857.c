//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define NUM_BALLS 75

int main() {
    int bingo_cards[ROWS][COLS];
    int ball_drawn[NUM_BALLS];
    int i, j, k, num_players, player_won;
    char input;

    // Initialize random seed
    srand(time(NULL));

    // Fill bingo cards with random numbers
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingo_cards[i][j] = rand() % 75 + 1;
        }
    }

    // Print bingo cards
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    // Ask for number of players
    printf("\nEnter number of players: ");
    scanf("%d", &num_players);

    // Simulate bingo game
    while (1) {
        // Draw a ball
        ball_drawn[k] = rand() % 75 + 1;
        k++;

        // Check if any player has won
        for (i = 0; i < num_players; i++) {
            player_won = 1;
            for (j = 0; j < COLS; j++) {
                if (bingo_cards[i][j]!= ball_drawn[j]) {
                    player_won = 0;
                    break;
                }
            }
            if (player_won) {
                printf("\nPlayer %d has won!\n", i + 1);
                break;
            }
        }

        // Check if game is over
        if (k == NUM_BALLS) {
            printf("\nGame over.\n");
            break;
        }
    }

    return 0;
}