//FormAI DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\n\t******** Welcome to the Table Game ********\n\n");
    printf("Instructions:\n1. The player will roll two dice.\n2. If the sum is 7 or 11, player wins.\n3. If the sum is 2, 3, or 12, player loses.\n4. If the sum is anything else, that sum becomes the player's 'point'.\n5. The player will continue to roll two dice until either they roll their point (win) or a sum of 7 (lose).\n\n");

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int point = -1;
        int sum = 0;
        int rollNum = 1;
        srand(time(NULL));

        printf("Press enter to roll the dice\n");
        getchar();

        while (1) {
            int die1 = rand() % 6 + 1;
            int die2 = rand() % 6 + 1;
            sum = die1 + die2;

            printf("\nRoll #%d: %d + %d = %d\n", rollNum, die1, die2, sum);

            if (rollNum == 1) {
                if (sum == 7 || sum == 11) {
                    printf("\nYou win!\n");
                    break;
                } else if (sum == 2 || sum == 3 || sum == 12) {
                    printf("\nYou lose.\n");
                    break;
                } else {
                    point = sum;
                    printf("\nYour point is %d.\n", point);
                }
            } else {
                if (sum == 7) {
                    printf("\nYou lose.\n");
                    break;
                } else if (sum == point) {
                    printf("\nYou win!\n");
                    break;
                }
            }

            printf("Roll again? (y/n) ");
            scanf(" %c", &playAgain);

            if (playAgain == 'n' || playAgain == 'N') {
                break;
            }

            rollNum++;
        }

        printf("\n");
    }

    printf("\nThanks for playing the Table Game!\n");

    return 0;
}