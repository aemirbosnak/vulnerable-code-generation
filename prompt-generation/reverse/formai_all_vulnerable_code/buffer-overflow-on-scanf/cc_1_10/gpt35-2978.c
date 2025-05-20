//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
/*
A simple number guessing game.
The user is given 5 chances to guess a randomly generated number in a range of 1 to 100.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, userGuess, attemptsRemaining = 5;

    // Generate a random number
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the number guessing game!\n");
    printf("You have 5 chances to guess a number between 1 and 100.\n");

    // Loop through 5 attempts
    for(int i=1; i<=5; i++)
    {
        printf("Attempt #%d: ", i);
        scanf("%d", &userGuess);

        // Check if the guess is correct
        if(userGuess == randomNumber)
        {
            printf("Congrats! You guessed the number.\n");
            return 0;
        }

        // Check if guess is too high or low
        else if(userGuess > randomNumber)
        {
            printf("Too high! ");
        }
        else
        {
            printf("Too low! ");
        }

        // Decrement attempts remaining
        attemptsRemaining--;

        // If there are attempts remaining, print them
        if(attemptsRemaining > 1)
        {
            printf("You have %d attempts remaining.\n", attemptsRemaining);
        }
        else if(attemptsRemaining == 1)
        {
            printf("You have 1 attempt remaining.\n");
        }
        else
        {
            printf("Sorry, you've run out of attempts. The number was %d.\n", randomNumber);
        }
    }

    return 0;
}