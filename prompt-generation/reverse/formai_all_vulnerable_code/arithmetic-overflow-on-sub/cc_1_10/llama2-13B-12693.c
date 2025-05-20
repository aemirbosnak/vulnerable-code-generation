//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERS 4
#define MAX_NAME_LEN 20

typedef struct player {
    char name[MAX_NAME_LEN];
    int score;
} player_t;

player_t players[PLAYERS];

void init_players(void);
void play_game(void);
void display_score(void);

int main(void) {
    init_players();
    play_game();
    display_score();
    return 0;
}

void init_players(void) {
    int i;
    for (i = 0; i < PLAYERS; i++) {
        players[i].score = 0;
        printf("Player %d, enter your name: ", i + 1);
        fgets(players[i].name, MAX_NAME_LEN, stdin);
    }
}

void play_game(void) {
    int player_choice;
    int computer_choice;

    do {
        player_choice = getchar() - '0';
        computer_choice = getchar() - '0';

        if (player_choice == computer_choice) {
            printf("Tie!\n");
        } else if (player_choice == 0) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        display_score();
    } while (1);
}

void display_score(void) {
    int i;
    for (i = 0; i < PLAYERS; i++) {
        printf("Player %d: %d\n", i + 1, players[i].score);
    }
}