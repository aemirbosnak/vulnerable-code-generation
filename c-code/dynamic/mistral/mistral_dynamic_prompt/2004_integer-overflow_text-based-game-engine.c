#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Game {
    char name[256];
    int level;
    int lives;
} Game;

void welcome() {
    printf("Welcome to 'The Quest for the Hallowed Artifact'! Press 'n' to start a new game or 'q' to quit.\n");
}

void new_game(Game *player) {
    strcpy(player->name, "Anonymous Adventurer");
    player->level = 1;
    player->lives = 3;
}

void game_over(Game *player) {
    printf("Game over! Final score: Level %d, Lives %d\n", player->level, player->lives);
}

void level_complete(Game *player) {
    printf("Congratulations! You've completed Level %d!\n", player->level);
    player->level++;
    player->lives = 3;
}

int main() {
    char option;
    Game player;

    welcome();

    while ((option = getchar()) != 'q') {
        if (option == 'n') {
            new_game(&player);
            int i;
            for (i = 0; i < 10000000; i++) {
                player.level++;
            }
            level_complete(&player);
        }
        game_over(&player);
    }

    return 0;
}
