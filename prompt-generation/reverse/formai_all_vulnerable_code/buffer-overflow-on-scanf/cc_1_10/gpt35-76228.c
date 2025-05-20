//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100, bossHealth = 200, playerAttack = 10, bossAttack = 20;
    int playerPotion = 3, bossPotion = 2; // each potion restores 30 hp
    int round = 0, playerChoice;

    srand(time(0)); // random seed based on current time

    printf("===== Welcome to Boss Battle! =====\n");
    printf("You, the player, have 100 health and 10 attack.\n");
    printf("Your opponent, the boss, has 200 health and 20 attack.\n");

    while (playerHealth > 0 && bossHealth > 0) {
        round++;
        printf("\n===== ROUND %d =====\n", round);
        printf("Boss health: %d, Player health: %d\n", bossHealth, playerHealth);
        printf("1. Attack\n2. Use potion (%d left)\n", playerPotion);
        scanf("%d", &playerChoice);

        if (playerChoice == 1) {
            int damage = playerAttack + rand() % 6; // random damage between 10 to 15
            printf("Player attacks boss and deals %d damage!\n", damage);
            bossHealth -= damage;
        } else if (playerChoice == 2) {
            if (playerPotion == 0) {
                printf("You are out of potions!\n");
            } else {
                int healed = 30;
                playerHealth += healed;
                playerPotion--;
                printf("Player uses potion and restores %d health!\n", healed);
            }
        } else {
            printf("Invalid choice, please try again.\n");
        }

        if (bossHealth <= 0) {
            printf("\nPlayer wins! Congrats!\n");
            break;
        }

        // Boss turn
        int randomChoice = rand() % 2;
        if (randomChoice == 0) {
            int damage = bossAttack + rand() % 6; // random damage between 20 to 25
            printf("Boss attacks player and deals %d damage!\n", damage);
            playerHealth -= damage;
        } else {
            if (bossPotion == 0) {
                printf("Boss has no more potions left!\n");
            } else {
                int healed = 30;
                bossHealth += healed;
                bossPotion--;
                printf("Boss uses potion and restores %d health!\n", healed);
            }
        }

        if (playerHealth <= 0) {
            printf("\nPlayer has been defeated. Game over.\n");
            break;
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}