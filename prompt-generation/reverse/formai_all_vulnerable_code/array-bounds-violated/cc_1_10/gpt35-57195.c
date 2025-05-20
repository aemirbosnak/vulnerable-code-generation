//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_HEALTH 100
#define MAX_SHIELDS 50

int playerHealth = MAX_HEALTH;
int playerShields = MAX_SHIELDS;
int playerCredits = 0;
int currentSector = 1;
int enemiesDefeated = 0;

typedef struct {
    int health;
    int shields;
} Enemy;

void printHeader() {
    printf("SPACE ADVENTURE\n");
    printf("---------------------------\n");
}

void printStats() {
    printf("Health: %d/100 - Shields: %d/50 - Credits: %d\n", playerHealth, playerShields, playerCredits);
}

void printEnemies(Enemy enemies[], int numEnemies) {
    int i;
    printf("ENEMIES:\n");
    for (i = 0; i < numEnemies; i++) {
        printf("%d. Health: %d - Shields: %d\n", i + 1, enemies[i].health, enemies[i].shields);
    }
}

int promptAction() {
    int choice;
    printf("What will you do?\n");
    printf("1. Attack enemy\n");
    printf("2. Run away\n");
    scanf("%d", &choice);
    return choice;
}

void startNewSector() {
    printf("\n\n************\n\n");
    printf("SECTOR %d\n", currentSector);
    printf("\n\n************\n\n");
    
    int numEnemies = rand() % MAX_ENEMIES + 1; // Random number of enemies between 1 and MAX_ENEMIES
    Enemy enemies[numEnemies];
    int i;
    
    for (i = 0; i < numEnemies; i++) {
        enemies[i].health = rand() % MAX_HEALTH + 1; // Random enemy health between 1 and MAX_HEALTH
        enemies[i].shields = rand() % MAX_SHIELDS + 1; // Random enemy shields between 1 and MAX_SHIELDS
    }
    
    printEnemies(enemies, numEnemies);
    
    int action = promptAction();
    if (action == 1) {
        int attackChoice;
        printf("Which enemy will you attack? (Enter number)\n");
        scanf("%d", &attackChoice);
        if (attackChoice <= numEnemies) {
            Enemy enemy = enemies[attackChoice - 1];
            int damage = rand() % 50 + 1;
            int shieldDamage = rand() % 25 + 1;
            
            printf("You attack the enemy and deal %d damage\n", damage);
            enemy.health -= damage;
            
            if (enemy.shields > 0) {
                printf("The enemy's shields take %d damage\n", shieldDamage);
                enemy.shields -= shieldDamage;
            }
            
            if (enemy.health <= 0) {
                printf("The enemy has been defeated!\n");
                playerCredits += rand() % 100 + 1;
                enemiesDefeated++;
            } else {
                printf("The enemy has %d health left\n", enemy.health);
            }
            
            if (enemiesDefeated >= numEnemies) {
                printf("All enemies have been defeated!\n");
                currentSector++;
                startNewSector();
            } else {
                startNewSector();
            }
        } else {
            printf("Invalid choice\n");
        }
    } else if (action == 2) {
        printf("You run away\n");
    } else {
        printf("Invalid choice\n");
    }
}

int main() {
    srand(time(NULL));
    printHeader();
    startNewSector();
    return 0;
}