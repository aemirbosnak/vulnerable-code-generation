#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_init() {
    char game_data[10];
    printf("Welcome to the Game of Bounds!\n");
    printf("Enter your name (10 characters max):\n");
    gets(game_data);
    printf("Hello, %s! Let's start the game.\n", game_data);
}

int main() {
    game_init();
    printf("You have entered a labyrinth filled with traps and treasures.\n");
    printf("Your mission is to find the hidden treasure while avoiding the traps.\n");
    printf("Good luck!\n");

    char input[256];
    while (1) {
        printf("> ");
        gets(input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        // Add game logic here
    }

    printf("Thanks for playing! See you next time.\n");
    return 0;
}
