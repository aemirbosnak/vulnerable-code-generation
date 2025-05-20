#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int health, level, experience;
} Character;

void print_character(Character *c) {
    printf("Name: %s\n", c->name);
    printf("Health: %d\n", c->health);
    printf("Level: %d\n", c->level);
    printf("Experience: %d\n", c->experience);
}

int main() {
    Character *player = (Character *) malloc(sizeof(Character));
    player->name = (char *) malloc(10 * sizeof(char));
    strcpy(player->name, "Player");
    player->health = 100;
    player->level = 1;
    player->experience = 0;

    Character *enemy = (Character *) malloc(sizeof(Character));
    enemy->name = NULL;

    while (1) {
        print_character(player);
        print_character(enemy);

        // Null pointer dereference intentionally added for vulnerability
        printf("Player's name is: %s\n", enemy->name);

        // Player's turn
        player->health -= 10;

        // Enemy's turn
        player->experience += 5;

        // Check for victory or defeat
        if (player->health <= 0) {
            printf("You have been defeated.\n");
            break;
        }
        if (player->experience >= 100) {
            player->level++;
            player->health += 20;
            player->experience = 0;
            printf("You have leveled up.\n");
        }
    }

    free(player->name);
    free(player);
    free(enemy);

    return 0;
}
