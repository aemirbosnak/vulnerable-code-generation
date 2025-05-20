//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game()
{
    int guess_number = 0;
    int target_number = rand() % 100 + 1;
    int attempts = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    // Loop until the user guesses the number or runs out of attempts
    while (guess_number != target_number && attempts < 5)
    {
        // Get the user's guess
        printf("Enter your guess: ");
        scanf("%d", &guess_number);

        // Check if the guess is correct
        if (guess_number == target_number)
        {
            printf("Congratulations! You guessed the number!\n");
        }
        else
        {
            // Increment the number of attempts
            attempts++;

            // Give feedback on the guess
            if (guess_number < target_number)
            {
                printf("Your guess is too low. The target number is higher.\n");
            }
            else
            {
                printf("Your guess is too high. The target number is lower.\n");
            }
        }
    }

    // If the user runs out of attempts, display the results
    if (attempts == 5)
    {
        printf("Sorry, you ran out of attempts. The target number was %d.\n", target_number);
    }
}

int main()
{
    play_game();

    return 0;
}