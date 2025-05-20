//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int num_guesses = 0;
    int guess = 0;
    int secret_num = 0;
    int upper_limit = 100;
    int lower_limit = 1;
    int range = upper_limit - lower_limit + 1;
    char play_again = 'y';
    int wins = 0;
    int losses = 0;
    float win_rate = 0.0;

    // Seed random number generator
    srand(time(NULL));

    // Play game until user chooses to quit
    while (play_again == 'y')
    {
        // Generate random secret number within range
        secret_num = (rand() % range) + lower_limit;

        // Play game until user guesses correctly
        while (guess != secret_num)
        {
            // Prompt user for guess
            printf("Guess a number between %d and %d: ", lower_limit, upper_limit);
            scanf("%d", &guess);
            num_guesses++;

            // Check if guess is within range
            if (guess < lower_limit || guess > upper_limit)
            {
                printf("Invalid guess! Please enter a number between %d and %d.\n", lower_limit, upper_limit);
                num_guesses--;
            }
            else
            {
                // Check if guess is correct
                if (guess == secret_num)
                {
                    printf("Congratulations! You guessed correctly in %d attempts.\n", num_guesses);
                    wins++;
                }
                else
                {
                    // Provide hint to user
                    if (guess > secret_num)
                    {
                        printf("Too high! Try again.\n");
                        upper_limit = guess - 1;
                    }
                    else
                    {
                        printf("Too low! Try again.\n");
                        lower_limit = guess + 1;
                    }
                }
            }
        }

        // Reset variables for next game
        num_guesses = 0;
        guess = 0;
        upper_limit = 100;
        lower_limit = 1;
        range = upper_limit - lower_limit + 1;

        // Prompt user to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        printf("\n");

        // Update win rate
        win_rate = ((float)wins / (float)(wins + losses)) * 100.0;
    }

    // Print win rate statistics
    printf("Overall win rate: %0.2f%%\n", win_rate);
    printf("Total wins: %d\n", wins);
    printf("Total losses: %d\n", losses);

    return 0;
}