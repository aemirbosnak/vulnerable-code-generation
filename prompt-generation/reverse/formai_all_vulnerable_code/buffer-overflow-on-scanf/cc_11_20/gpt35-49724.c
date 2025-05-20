//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // initialize random number generator
    srand(time(NULL));

    // initialize game variables
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerAmmo = 10;
    int enemyAmmo = 10;
    int playerScore = 0;
    int enemyScore = 0;
    int playerTurn = 1;

    printf("CYBERPUNK DEATH MATCH\n\n");

    // game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        printf("PLAYER HEALTH: %d\n", playerHealth);
        printf("ENEMY HEALTH: %d\n", enemyHealth);
        printf("PLAYER AMMO: %d\n", playerAmmo);
        printf("ENEMY AMMO: %d\n", enemyAmmo);
        printf("PLAYER SCORE: %d\n", playerScore);
        printf("ENEMY SCORE: %d\n\n", enemyScore);

        if (playerTurn) {
            // player turn
            printf("YOUR MOVE:\n1) SHOOT\n2) DODGE\n");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                // player shoots
                if (playerAmmo > 0) {
                    // player has ammo
                    int hitChance = rand() % 100;
                    if (hitChance < 70) {
                        // player hits
                        printf("YOU HIT!\n");
                        enemyHealth -= 20;
                    } else {
                        // player misses
                        printf("YOU MISS!\n");
                    }
                    playerAmmo -= 1;
                } else {
                    // player has no ammo
                    printf("YOU ARE OUT OF AMMO!\n");
                }
            } else {
                // player dodges
                int dodgeChance = rand() % 100;
                if (dodgeChance < 50) {
                    // player successfully dodges
                    printf("YOU DODGE THE ENEMY'S ATTACK!\n");
                } else {
                    // player fails to dodge
                    printf("YOU FAIL TO DODGE THE ENEMY'S ATTACK!\n");
                    playerHealth -= 20;
                }
            }

            playerTurn = 0; // end player turn
        } else {
            // enemy turn
            int enemyChoice = rand() % 2;

            if (enemyChoice == 0) {
                // enemy shoots
                if (enemyAmmo > 0) {
                    // enemy has ammo
                    int hitChance = rand() % 100;
                    if (hitChance < 70) {
                        // enemy hits
                        printf("ENEMY HITS YOU!\n");
                        playerHealth -= 20;
                    } else {
                        // enemy misses
                        printf("ENEMY MISSES YOU!\n");
                    }
                    enemyAmmo -= 1;
                } else {
                    // enemy has no ammo
                    printf("ENEMY IS OUT OF AMMO!\n");
                }
            } else {
                // enemy dodges
                int dodgeChance = rand() % 100;
                if (dodgeChance < 50) {
                    // enemy successfully dodges
                    printf("ENEMY DODGES YOUR ATTACK!\n");
                } else {
                    // enemy fails to dodge
                    printf("ENEMY FAILS TO DODGE YOUR ATTACK!\n");
                    enemyHealth -= 20;
                }
            }

            playerTurn = 1; // end enemy turn
        }
    }

    // game over
    if (playerHealth <= 0) {
        printf("YOU LOSE!\n");
    } else {
        printf("YOU WIN!\n");
    }

    return 0;
}