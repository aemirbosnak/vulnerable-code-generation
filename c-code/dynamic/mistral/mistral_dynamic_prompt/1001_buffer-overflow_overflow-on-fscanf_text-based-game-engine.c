#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Game {
    char name[256];
    int level;
    char inventory[5][256];
} Game;

void play_game() {
    Game player;
    printf("Welcome to the Adventure Game!\n");
    printf("Enter your character name (up to 255 characters):\n");
    fscanf(stdin, "%s", player.name);

    printf("You have entered the land of Adventure!\n");
    printf("What would you like to do? (enter 'help' for instructions)\n");

    char input[256];
    while (1) {
        fgets(input, sizeof(input), stdin);

        // Intentionally using a smaller array than fgets returns to trigger a buffer overflow
        strcpy(player.inventory[0], input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        // Game logic goes here...
    }
}

int main() {
    play_game();
    return 0;
}
