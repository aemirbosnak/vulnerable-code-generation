//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define BINGO_NUMBERS 75
#define BINGO_CALLS 15

typedef struct {
    char name[20];
    int card[5][5];
    int score;
} Player;

void generate_card(Player *player) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            player->card[i][j] = rand() % BINGO_NUMBERS + 1;
        }
    }
}

void print_card(Player *player) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", player->card[i][j]);
        }
        printf("\n");
    }
}

void call_number(int num) {
    printf("Number called: %d\n", num);
}

int check_bingo(Player *player) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (player->card[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(0));
    Player players[MAX_PLAYERS];
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        printf("Enter player name: ");
        scanf("%s", players[i].name);
        generate_card(&players[i]);
        printf("Player %s's card:\n", players[i].name);
        print_card(&players[i]);
    }
    int num_calls = 0;
    while (num_calls < BINGO_CALLS) {
        int num = rand() % BINGO_NUMBERS + 1;
        call_number(num);
        for (int i = 0; i < num_players; i++) {
            if (check_bingo(&players[i])) {
                printf("Player %s wins!\n", players[i].name);
                return 0;
            }
        }
        num_calls++;
    }
    printf("No winner after %d calls.\n", BINGO_CALLS);
    return 0;
}