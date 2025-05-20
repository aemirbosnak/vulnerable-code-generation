#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void greet(char *name) {
    printf("Welcome to the Dungeon of Doom, %s! Your journey begins now.\n", name);
}

void get_inventory() {
    char inventory[10];
    printf("Your inventory:\n");
    printf("1. Sword of Destiny\n");
    printf("2. Shield of Valor\n");
    printf("3. Elixir of Healing\n");
    printf("4. Map of Dungeon\n");
    printf("5. Key to Treasure Chest\n");
    printf("6. Exit Inventory\n");
    printf("Enter the number of item you want to use or 'exit' to leave the inventory:\n");
    scanf("%s", inventory);

    if (strcmp(inventory, "1") == 0) {
        printf("You used the Sword of Destiny.\n");
    } else if (strcmp(inventory, "2") == 0) {
        printf("You used the Shield of Valor.\n");
    } else if (strcmp(inventory, "3") == 0) {
        printf("You used the Elixir of Healing.\n");
    } else if (strcmp(inventory, "4") == 0) {
        printf("You used the Map of Dungeon.\n");
    } else if (strcmp(inventory, "5") == 0) {
        printf("You used the Key to Treasure Chest.\n");
    } else if (strcmp(inventory, "6") != 0) {
        printf("Invalid input. Please try again.\n");
    }
}

int main() {
    char name[20];
    printf("Enter your hero's name:\n");
    scanf("%s", name);

    strcpy(name, "Overlord"); // Buffer overflow by overwriting the user-provided name

    greet(name);
    get_inventory();

    return 0;
}
