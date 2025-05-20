//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_players = 0;
    int player_cards[5][5];
    int game_cards[5][5];
    int player_wins[5];
    int num_wins;
    int winner;
    int i, j, k, l, m;
    int player_choice;
    int card_value;
    int card_suit;
    char player_name[20];

    srand(time(NULL));

    printf("Welcome to BINGO!\n");
    printf("How many players will be playing? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", player_name);
        printf("Player %s, please choose your cards:\n", player_name);
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                card_value = rand() % 15 + 1;
                card_suit = rand() % 4 + 1;
                player_cards[i][j*5+k] = card_value*16 + card_suit;
            }
        }
    }

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                game_cards[j][k] = player_cards[i][j*5+k];
            }
        }
    }

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (game_cards[j][k]!= 0) {
                    for (l = 0; l < num_players; l++) {
                        for (m = 0; m < 5; m++) {
                            if (player_cards[l][m] == game_cards[j][k]) {
                                player_wins[l]++;
                            }
                        }
                    }
                }
            }
        }
    }

    num_wins = 0;
    for (i = 0; i < num_players; i++) {
        if (player_wins[i] == 25) {
            num_wins++;
        }
    }

    if (num_wins == 0) {
        printf("No winner.\n");
    } else if (num_wins == 1) {
        printf("Player %s wins!\n", player_name);
    } else {
        printf("Tie between %d players.\n", num_wins);
    }

    return 0;
}