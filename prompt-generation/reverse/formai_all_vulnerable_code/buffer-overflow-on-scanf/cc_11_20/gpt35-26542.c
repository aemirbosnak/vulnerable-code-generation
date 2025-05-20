//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NAME_LEN 20
#define MAX_ITEMS 10
#define MAX_ITEM_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char inventory[MAX_ITEMS][MAX_ITEM_LEN];
    int num_items;
} Character;

int main() {
    Character player;
    player.num_items = 0;

    // Initial message
    printf("Welcome to Medieval Inventory Manager.\n");
    printf("You are a peasant living in a small village in medieval times.\n");
    printf("You must manage your inventory to survive in this harsh world.\n");

    // Game loop
    int running = 1;
    while (running) {
        // Print menu
        printf("\nCurrent inventory for %s:\n", player.name);
        for (int i = 0; i < player.num_items; i++) {
            printf("- %s\n", player.inventory[i]);
        }
        printf("\nWhat would you like to do?\n");
        printf("1. Add an item to inventory\n");
        printf("2. Remove an item from inventory\n");
        printf("3. Quit the game\n");

        // Get choice from user
        int choice;
        scanf("%d", &choice);
        printf("\n");

        // Handle choice
        switch (choice) {
            case 1:
                if (player.num_items >= MAX_ITEMS) {
                    printf("You cannot carry any more items.\n");
                } else {
                    printf("What item would you like to add?\n");
                    char item[MAX_ITEM_LEN];
                    scanf("%s", item);
                    strncpy(player.inventory[player.num_items], item, MAX_ITEM_LEN);
                    player.num_items++;
                }
                break;
            case 2:
                if (player.num_items == 0) {
                    printf("Your inventory is empty.\n");
                } else {
                    printf("Which item would you like to remove?\n");
                    int item_index;
                    scanf("%d", &item_index);
                    if (item_index < 0 || item_index >= player.num_items) {
                        printf("Invalid item index.\n");
                    } else {
                        for (int i = item_index; i < player.num_items - 1; i++) {
                            strncpy(player.inventory[i], player.inventory[i+1], MAX_ITEM_LEN);
                        }
                        player.num_items--;
                        printf("Item removed.\n");
                    }
                }
                break;
            case 3:
                printf("Thanks for playing Medieval Inventory Manager!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}