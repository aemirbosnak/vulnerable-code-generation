//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, randomNumber, numOfGuesses = 0;
    char playAgain = 'y';

    srand(time(NULL)); // seed for random number generator

    while (playAgain == 'y')
    {
        randomNumber = rand() % 100 + 1; // random number between 1 and 100
        numOfGuesses = 0;

        printf("Welcome to Guess the Number!\n\n");

        do
        {
            printf("Guess a number between 1 and 100: ");
            scanf("%d", &guess);
            numOfGuesses++;

            if (guess > randomNumber)
            {
                printf("Too high!\n");
            }
            else if (guess < randomNumber)
            {
                printf("Too low!\n");
            }
            else
            {
                printf("Congratulations, you guessed the number in %d tries!\n", numOfGuesses);
            }
        } while (guess != randomNumber);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        if (playAgain == 'y')
        {
            printf("\nLet's play again!\n\n");
        }
    }

    printf("\nThanks for playing Guess the Number!\n");

    return 0;
}