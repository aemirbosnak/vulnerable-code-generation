//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ENEMIES 5
#define MAX_TREASURES 3

typedef struct {
    char name[20];
    int health;
    int attack;
    int gold;
} Character;

typedef struct {
    char name[20];
    int health;
    int attack;
} Enemy;

typedef struct {
    char name[20];
    int goldValue;
} Treasure;

void displayCharacter(Character player) {
    printf("\nPlayer Info:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Gold: %d\n", player.gold);
}

void displayEnemy(Enemy enemy) {
    printf("\nEnemy Encountered:\n");
    printf("Name: %s\n", enemy.name);
    printf("Health: %d\n", enemy.health);
}

void displayTreasure(Treasure treasure) {
    printf("\nTreasure Found:\n");
    printf("Name: %s\n", treasure.name);
    printf("Gold Value: %d\n", treasure.goldValue);
}

void attackEnemy(Character *player, Enemy *enemy) {
    printf("\nYou attack the %s for %d damage!\n", enemy->name, player->attack);
    enemy->health -= player->attack;
    if (enemy->health > 0) {
        printf("%s has %d health remaining.\n", enemy->name, enemy->health);
    } else {
        printf("You have defeated the %s!\n", enemy->name);
        player->gold += 20;  // Rewards for defeating enemy
        printf("You earned 20 gold!\n");
    }
}

void enemyAttack(Character *player, Enemy *enemy) {
    printf("\n%s attacks you for %d damage!\n", enemy->name, enemy->attack);
    player->health -= enemy->attack;
    if (player->health <= 0) {
        printf("You have been defeated by the %s!\n", enemy->name);
        exit(0);
    } else {
        printf("You have %d health remaining.\n", player->health);
    }
}

void takeTurn(Character *player, Enemy *enemy) {
    char choice;
    printf("\nDo you want to (a)ttack or (r)un? ");
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'a') {
            attackEnemy(player, enemy);
            if (enemy->health > 0) {
                enemyAttack(player, enemy);
            }
            break;
        } else if (choice == 'r') {
            printf("You ran away from the %s!\n", enemy->name);
            break;
        } else {
            printf("Invalid input! Please choose (a)ttack or (r)un: ");
        }
    }
}

void findTreasure(Character *player) {
    Treasure treasures[MAX_TREASURES] = {{"Ancient Coin", 50}, {"Golden Amulet", 100}, {"Silver Ring", 30}};
    int idx = rand() % MAX_TREASURES;
    displayTreasure(treasures[idx]);
    player->gold += treasures[idx].goldValue;
}

int main() {
    srand(time(0));
    Character player = {"Brave Hero", MAX_HEALTH, 20, 0};
    Enemy enemies[MAX_ENEMIES] = {{"Goblin", 30, 10}, {"Orc", 50, 15}, {"Troll", 70, 20}, {"Dragon", 100, 25}, {"Vampire", 40, 18}};
    int gameRunning = 1;

    printf("Welcome to the Brave Adventure Game!\n");
    printf("Enter your hero's name: ");
    scanf("%s", player.name);

    while (gameRunning) {
        displayCharacter(player);

        int enemyIndex = rand() % MAX_ENEMIES;
        Enemy enemy = enemies[enemyIndex];
        enemy.health = enemy.health > 0 ? enemy.health : 0; // Ensure enemy health is not negative
        displayEnemy(enemy);

        while (enemy.health > 0) {
            takeTurn(&player, &enemy);
        }

        findTreasure(&player);

        char continueGame;
        printf("Do you want to continue exploring? (y/n): ");
        scanf(" %c", &continueGame);
        if (continueGame != 'y') {
            gameRunning = 0;
        }
    }

    printf("Thank you for playing! You collected %d gold.\n", player.gold);
    return 0;
}