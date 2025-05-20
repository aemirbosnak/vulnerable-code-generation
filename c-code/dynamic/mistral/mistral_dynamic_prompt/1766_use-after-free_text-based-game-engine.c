#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char* inventory;
    int health;
} Character;

void addItemToInventory(Character* player, char* item) {
    if (player->inventory) {
        char* newInv = (char*)malloc(strlen(player->inventory) + strlen(item) + 2);
        strcpy(newInv, player->inventory);
        free(player->inventory);
        player->inventory = newInv;
        player->inventory[strlen(player->inventory) + strlen(item)] = ' ';
        strcat(player->inventory, item);
    } else {
        player->inventory = (char*)malloc(strlen(item) + 1);
        strcpy(player->inventory, item);
    }
}

int main() {
    Character* player = (Character*)malloc(sizeof(Character));
    strcpy(player->name, "Hero");
    player->health = 100;
    addItemToInventory(player, "Sword");
    addItemToInventory(player, "Armor");

    printf("Name: %s\n", player->name);
    printf("Inventory: %s\n", player->inventory);
    printf("Health: %d\n", player->health);

    free(player);

    Character* enemy = (Character*)malloc(sizeof(Character));
    strcpy(enemy->name, "Monster");
    enemy->health = 200;

    free(player); // Use after free

    int combatResult = (enemy->health - 20 < 0) ? 1 : 0;

    printf("Combat result: %d\n", combatResult);

    return 0;
}
