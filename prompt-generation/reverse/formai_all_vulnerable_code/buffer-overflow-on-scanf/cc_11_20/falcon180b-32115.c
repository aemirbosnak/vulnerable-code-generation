//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 75

int main() {
    int bingo_cards[MAX_ROWS][MAX_COLS];
    int called_numbers[MAX_NUMBERS];
    int num_players, i, j, k, m, n, match;
    int player_wins[MAX_ROWS][MAX_COLS];
    int player_scores[MAX_ROWS][MAX_COLS];
    int current_score;
    char player_names[MAX_ROWS][20];
    int valid_input;
    int player_choice;
    int random_number;
    int num_called_numbers;
    int bingo_found;
    time_t start_time, end_time;
    double elapsed_time;

    srand(time(NULL));

    // Initialize bingo cards
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            bingo_cards[i][j] = rand() % 75 + 1;
        }
    }

    // Get number of players
    printf("How many players are there? ");
    scanf("%d", &num_players);

    // Get player names
    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", player_names[i]);
    }

    // Shuffle called numbers
    for (i = 0; i < MAX_NUMBERS; i++) {
        called_numbers[i] = rand() % 75 + 1;
    }

    // Start game
    start_time = time(NULL);
    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("Called number %d: %d\n", i + 1, called_numbers[i]);

        // Check for matches
        for (j = 0; j < num_players; j++) {
            for (k = 0; k < MAX_ROWS; k++) {
                for (m = 0; m < MAX_COLS; m++) {
                    if (bingo_cards[k][m] == called_numbers[i]) {
                        player_wins[j][k * MAX_COLS + m] = 1;
                    }
                }
            }
        }

        // Check for bingos
        for (j = 0; j < num_players; j++) {
            match = 0;
            for (k = 0; k < MAX_ROWS; k++) {
                for (m = 0; m < MAX_COLS; m++) {
                    if (player_wins[j][k * MAX_COLS + m] == 1) {
                        match++;
                    }
                }
            }

            if (match == 5) {
                printf("Player %s wins!\n", player_names[j]);
                break;
            }
        }

        if (i == MAX_NUMBERS - 1) {
            printf("No one wins.\n");
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Game over. Elapsed time: %.2lf seconds.\n", elapsed_time);

    return 0;
}