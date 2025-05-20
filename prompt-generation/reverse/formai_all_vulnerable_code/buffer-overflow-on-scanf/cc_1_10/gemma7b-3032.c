//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_GUESSES 5

int main()
{
    int guess_num;
    int target_num;
    int num_guesses = 0;
    char play_again = 'y';

    // Generate a random target number between 1-100
    target_num = rand() % 100 + 1;

    // Loop until the player guesses the target number or runs out of guesses
    while (num_guesses < MAX_NUM_GUESSES && guess_num != target_num)
    {
        // Get the player's guess
        printf("Enter your guess: ");
        scanf("%d", &guess_num);

        // Check if the guess is correct
        if (guess_num == target_num)
        {
            printf("Congratulations! You guessed the target number.\n");
        }
        else
        {
            // Increment the number of guesses
            num_guesses++;

            // Give feedback on the guess
            if (guess_num < target_num)
            {
                printf("Your guess is too low. The target number is higher.\n");
            }
            else
            {
                printf("Your guess is too high. The target number is lower.\n");
            }
        }
    }

    // See if the player wants to play again
    printf("Do you want to play again? (y/n): ");
    scanf("%c", &play_again);

    // If the player wants to play again, start the game over
    if (play_again == 'y')
    {
        main();
    }

    return 0;
}