//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_WEAPONS 3

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
} Enemy;

typedef struct Weapon {
    char name[20];
    int damage;
    int accuracy;
} Weapon;

Enemy enemies[MAX_ENEMIES] = {
    {"Bob", 100, 15},
    {"Alice", 80, 12},
    {"Tom", 60, 10},
    {"Mary", 40, 8},
    {"John", 20, 6}
};

Weapon weapons[MAX_WEAPONS] = {
    {"Sword", 20, 80},
    {"Bow and Arrow", 15, 60},
    {"Spear", 10, 70}
};

int main() {
    int i, j, player_health = 100, player_weapon = 0, current_enemy = 0;
    char input;

    printf("Welcome to the Space Adventure!\n");

    // Generate a random weapon for the player
    player_weapon = rand() % MAX_WEAPONS;

    // Initialize the game loop
    while (player_health > 0 && enemies[current_enemy].health > 0) {
        // Display the current enemy's name and health
        printf("Current Enemy: %s, Health: %d\n", enemies[current_enemy].name, enemies[current_enemy].health);

        // Display the player's weapon name and damage
        printf("Your Weapon: %s, Damage: %d\n", weapons[player_weapon].name, weapons[player_weapon].damage);

        // Get the player's input
        printf("Enter your move (attack, defend, flee): ");
        scanf("%c", &input);

        // Process the player's input
        switch (input) {
            case 'a':
                // Attack the enemy
                enemies[current_enemy].health -= weapons[player_weapon].damage;
                printf("You attacked the enemy for %d damage.\n", weapons[player_weapon].damage);
                break;
            case 'd':
                // Defend against the enemy's attack
                printf("You defended against the enemy's attack.\n");
                break;
            case 'f':
                // Flee from the enemy
                current_enemy = rand() % MAX_ENEMIES;
                printf("You fled from the enemy.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the enemy is dead
        if (enemies[current_enemy].health <= 0) {
            printf("You defeated the enemy!\n");
            current_enemy = rand() % MAX_ENEMIES;
        }

        // Check if the player is dead
        if (player_health <= 0) {
            printf("You have died. Game Over!\n");
            return 0;
        }
    }

    // End of the game loop

    printf("Congratulations! You have won the Space Adventure!\n");

    return 0;
}