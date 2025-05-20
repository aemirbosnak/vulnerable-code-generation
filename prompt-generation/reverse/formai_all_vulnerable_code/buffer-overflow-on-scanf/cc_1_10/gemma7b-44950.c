//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 5

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
} Enemy;

Enemy enemies[MAX_ENEMIES] = {
    {"Goblin", 100, 15},
    {"orc", 120, 12},
    {"skeleton", 80, 18},
    {"dwarf", 90, 16},
    {"giant", 140, 20}
};

int main() {
    int playerHealth = 100;
    int playerAttack = 10;
    char playerName[20];

    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("Welcome, %s, to the Arena of Doom!", playerName);

    // Battle Loop
    while (playerHealth > 0) {
        int enemyIndex = rand() % MAX_ENEMIES;
        Enemy enemy = enemies[enemyIndex];

        printf("You have encountered a %s with %d health and %d attack!\n", enemy.name, enemy.health, enemy.attack);

        // Attack Phase
        int damage = playerAttack - enemy.attack;
        enemy.health -= damage;

        // Check if enemy is dead
        if (enemy.health <= 0) {
            printf("You have slain the %s!\n", enemy.name);
        } else {
            // Enemy's turn
            damage = enemy.attack - playerAttack;
            playerHealth -= damage;

            printf("The %s has inflicted %d damage, leaving you with %d health.\n", enemy.name, damage, playerHealth);
        }

        // Display remaining health
        printf("Your remaining health is: %d\n", playerHealth);
    }

    // Game Over
    printf("Game Over! You have perished in the Arena of Doom.\n");

    return 0;
}