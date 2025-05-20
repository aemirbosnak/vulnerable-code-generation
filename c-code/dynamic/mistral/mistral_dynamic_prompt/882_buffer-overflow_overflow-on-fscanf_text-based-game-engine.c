#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void welcome() {
    printf("\nWelcome to the Perilous Crypt!\n");
    printf("A game of adventure and danger!\n\n");
}

void game_loop() {
    char input[10];
    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);
    char command[3] = { input[0], input[1], '\0' };

    if (strcmp(command, "st") == 0) {
        start_game();
    } else if (strcmp(command, "ex") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

void start_game() {
    char name[256];
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);

    char level[8];
    printf("Choose your level: ");
    fgets(level, sizeof(level), stdin);

    char* attacker = "AAAAAAAAAAAAAAAAAAAAAAAAAA";
    strcat(name, attacker); // overflow

    printf("Welcome, %s! Good luck on your journey through the Perilous Crypt.\n", name);

    game_loop();
}

int main() {
    welcome();
    game_loop();
    return 0;
}
