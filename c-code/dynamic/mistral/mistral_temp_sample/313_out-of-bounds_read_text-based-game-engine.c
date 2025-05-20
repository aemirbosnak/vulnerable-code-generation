#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void game() {
    char buffer[1];
    printf("\nWelcome to the Dungeon of Peril!\n");
    printf("Enter your name to start the game: ");
    fgets(buffer, sizeof(buffer), stdin);

    char name[256];
    strcpy(name, buffer);

    printf("Hello, %s! You enter a dimly lit dungeon filled with traps and treasure.\n", name);
    printf("Type 'go north' to continue.\n");

    char command[256];
    while (1) {
        fgets(command, sizeof(command), stdin);
        if (strstr(command, "go north") != NULL) {
            printf("You cautiously step forward, the air grows colder.\n");
            printf("Suddenly, a pit opens beneath you!\n");
            printf("You fall into the abyss... Game Over!\n");
            return;
        }
    }
}

int main() {
    game();
    return 0;
}
