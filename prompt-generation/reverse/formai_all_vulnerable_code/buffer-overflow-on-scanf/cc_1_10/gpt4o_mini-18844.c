//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_INVENTORY 10

typedef struct {
    char *name;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_INVENTORY];
    int count;
} Inventory;

void attack(Inventory *inventory, int *enemy_health);
void search_items(Inventory *inventory);
void display_inventory(Inventory *inventory);
void explore(Inventory *inventory, int *enemy_health);

void attack(Inventory *inventory, int *enemy_health) {
    if (*enemy_health <= 0) {
        printf("There's no enemy left to attack!\n");
        return;
    }

    printf("You prepare to attack!\n");
    if (inventory->count > 0) {
        Item selected_item = inventory->items[rand() % inventory->count];
        printf("You use %s to deal damage!\n", selected_item.name);
        *enemy_health -= selected_item.quantity;
        printf("Enemy health is now %d\n", *enemy_health);
    } else {
        printf("You have no items to attack with!\n");
    }
}

void search_items(Inventory *inventory) {
    if (inventory->count >= MAX_INVENTORY) {
        printf("Your inventory is full! Can't search for more items.\n");
        return;
    }

    char *found_items[] = {"Rusty Knife", "Old Amunition", "Broken Radio", "Stale Rations", "Ancient Map"};
    int num_found_items = sizeof(found_items) / sizeof(found_items[0]);

    for (int i = 0; i < 3; i++) { // simulate finding up to 3 items
        if (inventory->count < MAX_INVENTORY) {
            int found_index = rand() % num_found_items;
            inventory->items[inventory->count].name = found_items[found_index];
            inventory->items[inventory->count].quantity = rand() % 10 + 1; // random quantity
            inventory->count++;
            printf("Found %dx %s!\n", inventory->items[inventory->count - 1].quantity, inventory->items[inventory->count - 1].name);
        }
    }

    printf("Inventory now holds %d items.\n", inventory->count);
}

void display_inventory(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    printf("Current Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf(" - %dx %s\n", inventory->items[i].quantity, inventory->items[i].name);
    }
}

void explore(Inventory *inventory, int *enemy_health) {
    printf("Exploring the abandoned city...\n");

    int action = rand() % 3;
    if (action == 0) {
        printf("You encounter an enemy!\n");
        *enemy_health = rand() % 50 + 10; // random enemy health between 10-59
    } else if (action == 1) {
        search_items(inventory);
    } else {
        printf("Nothing happens...\\n");
    }
}

void game_loop() {
    Inventory inventory = { .count = 0 };
    int enemy_health = 0;
    int game_over = 0;

    while (!game_over) {
        display_inventory(&inventory);
        explore(&inventory, &enemy_health);

        if (enemy_health > 0) {
            printf("Would you like to attack the enemy? (1 for Yes, 0 for No): ");
            int choice;
            scanf("%d", &choice);
            if (choice) {
                attack(&inventory, &enemy_health);
            }
        }

        if (enemy_health <= 0) {
            printf("You have defeated the enemy!\n");
            enemy_health = 0; // Reset enemy health
        }

        char continue_choice;
        printf("Do you want to continue exploring? (y/n): ");
        scanf(" %c", &continue_choice);
        if (continue_choice != 'y') {
            game_over = 1;
        }
    }

    printf("Game Over! Survived in the wasteland for a while.\n");
}

int main() {
    srand(time(NULL));
    game_loop();
    return 0;
}