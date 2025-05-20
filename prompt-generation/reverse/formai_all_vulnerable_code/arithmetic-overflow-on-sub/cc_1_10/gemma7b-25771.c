//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define ROUND_NUM 5

int main()
{
    int num_guess, guess_history[ROUND_NUM], score = 0, target, time_start, time_end;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the target number
    target = rand() % MAX_NUM + 1;

    // Start the timer
    time_start = clock();

    // Allow the player to guess the number
    printf("Enter your guess: ");
    scanf("%d", &num_guess);

    // Check if the guess is correct
    if (num_guess == target)
    {
        // Increment the score
        score++;

        // Add the guess to the history
        guess_history[ROUND_NUM - 1] = num_guess;

        // End the timer
        time_end = clock();

        // Calculate the time taken
        int time_taken = time_end - time_start;

        // Display the results
        printf("Congratulations! You guessed the number in %d guesses.\n", score);
        printf("Your guess history: ");
        for (int i = 0; i < ROUND_NUM - 1; i++)
        {
            printf("%d ", guess_history[i]);
        }
        printf("\nTime taken: %d seconds", time_taken);
    }
    else
    {
        // Display an error message
        printf("Sorry, your guess is incorrect. The target number is %d.", target);
    }

    return 0;
}