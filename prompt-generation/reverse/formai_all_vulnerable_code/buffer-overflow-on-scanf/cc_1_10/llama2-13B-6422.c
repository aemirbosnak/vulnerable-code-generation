//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare our hero variables! 💪
int heroHealth = 100;
int heroAttack = 5;
int heroDefense = 3;

// Declare our enemy variables! 👿
int enemyHealth = 100;
int enemyAttack = 10;
int enemyDefense = 5;

// Declare our weapons! 🔫
int weapon1Damage = 8;
int weapon2Damage = 12;

// Declare our armor! 🛡️
int armor1Defense = 3;
int armor2Defense = 5;

// Declare our items! 🏹
int potionHealthBoost = 20;
int swordAttackBoost = 15;
int shieldDefenseBoost = 10;

// Define our functions! 🔍
void attack(int attackingPlayer, int attackingEnemy);
void defend(int defendingPlayer, int defendingEnemy);
void useItem(int itemId);

// Define our game loop! 🔝
void gameLoop() {
    int playerChoice;

    // Display the game menu.
    printf("Welcome to Epic Adventures! \n");
    printf("Choose your adventure: \n");
    printf("1. Attack enemy with sword. \n");
    printf("2. Attack enemy with shield. \n");
    printf("3. Use potion to heal. \n");
    printf("4. Defend with shield. \n");
    printf("5. Quit. \n");

    // Get the player's choice.
    scanf("%d", &playerChoice);

    // Execute the player's choice.
    switch (playerChoice) {
        case 1:
            attack(heroAttack, enemyAttack);
            break;

        case 2:
            defend(heroDefense, enemyDefense);
            break;

        case 3:
            useItem(potionHealthBoost);
            break;

        case 4:
            defend(heroDefense, enemyAttack);
            break;

        case 5:
            exit(0);
            break;
    }
}

// Define our attack function! 💥
void attack(int attackingPlayer, int attackingEnemy) {
    int damage = attackingPlayer * 2;

    // Check if the enemy has been defeated.
    if (enemyHealth - damage < 0) {
        enemyHealth = 0;
        printf("You defeated the enemy! \n");
    } else {
        enemyHealth -= damage;
    }
}

// Define our defend function! 🛡️
void defend(int defendingPlayer, int defendingEnemy) {
    int defense = defendingPlayer * 3;

    // Check if the enemy has been defeated.
    if (defendingEnemy - defense < 0) {
        defendingEnemy = 0;
        printf("The enemy was defeated by your shield! \n");
    } else {
        defendingEnemy -= defense;
    }
}

// Define our useItem function! 🏹
void useItem(int itemId) {
    switch (itemId) {
        case 1:
            heroHealth += potionHealthBoost;
            break;

        case 2:
            heroAttack += swordAttackBoost;
            break;

        case 3:
            heroDefense += shieldDefenseBoost;
            break;
    }
}

int main() {
    // Initialize our hero and enemy variables.
    heroHealth = 100;
    enemyHealth = 100;

    // Set up our game loop.
    gameLoop();

    return 0;
}