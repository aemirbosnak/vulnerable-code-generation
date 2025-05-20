#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_start() {
    char player_name[10];
    printf("Welcome to the Dungeon of Perilous Pixels!\n");
    printf("Enter your hero's name: ");
    gets(player_name);

    printf("\nCongratulations, %s! Your adventure begins now...\n", player_name);
}

int main() {
    game_start();
    printf("\nYou find yourself in a dark, damp cave.\n");
    printf("There are three paths before you.\n");
    printf("1. The left path leads to the room of the ancient dragon.\n");
    printf("2. The middle path leads to the chamber of the magical artifacts.\n");
    printf("3. The right path leads to the lair of the goblin king.\n");
    printf("Where will you go, brave adventurer? ");

    char choice;
    scanf("%c", &choice);

    if (choice == '1') {
        printf("You bravely face the ancient dragon, but it burns you to ashes.\n");
        printf("Game Over.");
    } else if (choice == '2') {
        printf("You explore the magical artifacts and uncover powerful enchantments.\n");
        printf("You have discovered the Amulet of Eternal Life!\n");
        printf("Congratulations, you have won the game!\n");
    } else if (choice == '3') {
        printf("You encounter the goblin king and his minions.\n");
        printf("You fight valiantly, but are ultimately defeated.\n");
        printf("Game Over.");
    } else {
        printf("Invalid choice. Try again.\n");
        main();
    }

    return 0;
}
