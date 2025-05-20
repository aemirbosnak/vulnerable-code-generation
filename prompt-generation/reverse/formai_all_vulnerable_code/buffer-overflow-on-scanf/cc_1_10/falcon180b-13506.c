//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, lives = 3;
    int choice;
    char playAgain = 'y';

    srand(time(NULL));
    int enemyHealth = rand() % 10 + 1;

    while (playAgain == 'y') {
        system("clear");
        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);
        printf("Enemy Health: %d\n", enemyHealth);

        printf("\nChoose an option:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (score >= 10) {
                    score -= 10;
                    enemyHealth -= 10;
                } else {
                    printf("Not enough score!\n");
                }
                break;
            case 2:
                if (score >= 5) {
                    score -= 5;
                    lives++;
                } else {
                    printf("Not enough score!\n");
                }
                break;
            case 3:
                if (score >= 3) {
                    score -= 3;
                    lives = 3;
                } else {
                    printf("Not enough score!\n");
                }
                break;
            default:
                printf("Invalid option!\n");
        }

        if (enemyHealth <= 0) {
            printf("\nYou win!\n");
            playAgain = 'n';
        } else if (lives <= 0) {
            printf("\nYou lose!\n");
            playAgain = 'n';
        }
    }

    return 0;
}