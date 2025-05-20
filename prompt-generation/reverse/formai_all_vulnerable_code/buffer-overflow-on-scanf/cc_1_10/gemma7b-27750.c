//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
} Enemy;

Enemy enemies[MAX_ENEMIES];

void initializeEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].name[0] = '\0';
        enemies[i].health = 100;
        enemies[i].attack = 20 + i;
    }
}

int main() {
    initializeEnemies();

    // Seed the random number generator
    srand(time(NULL));

    // Create a hero
    char hero_name[20];
    printf("Enter hero name: ");
    scanf("%s", hero_name);

    int hero_health = 100;
    int hero_attack = 30;

    // Fight the enemies
    for (int i = 0; enemies[i].name[0] != '\0'; i++) {
        // Attack the enemy
        int damage = hero_attack - enemies[i].attack;
        enemies[i].health -= damage;

        // Check if the enemy is dead
        if (enemies[i].health <= 0) {
            printf("Enemy %s is dead!\n", enemies[i].name);
        } else {
            printf("Enemy %s has %d health remaining.\n", enemies[i].name, enemies[i].health);
        }
    }

    // Check if the hero is still alive
    if (hero_health > 0) {
        printf("You have won! Congratulations, %s!\n", hero_name);
    } else {
        printf("You have lost. Game over, %s.\n", hero_name);
    }

    return 0;
}