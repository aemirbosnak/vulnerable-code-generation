//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_SHIP_HEALTH 100
#define MAX_ENEMY_HEALTH 50
#define MAX_ENEMY_DAMAGE 10

// Struct for the player's ship
typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
    int credits;
} Ship;

// Struct for enemy ships
typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
} Enemy;

// Function to initialize a new ship
void initializeShip(Ship *ship) {
    printf("Enter a name for your ship: ");
    scanf("%s", ship->name);
    ship->health = MAX_SHIP_HEALTH;
    ship->damage = 10;
    ship->credits = 0;

    printf("\nWelcome aboard the %s!\n", ship->name);
}

// Function to initialize a new enemy ship
void initializeEnemy(Enemy *enemy) {
    char *names[] = {"Zorg", "Skrull", "Kree", "Chitauri", "Sakaaran"};
    strcpy(enemy->name, names[rand() % 5]);
    enemy->health = MAX_ENEMY_HEALTH;
    enemy->damage = MAX_ENEMY_DAMAGE;
}

// Function to handle combat between the player's ship and an enemy ship
void combat(Ship *ship, Enemy *enemy) {
    int playerRoll, enemyRoll;

    printf("\nYou have encountered an enemy ship!\n");
    while (ship->health > 0 && enemy->health > 0) {
        // Player attacks first
        playerRoll = rand() % 6 + 1;
        printf("You attack the enemy with a roll of %d.\n", playerRoll);
        enemy->health -= ship->damage * playerRoll;

        if (enemy->health <= 0) {
            printf("You have defeated the %s and gained 10 credits!\n", enemy->name);
            ship->credits += 10;
            break; // End the combat loop
        }

        // Enemy attacks
        enemyRoll = rand() % 6 + 1;
        printf("The enemy attacks you with a roll of %d.\n", enemyRoll);
        ship->health -= enemy->damage * enemyRoll;

        if (ship->health <= 0) {
            printf("Your ship has been destroyed. Game Over.\n");
            exit(0); // Exit the program
        }

        printf("Your ship has %d health remaining.\n", ship->health);
        printf("The enemy ship has %d health remaining.\n", enemy->health);
        printf("Press enter to continue combat...");
        getchar();
    }
}

int main() {
    srand(time(NULL));
    Ship playerShip;
    Enemy enemyShip;

    initializeShip(&playerShip);
    while (1) {
        initializeEnemy(&enemyShip);
        combat(&playerShip, &enemyShip);
        printf("You now have %d credits. Keep exploring the galaxy!\n", playerShip.credits);
        printf("Press enter to continue exploring...");
        getchar(); // Wait for user input to continue exploring
    }

    return 0;
}