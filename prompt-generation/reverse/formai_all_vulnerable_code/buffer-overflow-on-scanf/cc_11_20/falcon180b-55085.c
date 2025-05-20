//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides, total, i;
    int diceArray[100];
    char playAgain;

    do
    {
        printf("Enter the number of dice (1-100): ");
        scanf("%d", &numDice);
        if (numDice < 1 || numDice > 100)
        {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
        }
    } while (numDice < 1 || numDice > 100);

    do
    {
        printf("Enter the number of sides on each die (1-100): ");
        scanf("%d", &numSides);
        if (numSides < 1 || numSides > 100)
        {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
        }
    } while (numSides < 1 || numSides > 100);

    srand(time(NULL));
    for (i = 0; i < numDice; i++)
    {
        diceArray[i] = rand() % numSides + 1;
    }

    total = 0;
    for (i = 0; i < numDice; i++)
    {
        total += diceArray[i];
        printf("Dice %d rolled a %d.\n", i+1, diceArray[i]);
    }

    printf("The total is %d.\n", total);

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);
    if (playAgain == 'y' || playAgain == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for playing!\n");
    }

    return 0;
}