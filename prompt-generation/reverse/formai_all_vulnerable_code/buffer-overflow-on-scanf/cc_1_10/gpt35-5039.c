//FormAI DATASET v1.0 Category: Random ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for random numbers
    int min = 1; // Set the minimum value
    int max = 100; // Set the maximum value
    int num_of_guesses = 0; // Set number of guesses to zero
    int user_guess; // Variable for user's guess
    int secret_num = rand() % (max - min + 1) + min; // Generate random number between min and max, inclusive
    
    printf("***Welcome to the Random Number Guessing Game!***\n\n");
    printf("Guess a number between %d and %d\n", min, max);
    
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &user_guess); // Get user's guess
        
        num_of_guesses++; // Increment the number of guesses
        
        if(user_guess == secret_num) // Check if the user's guess is correct
        {
            printf("\n\nCongratulations! You guessed the secret number in only %d guesses!\n\n", num_of_guesses);
            
            printf("Do you want to play again? Enter 1 for Yes or 0 for No: ");
            int play_again;
            scanf("%d", &play_again);
            
            if(play_again == 1)
            {
                num_of_guesses = 0; // Reset the number of guesses
                secret_num = rand() % (max - min + 1) + min; // Generate a new random number
                printf("\n\n\n\n");
                printf("Guess a number between %d and %d\n", min, max);
            }
            else
            {
                printf("\n\nThank you for playing the Random Number Guessing Game!\n\n");
                break;
            }
        }
        else if(user_guess < secret_num) // Check if the user's guess is lower than the secret number
        {
            printf("Sorry, your guess is too low. Try again!\n");
        }
        else // Otherwise, the user's guess is higher than the secret number
        {
            printf("Sorry, your guess is too high. Try again!\n");
        }
        
    } while(1); // Infinite loop until the user chooses to quit
    
    return 0;
}