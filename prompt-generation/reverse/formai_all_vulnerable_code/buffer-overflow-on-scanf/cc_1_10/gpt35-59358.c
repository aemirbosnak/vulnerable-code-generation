//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max (inclusive)
int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to display the health of the spaceship
void displayHealth(int health) {
    printf("*************************************\n");
    printf("Spaceship Health: %d\n", health);
    printf("*************************************\n");
}

// Function to simulate a laser fight between the spaceship and an enemy ship
int laserFight(int health) {
    int enemyHealth = getRandom(50, 100);
    int laserDamage = getRandom(10, 20);
    int enemyLaserDamage = getRandom(5, 15);

    printf("Enemy Ship Health: %d\n", enemyHealth);

    while (health > 0 && enemyHealth > 0) {
        // Spaceship fires laser at enemy ship
        enemyHealth -= laserDamage;
        printf("\nSpaceship fires laser at enemy ship, doing %d damage. Enemy Ship Health: %d\n", laserDamage, enemyHealth);

        // Enemy ship fires laser at spaceship
        health -= enemyLaserDamage;
        printf("\nEnemy ship fires laser at spaceship, doing %d damage. Spaceship Health: %d\n", enemyLaserDamage, health);

        // Display health of spaceship
        displayHealth(health);
    }

    return health; // Return the health of the spaceship after the fight
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int health = 100;
    int choice;

    printf("Welcome to the Procedural Space Adventure!\n\n");

    do {
        printf("You are currently on the spaceship. What would you like to do?\n");
        printf("1. Go to the planet\n");
        printf("2. Check spaceship status\n");
        printf("3. Laser fight with enemy ship\n");
        printf("4. Quit game\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou land on the planet and discover a hidden treasure!\n");
                printf("You gain 20 health points.\n\n");
                health += 20;
                displayHealth(health);
                break;

            case 2:
                printf("\nSpaceship Status:\n");
                displayHealth(health);
                break;

            case 3:
                printf("\nYou encounter an enemy ship!\n");
                health = laserFight(health);
                if (health <= 0) {
                    printf("\nYour spaceship has been destroyed. Game over!\n");
                    return 0;
                }
                else {
                    printf("\nCongratulations! You have defeated the enemy ship and gained 30 health points.\n\n");
                    health += 30;
                    displayHealth(health);
                }
                break;

            case 4:
                printf("\nThank you for playing Procedural Space Adventure!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}