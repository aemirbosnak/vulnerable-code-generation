//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize random seed
    srand(time(NULL));

    //declare variables
    int secretNum = rand() % 100 + 1;
    int guess = 0;
    int numGuesses = 1;

    //introduction
    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a secret number between 1 and 100.\n");
    printf("You have 10 chances to guess the number.\n\n");

    //game loop
    while(guess != secretNum && numGuesses <= 10)
    {
        printf("Guess #%d: ", numGuesses);
        scanf("%d", &guess);

        if(guess < secretNum)
        {
            printf("Too low!\n");
        }
        else if(guess > secretNum)
        {
            printf("Too high!\n");
        }

        numGuesses++;
    }

    //check if player won or lost
    if(guess == secretNum)
    {
        printf("\nCongratulations! You guessed the secret number in %d tries.\n", numGuesses-1);
    }
    else
    {
        printf("\nSorry, you ran out of guesses. The secret number was %d.\n", secretNum);
    }

    //exit program
    return 0;
}