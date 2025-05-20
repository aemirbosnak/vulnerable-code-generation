//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numSides, numDice, rollAgain, i, j;
    char again = 'y';
    srand(time(0));

    printf("Welcome to the Dice Roller program!\n");

    while (again == 'y' || again == 'Y') {

        printf("How many sides does your dice have? ");
        scanf("%d", &numSides);

        printf("How many dice are you rolling? ");
        scanf("%d", &numDice);

        printf("You rolled: ");

        for (i = 1; i <= numDice; i++) {

            printf("\n Dice %d: ", i);

            for (j = 1; j <= numSides; j++) {

                int randomRoll = rand() % numSides + 1;

                printf("%d ", randomRoll);
            }
            

        }
        printf("\n \n");

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &again);

        if (again == 'n' || again == 'N') {
            printf("Goodbye! \n");
            return 0;
        }
        else if (again != 'y' && again != 'Y') {
            printf("Invalid input, exiting program. \n");
            return 0;
        }

    }
    return 0;
}