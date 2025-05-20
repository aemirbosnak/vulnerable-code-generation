//FormAI DATASET v1.0 Category: Game ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Let's Play a Game!\n\n");

    int secret_number = rand() % 100 + 1;
    int guess;
    int guess_count = 0;
    int guess_limit = 7;
    int out_of_guesses = 0;

    printf("Guess the secret number between 1 and 100. You have 7 tries.\n");

    while (guess != secret_number && out_of_guesses == 0)
    {
        if (guess_count < guess_limit)
        {
            printf("Enter your guess: ");
            scanf("%d", &guess);

            if (guess < secret_number)
            {
                printf("Too low! Try again.\n\n");
            }
            else if (guess > secret_number)
            {
                printf("Too high! Try again.\n\n");
            }

            guess_count++;
        }
        else
        {
            out_of_guesses = 1;
        }
    }

    if (out_of_guesses == 1)
    {
        printf("You lose! The secret number was %d.\n\n", secret_number);
    }
    else
    {
        printf("Congratulations! You guessed the secret number %d in %d tries.\n\n", secret_number, guess_count);
    }

    return 0;
}