//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_HEALTH 100

typedef struct {
    char name[20];
    int power;
} Creature;

typedef struct {
    char name[20];
    int value;
} Item;

typedef struct {
    Item inventory[MAX_ITEMS];
    int num_items;
    int health;
} Player;

void print_welcome() {
    printf("Welcome to the Mystic Forest Adventure!\n");
    printf("Your Quest: Explore, battle creatures, and gather treasures.\n");
    printf("You start with %d health points.\n\n", MAX_HEALTH);
}

void print_status(Player *player) {
    printf("Your Health: %d\n", player->health);
    printf("Items in your inventory:\n");
    for (int i = 0; i < player->num_items; i++) {
        printf(" - %s (Value: %d)\n", player->inventory[i].name, player->inventory[i].value);
    }
    printf("\n");
}

Creature generate_creature() {
    Creature creatures[3] = {
        {"Goblin", 20},
        {"Dragon", 30},
        {"Fairy", 10}
    };
    
    return creatures[rand() % 3];
}

Item generate_item() {
    Item items[3] = {
        {"Gold Coin", 50},
        {"Magic Potion", 30},
        {"Ancient Scroll", 20}
    };

    return items[rand() % 3];
}

void battle(Player *player, Creature creature) {
    printf("You encounter a %s!\n", creature.name);
    printf("It attacks you with %d power!\n", creature.power);

    player->health -= creature.power;
    printf("You now have %d health left!\n", player->health);

    if (player->health <= 0) {
        printf("You have been defeated!\nGame Over!\n");
        exit(0);
    }

    printf("You defeated the %s!\n", creature.name);
}

void collect_item(Player *player) {
    if (player->num_items < MAX_ITEMS) {
        Item item = generate_item();
        player->inventory[player->num_items++] = item;
        printf("You collected a %s! (Value: %d)\n", item.name, item.value);
    } else {
        printf("Your inventory is full!\n");
    }
}

void explore(Player *player) {
    int action;
    printf("You can choose to:\n");
    printf("1. Explore the forest\n");
    printf("2. Check your status\n");
    printf("3. Exit Game\n");
    printf("Enter your choice: ");
    scanf("%d", &action);

    switch (action) {
        case 1:
            if (rand() % 2) {
                Creature creature = generate_creature();
                battle(player, creature);
            } else {
                collect_item(player);
            }
            break;
        
        case 2:
            print_status(player);
            break;

        case 3:
            printf("Thank you for playing! Goodbye!\n");
            exit(0);
        
        default:
            printf("Invalid choice! Please pick again.\n");
            break;
    }
}

int main() {
    srand(time(NULL));

    Player player;
    player.health = MAX_HEALTH;
    player.num_items = 0;

    print_welcome();

    while (1) {
        explore(&player);
    }

    return 0;
}