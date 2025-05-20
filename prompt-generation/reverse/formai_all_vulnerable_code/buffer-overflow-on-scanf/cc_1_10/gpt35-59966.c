//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a number 
int randomNumberGenerator(int limit) {
    int num;
    srand(time(NULL));
    num = rand() % limit;
    return num;
}

int main() {
    // Variable definitions
    int enemies[3] = {'G', 'O', 'D'};
    int enemyIndex, playerAnswer, playerHealth = 100, enemyHealth = 100;
    char playerName[20], playerWeapon;
    
    // Introduction to the game
    printf("Welcome to the world of Adventure! \n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Welcome %s! \n", playerName);
    printf("You are about to embark on a journey filled with danger and mysteries.\n");
    printf("Your mission is to defeat all the enemies and save the world from destruction. \n");
    printf("\n");

    // Choosing a weapon
    printf("Choose your weapon: \n");
    printf("A - Sword \n");
    printf("B - Bow and Arrow \n");
    printf("C - Magic Wand \n");
    printf("Enter your choice: ");
    scanf("%c", &playerWeapon);

    // Starting the game
    printf("\n");
    printf("Get ready to fight the enemies! \n");

    while (playerHealth > 0 && enemyHealth > 0) {
        // Selecting a random enemy to fight
        enemyIndex = randomNumberGenerator(3);
        printf("\n");
        printf("You have encountered an enemy %c \n", enemies[enemyIndex]);
        printf("What will you do? \n");
        printf("1 - Attack \n");
        printf("2 - Defend \n");
        printf("Enter your choice: ");
        scanf("%d", &playerAnswer);

        if (playerAnswer == 1) {
            // Attack scenario
            printf("You have attacked the enemy %c \n", enemies[enemyIndex]);
            enemyHealth = enemyHealth - randomNumberGenerator(20);
            printf("Enemy %c remaining health: %d \n", enemies[enemyIndex], enemyHealth);
        } else {
            // Defense scenario
            printf("You have defended against the enemy %c attack \n", enemies[enemyIndex]);
        }

        // Enemy attacks
        printf("\n");
        printf("Enemy attacks you \n");
        playerHealth = playerHealth - randomNumberGenerator(10);
        printf("Your remaining health: %d \n", playerHealth);
    }

    // Game over scenario
    if (playerHealth <= 0) {
        printf("\n");
        printf("You have lost the game! \n");
    } else {
        printf("\n");
        printf("Congratulations! You have defeated all the enemies and saved the world! \n");
    }

    return 0;
}