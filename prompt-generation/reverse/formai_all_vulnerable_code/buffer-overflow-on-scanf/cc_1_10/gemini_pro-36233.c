//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Character struct
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Character;

// Enemy struct
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    bool isAlive;
} Enemy;

// Define the player character
Character player = {"Player", 100, 10, 5};

// Define the enemies
Enemy enemies[] = {
    {"Goblin", 50, 5, 2, true},
    {"Orc", 75, 7, 3, true},
    {"Troll", 100, 10, 5, true},
    {"Dragon", 150, 15, 7, true}
};

// Define the game state
bool gameOver = false;
bool playerWon = false;

// Define the game functions
void printTitle();
void printCharacter(Character character);
void printEnemy(Enemy enemy);
void printGameState();
void attackEnemy(Enemy* enemy);
void checkGameState();

int main() {
    // Print the game title
    printTitle();

    // Print the player character
    printCharacter(player);

    // Print the enemies
    for (int i = 0; i < sizeof(enemies) / sizeof(Enemy); i++) {
        printEnemy(enemies[i]);
    }

    // Print the game state
    printGameState();

    // Game loop
    while (!gameOver) {
        // Get the player's input
        char input;
        printf("Enter your command (a/s/d/q): ");
        scanf(" %c", &input);

        // Handle the player's input
        switch (input) {
            case 'a':
                // Attack the first enemy
                attackEnemy(&enemies[0]);
                break;
            case 's':
                // Attack the second enemy
                attackEnemy(&enemies[1]);
                break;
            case 'd':
                // Attack the third enemy
                attackEnemy(&enemies[2]);
                break;
            case 'q':
                // Quit the game
                gameOver = true;
                break;
            default:
                // Invalid input
                printf("Invalid input. Please enter a/s/d/q.\n");
                break;
        }

        // Check the game state
        checkGameState();

        // Print the game state
        printGameState();
    }

    // Print the game over message
    if (playerWon) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}

void printTitle() {
    printf("=======================\n");
    printf("==  Dungeon Crawler  ==\n");
    printf("=======================\n");
}

void printCharacter(Character character) {
    printf("Name: %s\n", character.name);
    printf("Health: %d\n", character.health);
    printf("Attack: %d\n", character.attack);
    printf("Defense: %d\n\n", character.defense);
}

void printEnemy(Enemy enemy) {
    printf("Name: %s\n", enemy.name);
    printf("Health: %d\n", enemy.health);
    printf("Attack: %d\n", enemy.attack);
    printf("Defense: %d\n\n", enemy.defense);
}

void printGameState() {
    printf("Player Health: %d\n", player.health);

    for (int i = 0; i < sizeof(enemies) / sizeof(Enemy); i++) {
        if (enemies[i].isAlive) {
            printf("%s Health: %d\n", enemies[i].name, enemies[i].health);
        }
    }

    printf("\n");
}

void attackEnemy(Enemy* enemy) {
    // Calculate the damage dealt
    int damage = player.attack - enemy->defense;
    if (damage < 0) {
        damage = 0;
    }

    // Apply the damage to the enemy
    enemy->health -= damage;

    // Check if the enemy is dead
    if (enemy->health <= 0) {
        enemy->isAlive = false;
    }
}

void checkGameState() {
    // Check if the player is dead
    if (player.health <= 0) {
        gameOver = true;
        playerWon = false;
        return;
    }

    // Check if all enemies are dead
    bool allEnemiesDead = true;
    for (int i = 0; i < sizeof(enemies) / sizeof(Enemy); i++) {
        if (enemies[i].isAlive) {
            allEnemiesDead = false;
            break;
        }
    }

    if (allEnemiesDead) {
        gameOver = true;
        playerWon = true;
    }
}