#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_init() {
    char game_data[10];
    printf("Welcome to Secret Dungeon!\nEnter your name (max 10 chars): ");
    fscanf(stdin, "%s", game_data);
}

void game_loop() {
    printf("\nYou enter the dungeon...\n");
    // Add your game logic here...
}

int main() {
    game_init();
    game_loop();
    return 0;
}
