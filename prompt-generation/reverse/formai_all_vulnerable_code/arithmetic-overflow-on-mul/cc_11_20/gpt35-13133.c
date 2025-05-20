//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5  // number of rows on the bingo card
#define COLUMNS 5  // number of columns on the bingo card

int main() {
    int player_count, num_players, max_calls, current_call;
    char bingo_card[ROWS][COLUMNS];
    int numbers_called[75] = {0};
    int row_bingo[ROWS] = {0};
    int column_bingo[COLUMNS] = {0};
    int diagonal_bingo[2] = {0};

    // Ask user for number of players
    printf("How many players will be playing?\n");
    scanf("%d", &num_players);

    // Create bingo cards for each player
    for (player_count = 1; player_count <= num_players; player_count++) {
        printf("\nBingo card for player %d:\n", player_count);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (i == 2 && j == 2) {
                    bingo_card[i][j] = 'X';  // center space is already filled in
                } else {
                    bingo_card[i][j] = '0' + (rand() % 9) + 1;  // fill in other spaces with random numbers
                }
                printf("%c ", bingo_card[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Set max number of calls
    max_calls = ROWS * COLUMNS * num_players;

    // Randomly draw numbers and check them off the cards
    srand(time(0));
    current_call = 1;
    while (current_call <= max_calls) {
        int num_drawn = (rand() % 75) + 1;
        if (numbers_called[num_drawn-1] == 0) {
            printf("Calling number %d...\n", num_drawn);
            numbers_called[num_drawn-1] = 1;
            // Check if number appears on any of the cards and mark it off if it does
            for (int i = 0; i < num_players; i++) {
                for (int j = 0; j < ROWS; j++) {
                    for (int k = 0; k < COLUMNS; k++) {
                        if (bingo_card[j][k] == '0' + num_drawn) {
                            bingo_card[j][k] = 'X';
                            printf("Player %d marked off %d on their card!\n", i+1, num_drawn);
                            // Check if any bingo patterns have been completed
                            if (++row_bingo[j] == ROWS) {
                                printf("Player %d has a BINGO in row %d!\n", i+1, j+1);
                                exit(0);
                            }
                            if (++column_bingo[k] == COLUMNS) {
                                printf("Player %d has a BINGO in column %d!\n", i+1, k+1);
                                exit(0);
                            }
                            if (j == k && ++diagonal_bingo[0] == ROWS) {
                                printf("Player %d has a BINGO on the diagonal!\n", i+1);
                                exit(0);
                            }
                            if (j + k == ROWS - 1 && ++diagonal_bingo[1] == ROWS) {
                                printf("Player %d has a BINGO on the opposite diagonal!\n", i+1);
                                exit(0);
                            }
                        }
                    }
                }
            }
            current_call++;
        }
    }

    // If all calls have been made without a winner, the game ends in a tie
    printf("All calls have been made. The game is a tie!\n");
    return 0;
}