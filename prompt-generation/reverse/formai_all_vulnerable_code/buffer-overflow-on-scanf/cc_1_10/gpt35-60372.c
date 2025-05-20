//FormAI DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number
int generateRandomNumber(int n)
{
    srand(time(NULL)); //srand takes seed as an input and is defined inside stdlib.h
    return rand() % n;
}

int main()
{
    int number;
    int guess;
    int numberOfGuesses = 1;
    char playAgain = 'y';

    printf("\n***Guess the Number Game***\n");
    printf("\nRules:");
    printf("\n1. Enter a number between 1 and 100.");
    printf("\n2. You have 5 chances to guess the number correctly.");
    printf("\n3. Good Luck!\n");

    while (playAgain == 'y')
    {
        number = generateRandomNumber(100);
        numberOfGuesses = 1;

        printf("\nGuess the Number (Between 1 and 100): ");
        scanf("%d", &guess);

        while (numberOfGuesses <= 5)
        {
            if (guess > number)
            {
                printf("\nGuess Lower! You have %d chances left.", 5 - numberOfGuesses);
                printf("\nGuess the Number Again: ");
                scanf("%d", &guess);
                numberOfGuesses++;
            }
            else if (guess < number)
            {
                printf("\nGuess Higher! You have %d chances left.", 5 - numberOfGuesses);
                printf("\nGuess the Number Again: ");
                scanf("%d", &guess);
                numberOfGuesses++;
            }
            else
            {
                printf("\nCongratulations!!! You Guessed the Right Number %d in %d attempts!", number, numberOfGuesses);
                break;
            }
        }

        if (numberOfGuesses == 6)
            printf("\nSorry! You Lost. The Correct Number was %d", number);

        printf("\nDo You Want to Play Again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("\nThanks for Playing! Good Bye!!!\n");

    return 0;
}