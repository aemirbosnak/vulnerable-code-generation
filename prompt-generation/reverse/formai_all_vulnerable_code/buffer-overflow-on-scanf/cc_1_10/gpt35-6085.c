//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Define game variables
    int answer, guess;
    int num_rounds = 0;
    int num_correct = 0;

    // Print welcome message
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have 5 chances to guess the number.\n");

    // Loop through 5 rounds
    for(int i = 0; i < 5; i++)
    {
        num_rounds++;

        // Generate random number between 1 and 100
        answer = rand() % 100 + 1;

        // Prompt user for guess
        printf("\nRound %d - Guess the number (1-100): ", num_rounds);
        scanf("%d", &guess);

        // Check if guess is correct
        if(guess == answer)
        {
            printf("Congratulations! You guessed the correct number.\n");
            num_correct++;
        }
        // Check if guess is too high or too low
        else if(guess > answer)
        {
            printf("Sorry, your guess is too high. The correct answer was %d.\n", answer);
        }
        else
        {
            printf("Sorry, your guess is too low. The correct answer was %d.\n", answer);
        }
    }

    // Print game summary
    printf("\nYou guessed %d out of %d correct.\n", num_correct, num_rounds);
    printf("Thank you for playing!\n");

    return 0;
}