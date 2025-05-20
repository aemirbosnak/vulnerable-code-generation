#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_INPUT 100

void game() {
    char name[MAX_INPUT];
    printf("Welcome to the Dungeon of Doom! Enter your character name (up to 100 characters):\n");
    gets(name);

    // Game logic here
    // ...
}

int main() {
    char menu[] = "Welcome to Dungeon of Doom!\n\n"
                  "1. New Game\n"
                  "2. Load Game\n"
                  "3. Quit\n\n"
                  "Choose an option: ";

    char choice[2];
    printf("%s", menu);
    gets(choice);

    int option = atoi(choice);

    switch(option) {
        case 1:
            game();
            break;
        case 2:
            // Load game logic
            // ...
            break;
        case 3:
            printf("Thanks for playing Dungeon of Doom!\n");
            return 0;
        default:
            printf("Invalid option. Try again.\n");
    }

    return 0;
}
