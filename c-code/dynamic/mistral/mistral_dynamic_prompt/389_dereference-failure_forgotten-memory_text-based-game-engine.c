#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entity {
    char name[50];
    int health;
    int armor;
} Entity;

void createEntity(Entity* entities, int entityIndex, const char* name) {
    entities[entityIndex].health = 100;
    entities[entityIndex].armor = 0;
    strcpy(entities[entityIndex].name, name);
}

void printEntity(const Entity* entity) {
    printf("Name: %s\n", entity->name);
    printf("Health: %d\n", entity->health);
    printf("Armor: %d\n", entity->armor);
}

void attackEntity(Entity* attacker, Entity* victim, int damage) {
    if (attacker->armor > 0) {
        attacker->armor--;
    } else {
        victim->health -= damage;
    }
}

int main() {
    Entity* player = malloc(sizeof(Entity));
    Entity* enemy = malloc(sizeof(Entity));

    createEntity(player, 0, "Player");
    createEntity(enemy, 1, "Goblin");

    while (player->health > 0 && enemy->health > 0) {
        printf("Player turn...\n");
        int damage = 20;
        attackEntity(player, enemy, damage);
        printEntity(enemy);

        if (enemy->health <= 0) break;

        printf("Goblin turn...\n");
        damage = 5;
        attackEntity(player, player, damage);
        printEntity(player);
    }

    if (player->health > 0) {
        printf("You defeated the Goblin!\n");
    } else {
        printf("Game Over! You died...\n");
    }

    free(player);
    free(enemy);

    return 0;
}
