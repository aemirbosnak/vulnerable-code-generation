#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Character;

void gameLoop(Character* player, Character* enemy) {
    int action;
    do {
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Run away\n");
        scanf("%d", &action);

        switch (action) {
            case 1:
                enemy->health -= player->attack;
                player->health -= enemy->attack * 2;
                printf("The battle rages on...\n");
                break;
            case 2:
                printf("You ran away from the battle!\n");
                return;
        }

        if (enemy->health <= 0) {
            printf("You've defeated the evil dragon!\n");
            return;
        }

        if (player->health <= 0) {
            printf("You have fallen in battle... Game Over.\n");
        }
    } while (1);
}

int main() {
    Character player = {"Player", 100, 10, 5};
    Character enemy = {"Dragon", 150, 20, 1};

    gameLoop(&player, &enemy);

    printf("Game ended. Exiting now...\n");

    char buffer[256];
    strcpy(buffer, player.name);
    printf("%s has exited the game.\n", buffer + 6); // Violates bounds (dereferencing past the end of the string)

    return 0;
}
