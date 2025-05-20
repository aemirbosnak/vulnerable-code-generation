//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int enemyScore = 0;
    int playerHealth = 100;
    int enemyHealth = 100;

    char playerName[20];
    printf("Enter your name: ");
    scanf("%s", playerName);

    while(playerHealth > 0 && enemyHealth > 0) {
        int attackResult = rand() % 3;
        if(attackResult == 0) {
            printf("%s missed!\n", playerName);
        } else if(attackResult == 1) {
            printf("%s hit the enemy for 10 damage!\n", playerName);
            enemyHealth -= 10;
        } else {
            printf("%s hit the enemy for 20 damage!\n", playerName);
            enemyHealth -= 20;
        }

        attackResult = rand() % 3;
        if(attackResult == 0) {
            printf("The enemy missed!\n");
        } else if(attackResult == 1) {
            printf("The enemy hit %s for 10 damage!\n", playerName);
            playerHealth -= 10;
        } else {
            printf("The enemy hit %s for 20 damage!\n", playerName);
            playerHealth -= 20;
        }

        if(playerHealth <= 0) {
            printf("%s has been defeated!\n", playerName);
            break;
        } else if(enemyHealth <= 0) {
            printf("The enemy has been defeated!\n");
            break;
        }
    }

    if(playerHealth > 0) {
        printf("%s has won the battle!\n", playerName);
    } else {
        printf("Game over. Play again? (y/n): ");
        char playAgain;
        scanf("%c", &playAgain);
        if(playAgain == 'y' || playAgain == 'Y') {
            main();
        }
    }

    return 0;
}