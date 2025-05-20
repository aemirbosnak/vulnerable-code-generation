#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void game() {
    char path[1];
    char choice[10];

    printf("Welcome to the Dungeon of Doom!\n");
    printf("Do you go left (L) or right (R)? ");
    scanf("%s", path);

    if (strcmp(path, "L") == 0) {
        printf("You found a treasure chest! Game over.\n");
    } else if (strcmp(path, "R") == 0) {
        printf("You encounter a monster! Game over.\n");
    } else {
        printf("Invalid input. Game over.\n");
    }

    printf("Do you want to play again? (y/n) ");
    scanf("%s", choice);

    if (strcmp(choice, "y") == 0) {
        game();
    }
}

int main() {
    game();
    return 0;
}
