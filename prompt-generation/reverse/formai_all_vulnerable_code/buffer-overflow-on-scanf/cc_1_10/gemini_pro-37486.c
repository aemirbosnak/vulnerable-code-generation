//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Your starship's stats
typedef struct {
    int health;
    int energy;
    int shield;
    int credits;
} Starship;

// Enemy starships
typedef struct {
    char *name;
    int health;
    int energy;
    int shield;
    int credits;
} Enemy;

// Initialize the starship
Starship starship = {
    .health = 100,
    .energy = 100,
    .shield = 100,
    .credits = 0
};

// Current enemy
Enemy *enemy;

// Game loop
int main() {
    srand(time(NULL));

    while (starship.health > 0) {
        // Generate a random enemy
        enemy = malloc(sizeof(Enemy));
        enemy->name = "Enemy";
        enemy->health = rand() % 100;
        enemy->energy = rand() % 100;
        enemy->shield = rand() % 100;
        enemy->credits = rand() % 100;

        // Display the enemy's stats
        printf("Enemy: %s\n", enemy->name);
        printf("Health: %d\n", enemy->health);
        printf("Energy: %d\n", enemy->energy);
        printf("Shield: %d\n", enemy->shield);
        printf("Credits: %d\n", enemy->credits);

        // Player's turn
        char input;
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Use item\n");
        printf("3. Run away\n");
        scanf(" %c", &input);

        switch (input) {
            case '1':
                // Attack the enemy
                enemy->health -= 10;
                printf("You attacked the enemy for 10 damage!\n");
                if (enemy->health <= 0) {
                    printf("You defeated the enemy!\n");
                    starship.credits += enemy->credits;
                    free(enemy);
                }
                break;
            case '2':
                // Use an item
                printf("You don't have any items!\n");
                break;
            case '3':
                // Run away from the enemy
                printf("You ran away from the enemy!\n");
                free(enemy);
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        // Enemy's turn
        if (enemy->health > 0) {
            // Attack the starship
            starship.health -= 10;
            printf("The enemy attacked you for 10 damage!\n");
            if (starship.health <= 0) {
                printf("You were defeated!\n");
                return 0;
            }
        }
    }

    printf("You won!\n");
    return 0;
}