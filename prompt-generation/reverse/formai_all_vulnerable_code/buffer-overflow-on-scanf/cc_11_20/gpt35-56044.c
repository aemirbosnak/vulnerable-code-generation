//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // for generating random numbers
    int playerHealth = 100, enemyHealth = 100, playerAttack, enemyAttack, turn = 1;
    printf("Welcome to Cyberpunk Battle!\n");
    printf("You are in a post-apocalyptic world and you have to fight against an enemy.\n");
    printf("You have 3 attack options: punch, shoot, and hack.\n");
    printf("You can only use hack once every 3 turns.\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nTurn %d\n", turn);
        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        int hackTurn = turn % 3; // check whether the hack attack can be used
        printf("Select your next move (1: punch, 2: shoot, 3: hack): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You punched the enemy!\n");
                playerAttack = rand() % 20 + 1; //generate a random number between 1-20
                enemyHealth -= playerAttack;
                printf("You dealt %d damage to the enemy.\n", playerAttack);
                break;
            case 2:
                printf("You shot the enemy!\n");
                playerAttack = rand() % 40 + 10; //generate a random number between 10-50
                enemyHealth -= playerAttack;
                printf("You dealt %d damage to the enemy.\n", playerAttack);
                break;
            case 3:
                if (hackTurn == 0) { // check if it's a valid turn for the hack attack
                    printf("You hacked the enemy!\n");
                    playerAttack = rand() % 50 + 50; //generate a random number between 50-100
                    enemyHealth -= playerAttack;
                    printf("You dealt %d damage to the enemy.\n", playerAttack);
                    break;
                } else {
                    printf("You can't use hack attack yet.\n");
                }
            default:
                printf("Invalid choice, try again.\n");
        }

        // check if the enemy is still alive before its turn
        if (enemyHealth > 0) {
            switch (rand() % 3 + 1) { //generate a random number between 1-3
                case 1:
                    printf("\nThe enemy punched you!\n");
                    enemyAttack = rand() % 20 + 1; //generate a random number between 1-20
                    playerHealth -= enemyAttack;
                    printf("The enemy dealt %d damage to you.\n", enemyAttack);
                    break;
                case 2:
                    printf("\nThe enemy shot you!\n");
                    enemyAttack = rand() % 40 + 10; //generate a random number between 10-50
                    playerHealth -= enemyAttack;
                    printf("The enemy dealt %d damage to you.\n", enemyAttack);
                    break;
                case 3:
                    printf("\nThe enemy hacked you!\n");
                    enemyAttack = rand() % 50 + 50; //generate a random number between 50-100
                    playerHealth -= enemyAttack;
                    printf("The enemy dealt %d damage to you.\n", enemyAttack);
                    break;
            }
        }

        turn++; //increment the turn counter
    }

    // check who wins or if it's a draw
    if (playerHealth <= 0 && enemyHealth <= 0) {
        printf("\nIt's a draw!\n");
    } else if (playerHealth <= 0) {
        printf("\nYou lost!\n");
    } else {
        printf("\nYou won!\n");
    }

    return 0;
}