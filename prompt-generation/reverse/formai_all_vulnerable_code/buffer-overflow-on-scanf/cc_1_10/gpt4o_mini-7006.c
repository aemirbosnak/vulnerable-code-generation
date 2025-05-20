//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_ITEMS 5

typedef struct {
    char name[20];
    int health;
    int attack;
} Character;

typedef struct {
    char name[20];
    int health;
    int attack;
} Enemy;

typedef struct {
    char name[20];
    int effect;
} Item;

void printCharacterStats(Character player) {
    printf("Player: %s\nHealth: %d\nAttack: %d\n", player.name, player.health, player.attack);
}

void printEnemyStats(Enemy enemy) {
    printf("Enemy: %s\nHealth: %d\nAttack: %d\n", enemy.name, enemy.health, enemy.attack);
}

int combat(Character *player, Enemy *enemy) {
    while (player->health > 0 && enemy->health > 0) {
        // Player attacks
        enemy->health -= player->attack;
        printf("%s attacks %s for %d damage!\n", player->name, enemy->name, player->attack);
        printf("%s has %d health remaining.\n", enemy->name, enemy->health);

        if (enemy->health <= 0) {
            printf("%s has been defeated!\n", enemy->name);
            return 1; // Enemy defeated
        }

        // Enemy attacks
        player->health -= enemy->attack;
        printf("%s attacks %s for %d damage!\n", enemy->name, player->name, enemy->attack);
        printf("%s has %d health remaining.\n", player->name, player->health);
    }
    return 0; // Player defeated
}

void loot(Item items[], int size) {
    printf("You found some loot!\n");
    for (int i = 0; i < size; i++) {
        printf("- %s\n", items[i].name);
    }
}

void setupItems(Item items[]) {
    strcpy(items[0].name, "Health Potion");
    items[0].effect = 20;
    
    strcpy(items[1].name, "Mana Potion");
    items[1].effect = 10;

    strcpy(items[2].name, "Sword");
    items[2].effect = 5; // Extra attack

    strcpy(items[3].name, "Shield");
    items[3].effect = 5; // Extra health or defense

    strcpy(items[4].name, "Magic Amulet");
    items[4].effect = 10; // Boost to both health and attack
}

void useItem(Character *player, Item item) {
    if (strcmp(item.name, "Health Potion") == 0) {
        player->health += item.effect;
        printf("%s used a Health Potion! Health is now %d.\n", player->name, player->health);
    }
    // Other items can be added similarly
}

int main() {
    srand(time(NULL));
    
    Character player;
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];

    // Setup player
    printf("Enter your character's name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 20;

    // Setup enemies
    strcpy(enemies[0].name, "Goblin");
    enemies[0].health = 30;
    enemies[0].attack = 5;

    strcpy(enemies[1].name, "Orc");
    enemies[1].health = 50;
    enemies[1].attack = 10;

    strcpy(enemies[2].name, "Dragon");
    enemies[2].health = 100;
    enemies[2].attack = 20;

    // Load items
    setupItems(items);

    // Adventure loop
    char choice;
    
    while (player.health > 0) {
        printf("\n");
        printCharacterStats(player);
        
        printf("You encounter an enemy! \n");
        int enemyIndex = rand() % MAX_ENEMIES;
        Enemy currentEnemy = enemies[enemyIndex];
        printEnemyStats(currentEnemy);
        
        printf("Do you want to [A]ttack, [R]un, or [L]oot? ");
        scanf(" %c", &choice);
        
        if (choice == 'A' || choice == 'a') {
            // Combat
            if (combat(&player, &currentEnemy) == 1) {
                printf("You have won the battle!\n");
                loot(items, MAX_ITEMS);
            } else {
                printf("You have been defeated!\n");
                break; // End game if player is defeated
            }
        } else if (choice == 'R' || choice == 'r') {
            printf("You ran away safely!\n");
        } else if (choice == 'L' || choice == 'l') {
            loot(items, MAX_ITEMS);
            // You could add logic here to allow the player to use the items
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    printf("Game Over!\n");
    return 0;
}