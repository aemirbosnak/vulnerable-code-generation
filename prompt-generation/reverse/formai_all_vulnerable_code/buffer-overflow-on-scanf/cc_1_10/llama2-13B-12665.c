//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct {
    char name[50];
    int score;
} player_t;

player_t players[5];

void init_players(void) {
    int i;
    for (i = 0; i < 5; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
    }
}

void add_player(char *name) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(players[i].name, name) == 0) {
            break;
        }
    }
    if (i == 5) {
        printf("Error: too many players!\n");
        return;
    }
    strcpy(players[i].name, name);
    players[i].score = 0;
}

void update_score(int score) {
    int i;
    for (i = 0; i < 5; i++) {
        if (players[i].name[0] != '\0') {
            players[i].score += score;
            break;
        }
    }
}

void draw_game(void) {
    int i;
    for (i = 0; i < 5; i++) {
        if (players[i].name[0] != '\0') {
            printf("%d. %s (%d points)\n", i + 1, players[i].name, players[i].score);
        }
    }
}

void handle_input(void) {
    char input[100];
    int score;

    printf("Enter your name: ");
    fgets(input, 100, stdin);
    add_player(input);

    printf("Enter your score: ");
    scanf("%d", &score);
    update_score(score);

    draw_game();
}

int main(void) {
    srand(time(NULL));

    init_players();

    while (1) {
        handle_input();
    }

    return 0;
}