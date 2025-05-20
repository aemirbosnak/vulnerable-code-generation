//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_MONSTERS 3

typedef struct {
    char name[30];
    int health;
    int attack;
    int defense;
} Character;

typedef struct {
    char name[30];
    int damage;
} Item;

typedef struct {
    char name[30];
    int health;
    int damage;
} Monster;

void initializeCharacter(Character* player) {
    printf("Enter your character name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->attack = 20;
    player->defense = 5;
}

void initializeMonster(Monster* monster, const char* name, int health, int damage) {
    strcpy(monster->name, name);
    monster->health = health;
    monster->damage = damage;
}

void initializeItem(Item* item, const char* name, int damage) {
    strcpy(item->name, name);
    item->damage = damage;
}

int battle(Character* player, Monster* monster) {
    printf("A wild %s appears!\n", monster->name);
    while (player->health > 0 && monster->health > 0) {
        monster->health -= player->attack - monster->damage / player->defense;
        if (monster->health > 0) {
            player->health -= monster->damage;
            printf("%s attacks! You have %d health remaining.\n", monster->name, player->health);
        } else {
            printf("You defeated the %s!\n", monster->name);
            return 1; // Victory
        }
    }
    return 0; // Defeat
}

void explore(Character* player, Monster* monsters, int numMonsters) {
    int choice;
    printf("You are exploring the dungeon. Choose an option:\n");
    printf("1. Look for monsters\n");
    printf("2. Use an item\n");
    printf("3. Rest\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            for (int i = 0; i < numMonsters; i++) {
                if (battle(player, &monsters[i]) == 0) {
                    printf("You have been defeated in battle!\n");
                    exit(0);
                }
            }
            break;
        case 2:
            printf("You used an item!\n");
            break;
        case 3:
            printf("You rest and regain some health.\n");
            player->health += 20;
            if (player->health > 100) player->health = 100;
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    Character player;
    Item items[MAX_ITEMS];
    Monster monsters[MAX_MONSTERS];

    initializeCharacter(&player);
    initializeMonster(&monsters[0], "Goblin", 30, 10);
    initializeMonster(&monsters[1], "Troll", 50, 15);
    initializeMonster(&monsters[2], "Dragon", 100, 20);
    initializeItem(&items[0], "Health Potion", 20);
    initializeItem(&items[1], "Sword of Might", 10);
    initializeItem(&items[2], "Shield of Valor", 5);
    
    printf("Welcome to the Dungeon, %s!\n", player.name);
    
    while (player.health > 0) {
        explore(&player, monsters, MAX_MONSTERS);
    }

    printf("Game Over! You did not survive the adventures!\n");
    return 0;
}