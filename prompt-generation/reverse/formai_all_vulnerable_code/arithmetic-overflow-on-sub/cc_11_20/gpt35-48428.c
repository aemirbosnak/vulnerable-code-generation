//FormAI DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice1, dice2, score, point, rollCount, bet;
    char choice;

    srand(time(NULL));

    printf("Welcome to the C Table Game!\n\n");

    while (1) {
        score = 100;
        point = 0;
        rollCount = 0;

        printf("You have $%d to bet with.\n", score);
        printf("How much would you like to bet? ");
        scanf("%d", &bet);

        while (bet > score) {
            printf("You cannot bet more than you have.\n");
            printf("How much would you like to bet? ");
            scanf("%d", &bet);
        }

        printf("\nRolling the dice...\n");
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        rollCount++;
        printf("You rolled a %d and a %d for a total of %d.\n", dice1, dice2, dice1+dice2);

        if (dice1+dice2 == 2 || dice1+dice2 == 3 || dice1+dice2 == 12) {
            printf("Craps! You lose your bet.\n");
            score -= bet;
            if (score == 0) {
                printf("You're out of money!\n");
                return 0;
            }
            printf("You now have $%d left.\n", score);
        } else if (dice1+dice2 == 7 || dice1+dice2 == 11) {
            printf("Natural! You win your bet.\n");
            score += bet;
            printf("You now have $%d.\n", score);
        } else {
            point = dice1+dice2;
            printf("Your point is %d.\n", point);

            while (1) {
                printf("Rolling the dice...\n");
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;

                rollCount++;
                printf("You rolled a %d and a %d for a total of %d.\n", dice1, dice2, dice1+dice2);

                if (dice1+dice2 == point) {
                    printf("You match your point! You win your bet.\n");
                    score += bet;
                    printf("You now have $%d.\n", score);
                    break;
                } else if (dice1+dice2 == 7) {
                    printf("Seven out! You lose your bet.\n");
                    score -= bet;
                    if (score == 0) {
                        printf("You're out of money!\n");
                        return 0;
                    }
                    printf("You now have $%d left.\n", score);
                    break;
                }
            }
        }

        printf("\n");
        printf("You made %d rolls.\n", rollCount);
        printf("Would you like to play again? (Y/N) ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            printf("Thanks for playing!\n");
            return 0;
        } else if (choice == 'Y' || choice == 'y') {
            printf("\n");
        } else {
            printf("Invalid choice. Thanks for playing!\n");
            return 0;
        }
    }
    return 0;
}