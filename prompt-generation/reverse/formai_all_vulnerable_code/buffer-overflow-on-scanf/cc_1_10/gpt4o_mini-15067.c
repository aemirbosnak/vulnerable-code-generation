//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    int value;
} Item;

typedef struct {
    char name[30];
    int health;
    Item inventory[MAX_ITEMS];
    int inventory_count;
} Player;

void initialize_player(Player *player, const char *name) {
    strcpy(player->name, name);
    player->health = 100;
    player->inventory_count = 0;
}

void add_item_to_inventory(Player *player, const char *item_name, int item_value) {
    if (player->inventory_count < MAX_ITEMS) {
        strcpy(player->inventory[player->inventory_count].name, item_name);
        player->inventory[player->inventory_count].value = item_value;
        player->inventory_count++;
        printf("%s added to inventory.\n", item_name);
    } else {
        printf("Inventory is full!\n");
    }
}

void display_inventory(const Player *player) {
    printf("\nInventory of %s:\n", player->name);
    for (int i = 0; i < player->inventory_count; i++) {
        printf("%d. %s (Value: %d)\n", i + 1, player->inventory[i].name, player->inventory[i].value);
    }
    if (player->inventory_count == 0) {
        printf("Your inventory is empty.\n");
    }
}

void encounter_item(Player *player) {
    const char *items[] = {"Potion", "Gold Coin", "Magic Gem", "Steel Sword", "Health Elixir"};
    int values[] = {20, 10, 50, 100, 30};
    int random_index = rand() % 5;

    printf("\nYou encountered a %s!\n", items[random_index]);
    add_item_to_inventory(player, items[random_index], values[random_index]);
}

void show_health(const Player *player) {
    printf("\n%s's health: %d\n", player->name, player->health);
}

void battle(Player *player) {
    int enemy_health = 50;
    int attack_power = 10;

    printf("\nA wild monster appeared!\n");

    while (enemy_health > 0) {
        enemy_health -= attack_power;
        player->health -= attack_power / 2; // Player loses half as much health as the enemy is damaged

        printf("You attacked the monster! Monster health: %d\n", enemy_health);
        show_health(player);
        if (player->health <= 0) {
            printf("You have been defeated!\n");
            exit(0);
        }
    }

    printf("You defeated the monster!\n");
}

int main() {
    srand(time(NULL));
    char player_name[30];
    Player player;

    printf("Welcome to the Adventure Game!\n");
    printf("Enter your character's name: ");
    scanf("%s", player_name);

    initialize_player(&player, player_name);

    int choice;
    do {
        printf("\n1. Look for items\n2. Check inventory\n3. Show health\n4. Battle a monster\n5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                encounter_item(&player);
                break;
            case 2:
                display_inventory(&player);
                break;
            case 3:
                show_health(&player);
                break;
            case 4:
                battle(&player);
                break;
            case 5:
                printf("Exiting the game. Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}