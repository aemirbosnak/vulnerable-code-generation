//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// deifining the constants
#define HEALTH 100
#define MAX_DAMAGE 20
#define MIN_DAMAGE 5

// function to generate random damage
int generateRandomDamage() {
    return rand() % (MAX_DAMAGE - MIN_DAMAGE + 1) + MIN_DAMAGE;
}

int main() {

    // seeding the random number generator
    srand(time(0));

    // initialising the variables
    char player[20], enemy[20];
    int playerHealth = HEALTH, enemyHealth = HEALTH;

    printf("Welcome to the Medieval Battle Game!\n\n");

    // getting the player and enemy name
    printf("Enter your name: ");
    scanf("%s", player);
    printf("Enter enemy's name: ");
    scanf("%s", enemy);

    printf("\n%s will fight against %s\n\n", player, enemy);

    // game starts
    while (1) {

        // player's turn
        printf("%s's turn:\n", player);
        int damage = generateRandomDamage();
        printf("%s attacks with %d damage!\n", player, damage);
        enemyHealth -= damage;

        // checking if enemy is defeated
        if (enemyHealth <= 0) {
            printf("\n%s defeated %s!\n", player, enemy);
            break;
        }

        // enemy's turn
        printf("%s's turn:\n", enemy);
        damage = generateRandomDamage();
        printf("%s attacks with %d damage!\n", enemy, damage);
        playerHealth -= damage;

        // checking if player is defeated
        if (playerHealth <= 0) {
            printf("\n%s defeated %s!\n", enemy, player);
            break;
        }

        // status update
        printf("\n%s's health: %d\n", player, playerHealth);
        printf("%s's health: %d\n\n", enemy, enemyHealth);

    }

    printf("Game over!\n");

    return 0;
}