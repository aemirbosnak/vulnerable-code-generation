//FormAI DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ENERGY 50
#define NUM_ENEMY_TYPES 3

// Enemy types
enum Enemy { MUTANT = 0, RAIDER = 1, ZOMBIE = 2 };

// Struct for player data
typedef struct {
    int health;
    int energy;
    int score;
} Player;

// Struct for enemy data
typedef struct {
    int health;
    int attack;
} EnemyData;

// Function to generate a random enemy type
enum Enemy generateEnemyType() {
    return rand() % NUM_ENEMY_TYPES;
}

// Function to generate random enemy health and attack values
void generateEnemyData(EnemyData* data, enum Enemy type) {
    switch(type) {
        case MUTANT:
            data->health = rand() % 50 + 50; // Range: 50-99
            data->attack = rand() % 20 + 10; // Range: 10-29
            break;
        case RAIDER:
            data->health = rand() % 40 + 30; // Range: 30-69
            data->attack = rand() % 25 + 15; // Range: 15-39
            break;
        case ZOMBIE:
            data->health = rand() % 30 + 20; // Range: 20-49
            data->attack = rand() % 30 + 20; // Range: 20-49
            break;
    }
}

// Function to handle player's attack
void attack(EnemyData* enemy, int energy) {
    if (energy >= 10) {
        enemy->health -= energy * 2;
    } else {
        enemy->health -= energy;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize player data
    Player player = { MAX_HEALTH, MAX_ENERGY, 0 };

    printf("Welcome to the post-apocalyptic wasteland! Your goal is to defeat as many enemies as possible.\n");

    while (player.health > 0) {
        // Generate a random enemy type and data
        EnemyData enemyData;
        enum Enemy enemyType = generateEnemyType();
        generateEnemyData(&enemyData, enemyType);

        printf("\nYou encountered a ");

        switch(enemyType) {
            case MUTANT:
                printf("Mutant ");
                break;
            case RAIDER:
                printf("Raider ");
                break;
            case ZOMBIE:
                printf("Zombie ");
                break;
        }

        printf("with %d health and %d attack!\n", enemyData.health, enemyData.attack);

        // Player's turn
        printf("\nIt's your turn! You have %d health and %d energy.\n", player.health, player.energy);
        printf("Enter a number between 1-10 to select your energy level: ");
        int energy;
        scanf("%d", &energy);

        if (energy < 1 || energy > 10) {
            printf("Invalid energy level! Energy automatically set to 1.\n");
            energy = 1;
        }

        attack(&enemyData, energy);
        player.energy -= energy;

        // Check if player defeated the enemy
        if (enemyData.health <= 0) {
            printf("\nYou defeated the enemy and gained 10 points!\n");
            player.score += 10;
            player.health += 10;
            if (player.health > MAX_HEALTH) {
                player.health = MAX_HEALTH;
            }
            player.energy += 5;
            if (player.energy > MAX_ENERGY) {
                player.energy = MAX_ENERGY;
            }
        } else {
            printf("\nYou dealt %d damage to the enemy!\n", energy >= 10 ? energy * 2 : energy);
        }

        // Enemy's turn
        if (enemyData.health > 0) {
            int damage = enemyData.attack;
            player.health -= damage;
            printf("\nThe enemy dealt %d damage to you!\n", damage);
        }

        // Check if player is out of energy
        if (player.energy <= 0) {
            printf("\nYou are out of energy! Game over.\n");
            break;
        }
    }

    printf("\nYou scored %d points. Thanks for playing!\n", player.score);

    return 0;
}