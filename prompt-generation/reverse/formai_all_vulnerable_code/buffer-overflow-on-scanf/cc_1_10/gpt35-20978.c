//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Player;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Enemy;

// Function to generate random numbers for the player and enemy attributes
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to create a new player with random attributes
Player createNewPlayer(char name[]) {
    Player player;

    // Initialize player's attributes with random values
    player.health = generateRandomNumber(50, 100);
    player.attack = generateRandomNumber(10, 20);
    player.defense = generateRandomNumber(5, 10);

    // Copy player's name
    strcpy(player.name, name);

    return player;
}

// Function to create a new enemy with random attributes
Enemy createNewEnemy() {
    Enemy enemy;

    // Initialize enemy's attributes with random values
    enemy.health = generateRandomNumber(30, 80);
    enemy.attack = generateRandomNumber(5, 15);
    enemy.defense = generateRandomNumber(3, 8);

    // Assign a random name to the enemy
    switch (generateRandomNumber(1, 3)) {
        case 1:
            strcpy(enemy.name, "Alien");
            break;
        case 2:
            strcpy(enemy.name, "Robot");
            break;
        case 3:
            strcpy(enemy.name, "Mutant");
            break;
    }

    return enemy;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Create a new player with a given name
    char playerName[20];
    printf("Enter your name: ");
    scanf("%s", playerName);
    Player player = createNewPlayer(playerName);

    // Introduce the player to the game
    printf("\n\nWelcome, %s, to the Procedural Space Adventure!\n", player.name);
    printf("You are on a mission to investigate an abandoned space station.\n\n");

    // Start the game loop
    while (1) {
        // Create a new enemy
        Enemy enemy = createNewEnemy();
        printf("A %s with %i health appears!\n\n", enemy.name, enemy.health);

        // Battle the enemy
        while (enemy.health > 0) {
            int playerAttack = generateRandomNumber(player.attack / 2, player.attack);
            int enemyDefense = generateRandomNumber(enemy.defense / 2, enemy.defense);

            int enemyDamage = playerAttack - enemyDefense;
            enemy.health -= enemyDamage;

            printf("%s attacks %s for %i damage.\n", player.name, enemy.name, enemyDamage);

            if (enemy.health <= 0) {
                printf("\n%s defeated %s!\n\n", player.name, enemy.name);
                break;
            }

            int enemyAttack = generateRandomNumber(enemy.attack / 2, enemy.attack);
            int playerDefense = generateRandomNumber(player.defense / 2, player.defense);

            int playerDamage = enemyAttack - playerDefense;
            player.health -= playerDamage;

            printf("%s attacks %s for %i damage.\n", enemy.name, player.name, playerDamage);

            if (player.health <= 0) {
                printf("\n%s has been defeated!\n\n", player.name);
                exit(0);
            }
        }

        // Restore the player's health after each battle
        player.health = generateRandomNumber(50, 100);
    }

    return 0;
}