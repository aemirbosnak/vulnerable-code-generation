//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // to generate random numbers

    // initializing variables
    int guess, number, tries = 0; 
    number = rand() % 100 + 1; // generating a random number between 1 and 100

    // printing welcome message and instructions
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");

    // game loop
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess); // taking input from user

        // checking if guess is within range
        if (guess < 1 || guess > 100)
        {
            printf("Your guess is out of range. ");
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        // checking if guess is correct
        if (guess == number)
        {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
            break;
        }

        // giving hints if guess is incorrect
        if (guess < number)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > number)
        {
            printf("Too high! Try again.\n");
        }

        tries++; // incrementing the number of tries
    } while (guess != number);

    return 0;
}