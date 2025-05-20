//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 75

int main() {
    srand(time(NULL));
    int bingo_cards[MAX_ROWS][MAX_COLS];
    int player_cards[MAX_ROWS][MAX_COLS];
    int called_numbers[MAX_NUMBERS];
    int num_players, i, j, k, bingo;

    printf("Welcome to the wacky world of C Bingo Simulator!\n");
    printf("How many players will be joining the fun today? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Player %d, please enter your name: ", i + 1);
        scanf("%s", &player_cards[i][0]);
    }

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            bingo_cards[i][j] = rand() % 15 + 1;
            player_cards[i][j] = rand() % 15 + 1;
        }
    }

    printf("\nLet's play some bingo!\n");
    for (k = 0; k < MAX_NUMBERS; k++) {
        called_numbers[k] = rand() % 15 + 1;
        printf("%d ", called_numbers[k]);
        for (i = 0; i < num_players; i++) {
            for (j = 0; j < MAX_ROWS; j++) {
                if (player_cards[i][j] == called_numbers[k]) {
                    player_cards[i][j] = -1;
                }
            }
            for (j = 0; j < MAX_COLS; j++) {
                if (player_cards[i][j] == -1) {
                    bingo = 1;
                    break;
                }
            }
            if (bingo) {
                break;
            }
        }
        if (bingo) {
            printf("\nPlayer %d wins! Congrats %s!\n", i + 1, &player_cards[i][0]);
            break;
        }
    }

    return 0;
}