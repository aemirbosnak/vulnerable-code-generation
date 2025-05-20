//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_players;
    int bingo_cards[10][5];
    int player_cards[10][5];
    int called_nums[75];
    int i, j, k, l;
    int player_won;
    int game_over;
    int num_called;

    srand(time(NULL));

    printf("Welcome to the Alan Turing style Bingo Simulator!\n");
    printf("How many players will be playing? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            bingo_cards[i][j] = rand() % 15 + 1;
            player_cards[i][j] = bingo_cards[i][j];
        }
    }

    printf("\n");
    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", player_cards[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 75; i++) {
        called_nums[i] = 0;
    }

    game_over = 0;
    while (!game_over) {
        num_called = 0;
        for (i = 0; i < 75; i++) {
            if (called_nums[i] == 0) {
                called_nums[i] = 1;
                printf("%d has been called.\n", i+1);
                num_called++;
            }
        }

        if (num_called == 0) {
            game_over = 1;
        }

        for (i = 0; i < num_players; i++) {
            player_won = 1;
            for (j = 0; j < 5; j++) {
                for (k = 0; k < 5; k++) {
                    if (player_cards[i][j] == called_nums[k]) {
                        player_cards[i][j] = 0;
                    }
                }
            }
            for (j = 0; j < 5; j++) {
                if (player_cards[i][j]!= 0) {
                    player_won = 0;
                    break;
                }
            }

            if (player_won == 1) {
                printf("Player %d has won!\n", i+1);
                game_over = 1;
            }
        }
    }

    return 0;
}