//FormAI DATASET v1.0 Category: Table Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set the random seed
    srand(time(NULL));

    // Initialize game variables
    int points;
    char response;

    printf("Welcome to the C Table Game! \n");

    // Start game loop
    do {

        // Initialize round variables
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int total = dice1 + dice2;

        printf("\nYou rolled a %d and a %d, totaling %d\n", dice1, dice2, total);

        // Check if won or lost
        if (total == 7 || total == 11) {
            printf("Congratulations! You won!\n");
            points++;
        } else if (total == 2 || total == 3 || total == 12) {
            printf("Sorry, you lost.\n");
            points--;
        } else {
            int point = total;
            printf("You need to roll a %d to win!\n", point);

            while (1) {
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;
                total = dice1 + dice2;

                printf("\nYou rolled a %d and a %d, totaling %d\n", dice1, dice2, total);

                if (total == point) {
                    printf("Congratulations! You won!\n");
                    points++;
                    break;
                } else if (total == 7) {
                    printf("Sorry, you lost.\n");
                    points--;
                    break;
                }
            }
        }

        printf("\nPoints: %d\n", points);

        // Ask if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("\nYou ended with %d points. Thanks for playing!\n", points);

    return 0;
}