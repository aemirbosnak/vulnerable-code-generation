//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define player structure
typedef struct player {
    char name[20];
    int health;
    int strength;
    int gold;
} Player;

// Define enemy structure
typedef struct enemy {
    char name[20];
    int health;
    int strength;
    int gold;
} Enemy;

// Define function to create a random enemy
Enemy createEnemy() {
    Enemy enemy;
    int randomHealth = rand() % 20 + 5;
    int randomStrength = rand() % 5 + 1;
    int randomGold = rand() % 10 + 1;
    int randomEnemy = rand() % 3;
    switch (randomEnemy) {
        case 0: strcpy(enemy.name, "Goblin");
                break;
        case 1: strcpy(enemy.name, "Troll");
                break;
        case 2: strcpy(enemy.name, "Dragon");
                break;
    }
    enemy.health = randomHealth;
    enemy.strength = randomStrength;
    enemy.gold = randomGold;
    return enemy;
}

// Define function to print player stats
void printPlayer(Player player) {
    printf("\n----------\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Strength: %d\n", player.strength);
    printf("Gold: %d\n", player.gold);
    printf("----------\n\n");
}

// Define function to print enemy stats
void printEnemy(Enemy enemy) {
    printf("\n----------\n");
    printf("Name: %s\n", enemy.name);
    printf("Health: %d\n", enemy.health);
    printf("Strength: %d\n", enemy.strength);
    printf("Gold: %d\n", enemy.gold);
    printf("----------\n\n");
}

int main() {
    // Initialize player
    Player player = {"Player", 100, 10, 0};
    
    printf("Welcome to Adventure Game!\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", player.name);
    printf("Greetings, %s!\n", player.name);
    
    // Keep playing until player dies
    while (player.health > 0) {
        printf("You are in a forest.\n");
        printf("What do you want to do?\n");
        printf("1. Look for treasure\n");
        printf("2. Fight an enemy\n");
        printf("3. Quit the game\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: player.gold += rand() % 10 + 1;
                    printf("You found %d gold!\n", player.gold);
                    break;
            case 2: printf("You encounter an enemy!\n");
                    Enemy enemy = createEnemy();
                    printEnemy(enemy);
                    
                    // Fight the enemy
                    while (player.health > 0 && enemy.health > 0) {
                        // Player attacks first
                        int playerDamage = rand() % player.strength + 1;
                        printf("%s attacks %s for %d damage!\n", player.name, enemy.name, playerDamage);
                        enemy.health -= playerDamage;
                        if (enemy.health <= 0) {
                            printf("You defeat %s and earn %d gold!\n", enemy.name, enemy.gold);
                            player.gold += enemy.gold;
                            break;
                        }
                        // Enemy attacks
                        int enemyDamage = rand() % enemy.strength + 1;
                        printf("%s attacks %s for %d damage!\n", enemy.name, player.name, enemyDamage);
                        player.health -= enemyDamage;
                        if (player.health <= 0) {
                            printf("You died. Game over.\n");
                            return 0;
                        }
                        printPlayer(player);
                        printEnemy(enemy);
                    }
                    break;
            case 3: printf("Thanks for playing! Goodbye.\n");
                    return 0;
            default: printf("Invalid input. Try again.\n");
                     break;
        }
    }
    printf("You died. Game over.\n");
    return 0;
}