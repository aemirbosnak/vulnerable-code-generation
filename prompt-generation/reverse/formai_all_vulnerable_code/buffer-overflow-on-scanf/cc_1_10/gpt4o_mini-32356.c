//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 5
#define DUNGEON_SIZE 3

typedef struct {
    char name[20];
    int value;
} Item;

typedef struct {
    char name[20];
    int health;
    Item inventory[MAX_ITEMS];
    int item_count;
} Player;

typedef struct {
    char name[20];
    int health;
    int damage;
} Monster;

void initializePlayer(Player *player) {
    printf("Enter your character name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->item_count = 0;
}

void initializeMonsters(Monster monsters[]) {
    strcpy(monsters[0].name, "Goblin");
    monsters[0].health = 30;
    monsters[0].damage = 10;

    strcpy(monsters[1].name, "Skeleton");
    monsters[1].health = 40;
    monsters[1].damage = 15;

    strcpy(monsters[2].name, "Orc");
    monsters[2].health = 50;
    monsters[2].damage = 20;
}

void addRandomItem(Player *player) {
    const char *item_names[] = {"Gold Coin", "Healing Potion", "Magic Sword", "Shield", "Amulet"};
    if (player->item_count < MAX_ITEMS) {
        int item_value = rand() % 50 + 1; // random value between 1 and 50
        strcpy(player->inventory[player->item_count].name, item_names[rand() % 5]);
        player->inventory[player->item_count].value = item_value;
        player->item_count++;
        printf("You found a %s worth %d gold coins!\n", player->inventory[player->item_count - 1].name, item_value);
    } else {
        printf("Your inventory is full!\n");
    }
}

void displayInventory(Player *player) {
    printf("Inventory:\n");
    for (int i = 0; i < player->item_count; i++) {
        printf("%s (Value: %d)\n", player->inventory[i].name, player->inventory[i].value);
    }
}

void encounterMonster(Player *player, Monster *monster) {
    printf("A wild %s appears!\n", monster->name);
    while (player->health > 0 && monster->health > 0) {
        printf("Your Health: %d | %s's Health: %d\n", player->health, monster->name, monster->health);
        printf("Choose an action: (1) Attack (2) Run (3) Check Inventory\n");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You attack the %s!\n", monster->name);
            monster->health -= 20; // Player deals 20 damage
            if (monster->health > 0) {
                printf("%s attacks you back!\n", monster->name);
                player->health -= monster->damage;
            }
        } else if (choice == 2) {
            printf("You ran away!\n");
            return;
        } else if (choice == 3) {
            displayInventory(player);
            continue;
        } else {
            printf("Invalid choice. Try again.\n");
            continue;
        }
    }

    if (player->health <= 0) {
        printf("You were defeated by the %s...\n", monster->name);
    } else {
        printf("You defeated the %s!\n", monster->name);
        addRandomItem(player);
    }
}

int main() {
    srand(time(NULL));
    Player player;
    initializePlayer(&player);
    
    Monster monsters[DUNGEON_SIZE];
    initializeMonsters(monsters);

    for (int i = 0; i < DUNGEON_SIZE; i++) {
        encounterMonster(&player, &monsters[i]);
        if (player.health <= 0) {
            break; // Game over if player is dead
        }
    }
    
    if (player.health > 0) {
        printf("Congratulations, %s! You survived the dungeon!\n", player.name);
        printf("You collected items worth:\n");
        displayInventory(&player);
    }

    return 0;
}