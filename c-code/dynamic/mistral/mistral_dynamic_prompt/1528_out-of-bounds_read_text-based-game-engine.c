#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

const int MAX_PLAYERS = 10;
const int MAX_NAME_LENGTH = 20;

void game() {
    char players[MAX_PLAYERS][MAX_NAME_LENGTH];
    int num_players = 0;

    printf("Text-based Game Engine\n\n");

    while (num_players < MAX_PLAYERS && num_players >= 0) {
        printf("Enter player %d's name (or 0 to quit): ", num_players + 1);
        scanf("%s", players[num_players]);

        num_players++;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i + 1, players[i]);
    }
}

int main() {
    game();

    printf("\nGame Over\n\n");

    return 0;
}
