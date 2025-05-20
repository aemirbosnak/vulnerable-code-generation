//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHP = 100, enemyHP = 50;
    int attack = 0, defense = 0, playerChoice, randomEnemyAttack = 0;
    char playAgain = 'y';

    srand(time(NULL));

    while(playAgain == 'y' || playAgain == 'Y') {
        system("clear");

        printf("You have %d HP.\n", playerHP);
        printf("The enemy has %d HP.\n", enemyHP);
        printf("Choose an action:\n");
        printf("1. Attack\n2. Defend\n");
        scanf("%d", &playerChoice);

        switch(playerChoice) {
            case 1:
                attack = rand() % 10 + 1;
                printf("You attacked for %d damage!\n", attack);
                enemyHP -= attack;
                if(enemyHP <= 0) {
                    printf("You won! Play again? (y/n): ");
                    scanf(" %c", &playAgain);
                    playAgain = toupper(playAgain);
                }
                break;
            case 2:
                defense = rand() % 10 + 1;
                printf("You defended with %d armor!\n", defense);
                randomEnemyAttack = rand() % 10 + 1;
                if(randomEnemyAttack <= defense) {
                    printf("You avoided damage!\n");
                } else {
                    playerHP -= (randomEnemyAttack - defense);
                    printf("You took %d damage!\n", randomEnemyAttack - defense);
                    if(playerHP <= 0) {
                        printf("You lost...\n");
                        exit(0);
                    }
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}