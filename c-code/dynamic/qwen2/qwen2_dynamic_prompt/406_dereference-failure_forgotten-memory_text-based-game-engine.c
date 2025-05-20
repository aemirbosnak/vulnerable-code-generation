#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char *name;
} Character;

void attack(Character *attacker, Character *defender) {
    if (defender != NULL) {
        defender->health -= 10;
        printf("%s attacks %s! %s now has %d health.\n", attacker->name, defender->name, defender->name, defender->health);
    } else {
        printf("No target to attack!\n");
    }
}

int main() {
    Character player = {100, "Hero"};
    Character *enemy = NULL;

    printf("Welcome to the Text-Based Game Engine!\n");

    while (player.health > 0 && enemy == NULL) {
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Heal\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack(&player, enemy);
                break;
            case 2:
                player.health += 20;
                printf("%s heals! Now has %d health.\n", player.name, player.health);
                break;
            case 3:
                printf("Quitting game...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    if (player.health <= 0) {
        printf("Game Over! You have been defeated.\n");
    } else {
        printf("Congratulations! You have won the game!\n");
    }

    free(enemy); // This line will cause a segmentation fault because enemy is not allocated

    return 0;
}
