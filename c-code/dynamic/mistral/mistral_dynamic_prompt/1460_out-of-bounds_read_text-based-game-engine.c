#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game() {
    char player[10];
    char enemies[5][20] = { "Goblin", "Orc", "Troll", "Dragon", "Demon Lord" };
    int health = 100;
    int enemy_index = rand() % 5;

    strcpy(player, "Hero");

    printf("Welcome to the Dungeon Crawler, %s!\n", player);
    printf("You've encountered an %s!\n", enemies[enemy_index]);
    printf("Your current health is %d.\n", health);

    char input[10];
    printf("Enter your attack: ");
    scanf("%s", input);

    // Out of bounds read example, reading past the enemies array
    printf("The enemy thinks: %c\n", enemies[enemy_index + 10]);

    health -= 10;
    printf("Your health is now %d.\n", health);

    if (health <= 0) {
        printf("Game over, you have been defeated by the %s.\n", enemies[enemy_index]);
    } else {
        printf("Attack successful!\n");
        health += 20;
        printf("Your health is now %d.\n", health);
    }
}

int main() {
    game();
    return 0;
}
