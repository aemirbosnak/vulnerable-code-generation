//FormAI DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare variables
    int guess;
    int randNum = rand() % 100 + 1;
    int attempts = 0;
    char playAgain = 'y';
    
    printf("Welcome to the game of guessing!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Take a guess: ");
    
    // Loop until user wins or chooses to quit
    while (playAgain == 'y')
    {
        scanf("%d", &guess);
        
        // Check if guess is valid
        if (guess > 100 || guess < 1)
        {
            printf("Please enter a number between 1 and 100.\n");
            printf("Take another guess: ");
        }
        else
        {
            // Increment attempts
            attempts++;
            
            // Check if guess is correct
            if (guess == randNum)
            {
                printf("Congratulations! You guessed my number in %d attempts.\n", attempts);
                printf("Would you like to play again? (y/n) ");
                scanf(" %c", &playAgain);
                
                // Reset variables for new game
                randNum = rand() % 100 + 1;
                attempts = 0;
                
                if (playAgain == 'y')
                {
                    printf("I am thinking of a number between 1 and 100.\n");
                    printf("Take a guess: ");
                }
                else
                {
                    printf("Thank you for playing!\n");
                }
            }
            else if (guess > randNum)
            {
                printf("Too high! Try again: ");
            }
            else
            {
                printf("Too low! Try again: ");
            }
        }
    }
    
    return 0;
}