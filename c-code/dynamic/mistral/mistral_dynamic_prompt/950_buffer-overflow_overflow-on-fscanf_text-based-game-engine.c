#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game() {
    char buffer[10];
    int score = 0;

    printf("Welcome to the Mysterious Dungeon!\n");
    printf("Enter your character name (up to 9 characters):\n");

    fscanf(stdin, "%s", buffer);
    strcat(buffer, " the Brave");
    strcat(buffer, "\n");

    printf("Hello, %s!\n", buffer);
    printf("Let's embark on your adventure...\n");

    printf("You encounter a fierce monster.\n");
    printf("Enter your attack strength (0-9):\n");
    int attack;
    fscanf(stdin, "%d", &attack);

    int monsterStrength = rand() % 10 + 1;
    printf("You attack with a force of %d.\n", attack);
    printf("The monster retaliates with a force of %d.\n", monsterStrength);

    if (attack > monsterStrength) {
        printf("You defeat the monster!\n");
        score++;
    } else {
        printf("The monster defeats you.\n");
    }

    printf("Your score: %d\n", score);

    char input[10];
    printf("Press enter to continue or type 'quit' to exit the game.\n");
    fgets(input, sizeof(input), stdin);

    if (strcmp(input, "quit\n") == 0) {
        printf("Goodbye!\n");
    } else {
        game();
    }
}

int main() {
    game();
    return 0;
}
