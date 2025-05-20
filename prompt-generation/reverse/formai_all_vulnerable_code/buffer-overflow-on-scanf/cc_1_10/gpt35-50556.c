//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator using current time

    // Initializations
    int playerHealth = 100;
    int monsterHealth = 100;
    int playerDamage = 10;
    int monsterDamage = 5;

    printf("Welcome to the Scientific Adventure Game!\n");

    // Main game loop
    while (playerHealth > 0 && monsterHealth > 0) {
        printf("\nPlayer Health: %d\n", playerHealth);
        printf("Monster Health: %d\n", monsterHealth);

        printf("\nWhat do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");

        int choice;
        scanf("%d", &choice);

        // Player makes a choice
        switch (choice) {
            case 1:  // Attack
                printf("\nYou attack the monster!\n");
                int damage = rand() % playerDamage + 1;
                monsterHealth -= damage;
                printf("You deal %d damage to the monster!\n", damage);
                break;

            case 2:  // Defend
                printf("\nYou defend yourself!\n");
                int reduce = rand() % playerDamage + 1;
                playerDamage -= reduce;
                printf("Your defense is strengthened! Your damage reduced by %d.\n", reduce);
                break;

            default:  // Invalid choice
                printf("\nInvalid choice! Try again.\n");
                continue;
        }

        if (monsterHealth <= 0) break;  // Player wins

        // Monster attacks
        printf("\nThe monster attacks you!\n");
        int damage = rand() % monsterDamage + 1;
        playerHealth -= damage;
        printf("The monster deals %d damage to you!\n", damage);

        if (playerHealth <= 0) break;  // Player loses
    }

    if (playerHealth > 0) {
        printf("\nCongratulations! You have defeated the monster and won the game!\n");
    } else {
        printf("\nGame over! You were defeated by the monster.\n");
    }

    return 0;
}