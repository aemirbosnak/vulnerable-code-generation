#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Game {
    char *player_name;
    int health;
    char *inventory[5];
} Game;

void game_start() {
    Game *game = malloc(sizeof(Game));
    game->player_name = "Anonymous";
    game->health = 100;

    game->inventory[0] = "Sword";
    game->inventory[1] = "Armor";
    game->inventory[2] = "Shield";
    game->inventory[3] = "Elixir";
    game->inventory[4] = "Key";

    printf("Welcome to the Epic Quest!\n");
    printf("You are %s, the adventurer.\n", game->player_name);
    printf("Your starting health is %d.\n", game->health);

    printf("Your current inventory:\n");
    for (int i = 0; i < 5; ++i) {
        if (game->inventory[i])
            printf("%s\n", game->inventory[i]);
    }

    // Gameplay...

    // Dereference failure example
    printf("You decide to use the %s\n", game->inventory[5]); // This line should cause the segmentation fault
}

int main() {
    game_start();
    return 0;
}
