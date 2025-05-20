//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int num, guess, guesses = 0;

    // Generate a random number between 1 and 100
    srand(time(NULL));
    num = rand() % 100 + 1;

    // Welcome message and instructions
    printf("Welcome to the Guessing Game!\n");
    printf("Can you guess the secret number between 1 and 100?\n\n");

    // Keep prompting the user for guesses until they guess correctly or run out of guesses
    while(guesses < 10) 
    {
        printf("Guess #%d: ", guesses + 1);
        scanf("%d", &guess);
        
        // Make sure the user entered a valid guess
        if(guess < 1 || guess > 100) 
        {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }

        // Increment the number of guesses and give feedback to the user
        guesses++;
        if(guess < num) 
        {
            printf("Too low! Try again.\n");
        } 
        else if(guess > num) 
        {
            printf("Too high! Try again.\n");
        } 
        else 
        {
            printf("Congratulations! You guessed the correct number in %d guesses.\n", guesses);
            break;
        }
    }

    // If the user ran out of guesses, tell them they lost
    if(guesses == 10) 
    {
        printf("Sorry, you ran out of guesses. The secret number was %d.", num);
    }

    return 0;
}