//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIN_WIDTH 80
#define WIN_HEIGHT 24

typedef struct {
    char name[20];
    int score;
} player_t;

player_t players[5];

void init_players(void);
void update_players(void);
void display_players(void);
void handle_input(void);

int main(void) {
    init_players();

    while (1) {
        update_players();
        display_players();
        handle_input();
    }

    return 0;
}

void init_players(void) {
    int i;

    for (i = 0; i < 5; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
    }
}

void update_players(void) {
    int i;

    for (i = 0; i < 5; i++) {
        if (players[i].score > 0) {
            players[i].score--;
        }
    }
}

void display_players(void) {
    int i;

    for (i = 0; i < 5; i++) {
        printf("Player %d: %s (%d)\n", i + 1, players[i].name, players[i].score);
    }
}

void handle_input(void) {
    int i;

    for (i = 0; i < 5; i++) {
        if (scanf("%d", &players[i].score) == 1) {
            break;
        }
    }
}