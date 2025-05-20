//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_ITEMS 3

typedef struct {
    char name[30];
    int health;
    int attack_power;
} Character;

typedef struct {
    char name[30];
    int health;
    int attack_power;
} Enemy;

typedef struct {
    char name[30];
    int healing_amount;
} Item;

void initialize_character(Character *player) {
    printf("Enter your character name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->attack_power = 20;
}

void initialize_enemy(Enemy *enemy, int id) {
    snprintf(enemy->name, sizeof(enemy->name), "Enemy %d", id);
    enemy->health = 50 + rand() % 51; // Health between 50 and 100
    enemy->attack_power = 10 + rand() % 11; // Attack power between 10 and 20
}

void initialize_items(Item *items) {
    snprintf(items[0].name, sizeof(items[0].name), "Health Potion");
    items[0].healing_amount = 30;
    
    snprintf(items[1].name, sizeof(items[1].name), "Energy Drink");
    items[1].healing_amount = 20;

    snprintf(items[2].name, sizeof(items[2].name), "Mega Potion");
    items[2].healing_amount = 50;
}

void display_status(Character *player, Enemy *enemies) {
    printf("\nYour status:\n");
    printf("Name: %s | Health: %d | Attack Power: %d\n", player->name, player->health, player->attack_power);
    
    printf("\nEnemies Status:\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("%s - Health: %d\n", enemies[i].name, enemies[i].health);
    }
}

void player_attack(Character *player, Enemy *enemy) {
    printf("%s attacks %s for %d damage!\n", player->name, enemy->name, player->attack_power);
    enemy->health -= player->attack_power;
}

void enemy_attack(Enemy *enemy, Character *player) {
    printf("%s attacks you for %d damage!\n", enemy->name, enemy->attack_power);
    player->health -= enemy->attack_power;
}

void use_item(Character *player, Item *item) {
    printf("You use %s and restore %d health!\n", item->name, item->healing_amount);
    player->health += item->healing_amount;
    if (player->health > 100) {
        player->health = 100; // Cap health at 100
    }
}

int main() {
    srand(time(0));
    
    Character player;
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];
    int is_game_over = 0;
    char action;
    
    initialize_character(&player);
    for (int i = 0; i < MAX_ENEMIES; i++) {
        initialize_enemy(&enemies[i], i + 1);
    }
    initialize_items(items);
    
    while (!is_game_over) {
        display_status(&player, enemies);
        
        printf("\nChoose an action - (A)ttack, (H)eal, (Q)uit: ");
        scanf(" %c", &action);

        if (action == 'A' || action == 'a') {
            for (int i = 0; i < MAX_ENEMIES; i++) {
                if (enemies[i].health > 0) {
                    player_attack(&player, &enemies[i]);
                    if (enemies[i].health <= 0) {
                        printf("%s has been defeated!\n", enemies[i].name);
                    } else {
                        enemy_attack(&enemies[i], &player);
                    }
                }
            }
        } else if (action == 'H' || action == 'h') {
            for (int j = 0; j < MAX_ITEMS; j++) {
                printf("Item %d: %s\n", j + 1, items[j].name);
            }
            int item_choice;
            printf("Select an item to use (1-%d): ", MAX_ITEMS);
            scanf("%d", &item_choice);
            if (item_choice >= 1 && item_choice <= MAX_ITEMS) {
                use_item(&player, &items[item_choice - 1]);
            }
        } else if (action == 'Q' || action == 'q') {
            is_game_over = 1;
            printf("Exiting game. Thanks for playing!\n");
        } else {
            printf("Invalid action. Try again!\n");
        }
        
        if (player.health <= 0) {
            printf("You have been defeated!\n");
            is_game_over = 1;
        }
    }
    
    return 0;
}