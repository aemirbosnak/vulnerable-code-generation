//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Character struct to hold player information
struct Character {
    char name[20];
    int health;
    int attack;
    int defense;
};

// Function to generate a random number between min and max (inclusive)
int randNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Setup random number generator
    srand(time(NULL));

    // Initialize player character
    struct Character player;
    printf("What is your character's name?\n");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 10;
    player.defense = 5;

    // Set up alien enemy characters
    struct Character alien1 = {"Zorgax", 75, 15, 5};
    struct Character alien2 = {"Voltron", 60, 20, 10};
    struct Character alien3 = {"Nexor", 80, 10, 15};

    // Fight sequence
    int round = 1;
    while (player.health > 0) {
        printf("\n--- Round %d ---\n", round);

        // Generate a random number to determine which alien the player fights
        int alienNum = randNum(1, 3);
        struct Character enemy;
        if (alienNum == 1) {
            enemy = alien1;
            printf("You encounter %s!\n", enemy.name);
        } else if (alienNum == 2) {
            enemy = alien2;
            printf("You encounter %s!\n", enemy.name);
        } else {
            enemy = alien3;
            printf("You encounter %s!\n", enemy.name);
        }

        // Fight sequence
        while (player.health > 0 && enemy.health > 0) {
            // Player's turn to attack
            int playerDamage = randNum(player.attack - 5, player.attack + 5);
            enemy.health -= playerDamage;
            printf("You attack %s for %d damage!\n", enemy.name, playerDamage);
            if (enemy.health <= 0) {
                printf("You defeated %s!\n", enemy.name);
                break;
            }

            // Enemy's turn to attack
            int enemyDamage = randNum(enemy.attack - 5, enemy.attack + 5);
            player.health -= enemyDamage - player.defense;
            printf("%s attacks you for %d damage!\n", enemy.name, enemyDamage - player.defense);

            // Check if player died
            if (player.health <= 0) {
                printf("You died. Game over.\n");
                return 0;
            }
        }

        // Increase player's attack and defense after each round
        player.attack += 5;
        player.defense += 2;

        // Check if player has won the game
        if (round == 5) {
            printf("Congratulations, you have defeated all of the aliens! You win!\n");
            return 0;
        }

        // Increment round counter
        round++;
    }

    return 0;
}