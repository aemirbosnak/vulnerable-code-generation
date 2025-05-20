#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void game_loop() {
    char player_name[10];
    printf("Welcome to the Dungeon of Doom!\n");
    printf("Please enter your character's name (up to 10 characters): ");
    fgets(player_name, sizeof(player_name), stdin);

    char inventory[5][20];
    printf("You have entered the dungeon with the following items:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s\n", inventory[i]);
    }

    int health = 100;
    int level = 1;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the dungeon\n");
        printf("2. Check inventory\n");
        printf("3. Quit the game\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Exploring the dungeon...\n");
                health -= 10;
                if (health <= 0) {
                    printf("You have died. Game over.\n");
                    return;
                }
                level++;
                printf("You have reached level %d.\n", level);
                break;
            case 2:
                printf("Your inventory:\n");
                for (int i = 0; i < 5; ++i) {
                    printf("%s\n", inventory[i]);
                }
                break;
            case 3:
                printf("Exiting the game...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    game_loop();
    return 0;
}
