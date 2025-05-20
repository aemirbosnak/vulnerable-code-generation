//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num_guess, guess_history[MAX_NUM], num_tries = 5, is_correct = 0, target_num;

    srand(time(NULL));
    target_num = rand() % MAX_NUM + 1;

    // Display target number
    printf("The target number is: %d\n", target_num);

    // Get user guesses
    for (int i = 0; i < num_tries && is_correct == 0; i++)
    {
        printf("Enter your guess: ");
        scanf("%d", &num_guess);

        // Check if guess is correct
        if (num_guess == target_num)
        {
            is_correct = 1;
            printf("Congratulations! You guessed the number.\n");
        }
        else if (num_guess < target_num)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n");
        }

        // Store guess history
        guess_history[i] = num_guess;
    }

    // Display guess history
    if (is_correct == 0)
    {
        printf("Your guess history: ");
        for (int i = 0; i < num_tries; i++)
        {
            printf("%d ", guess_history[i]);
        }
        printf("\n");
    }

    return 0;
}