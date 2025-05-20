//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define MAX_CARDS 1000
    #define MAX_PLAYERS 10

    typedef struct {
        char name[20];
        int card[MAX_CARDS];
        int num_cards;
    } player_t;

    void init_card(char card[5]) {
        int i;
        for (i = 0; i < 5; i++) {
            card[i] = '0' + rand() % 15;
        }
    }

    void print_card(const char card[5]) {
        int i;
        for (i = 0; i < 5; i++) {
            printf("%c ", card[i]);
        }
        printf("\n");
    }

    void print_players(const player_t players[MAX_PLAYERS]) {
        int i;
        for (i = 0; i < MAX_PLAYERS; i++) {
            printf("Player %d: %s\n", i + 1, players[i].name);
        }
    }

    void draw_card(player_t *player) {
        init_card(player->card + player->num_cards);
        player->num_cards++;
    }

    int check_bingo(const player_t player) {
        int i, j, k, count;
        for (i = 0; i < 5; i++) {
            for (j = i + 1; j < 5; j++) {
                for (k = j + 1; k < 5; k++) {
                    if (player.card[i] == player.card[j] && player.card[j] == player.card[k]) {
                        count++;
                    }
                }
            }
        }
        if (count == 5) {
            return 1;
        }
        return 0;
    }

    int main(int argc, char *argv[]) {
        srand(time(NULL));
        player_t players[MAX_PLAYERS];
        int num_players, i;

        printf("Welcome to C Bingo Simulator!\n");
        printf("How many players will be playing? (1-10): ");
        scanf("%d", &num_players);

        for (i = 0; i < num_players; i++) {
            printf("Enter player %d's name: ", i + 1);
            scanf("%s", players[i].name);
        }

        int num_cards_drawn = 0;
        while (num_cards_drawn < 100) {
            int winner = 0;
            for (i = 0; i < num_players; i++) {
                if (check_bingo(players[i])) {
                    winner = i + 1;
                    break;
                }
            }

            if (winner == 0) {
                draw_card(&players[0]);
                num_cards_drawn++;
            } else {
                printf("Player %d wins!\n", winner);
                break;
            }
        }

        printf("Thanks for playing!\n");
        return 0;
    }