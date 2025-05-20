//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    srand(time(NULL));
    int secretNum = rand() % 100 + 1;
    int guess;
    int numGuesses = 0;
    bool win = false;

    printf("\n============================================\n");
    printf("Welcome to the Guess the Number Game!\n");
    printf("You have 10 tries to guess the secret number.\n");
    printf("============================================\n");

    while(numGuesses < 10)
    {
        printf("\nEnter your guess (1-100): ");
        scanf("%d", &guess);

        if(guess < 1 || guess > 100)
        {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            continue;
        }

        numGuesses++;

        if(guess == secretNum)
        {
            win = true;
            break;
        }
        else if(guess > secretNum)
        {
            printf("Too high! ");
        }
        else
        {
            printf("Too low! ");
        }

        printf("You have %d guesses left.\n", 10 - numGuesses);
    }

    if(win)
    {
        printf("\n============================================\n");
        printf("Congratulations! You guessed the secret number (%d) in %d tries.\n", secretNum, numGuesses);
        printf("============================================\n");
    }
    else
    {
        printf("\n============================================\n");
        printf("Sorry, you ran out of guesses. The secret number was %d.\n", secretNum);
        printf("============================================\n");
    }

    return 0;
}