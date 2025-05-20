//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num_guess, guess_history[MAX_NUM] = {0}, target_num, attempts = 0;
    time_t t;

    t = time(NULL);

    // Generate a random target number between 1-10
    target_num = rand() % MAX_NUM + 1;

    // Start the game loop
    while (num_guess != target_num && attempts < MAX_NUM)
    {
        // Get the user's guess
        printf("Enter your guess: ");
        scanf("%d", &num_guess);

        // Check if the guess is valid
        if (num_guess < 1 || num_guess > MAX_NUM)
        {
            printf("Invalid guess. Please try again.\n");
            continue;
        }

        // Record the guess in history
        guess_history[attempts] = num_guess;

        // Check if the guess is correct
        if (num_guess == target_num)
        {
            printf("Congratulations! You guessed the target number in %d attempts.\n", attempts + 1);
            break;
        }

        // Increment the number of attempts
        attempts++;
    }

    // Print the time taken to guess the target number
    printf("Time taken: %.2f seconds.\n", (double)time(NULL) - t);

    // Print the guess history
    printf("Guess history: ");
    for (int i = 0; i < attempts; i++)
    {
        printf("%d ", guess_history[i]);
    }

    return 0;
}