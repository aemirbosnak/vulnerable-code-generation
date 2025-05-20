//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    int guess, secretNumber;
    int tries = 0;
    int upperBound, lowerBound;

    printf("Welcome to Guess the Number Game!\n\n");

    printf("Enter the lower bound of the secret number (must be a positive integer): ");
    scanf("%d", &lowerBound);

    printf("Enter the upper bound of the secret number (must be a positive integer): ");
    scanf("%d", &upperBound);

    srand(time(NULL)); // random seed

    secretNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;

    printf("\n\nYou will have 5 tries to guess the secret number.\n\n");

    while (tries < 5)
    {
        printf("Enter your guess (must be between %d and %d): ", lowerBound, upperBound);
        scanf("%d", &guess);

        if (guess < lowerBound || guess > upperBound)
        {
            printf("Invalid input. Please enter a number between %d and %d.\n", lowerBound, upperBound);
        }
        else if (guess == secretNumber)
        {
            printf("\nYou got it! The secret number is %d.\n\n", secretNumber);
            score += 100 - (tries * 10);
            printf("Your score is: %d\n\n", score);
            break; // exit the loop
        }
        else if (guess < secretNumber)
        {
            printf("Your guess is too low. Please try again.\n");
            tries++;
        }
        else if (guess > secretNumber)
        {
            printf("Your guess is too high. Please try again.\n");
            tries++;
        }
    }

    // if the player runs out of tries
    if (tries == 5)
    {
        printf("\nSorry, you failed to guess the secret number. The number was %d.\n\n", secretNumber);
    }

    return 0;
}