//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 20

int main()
{
    int number_to_guess;
    int guess;
    int num_guesses = 0;
    int done = 0;

    // Generate a random number
    srand(time(NULL));
    number_to_guess = rand() % MAX_NUMBER + 1;

    printf("I'm thinking of a number between 1 and %d. You have %d guesses.\n", MAX_NUMBER, MAX_GUESSES);

    while (!done)
    {
        printf("Guess a number: ");
        scanf("%d", &guess);

        if (guess == number_to_guess)
        {
            printf("Correct! You win!\n");
            done = 1;
        }
        else if (guess > number_to_guess)
        {
            printf("Too high.\n");
        }
        else
        {
            printf("Too low.\n");
        }

        num_guesses++;

        if (num_guesses >= MAX_GUESSES)
        {
            printf("You're out of guesses. The number was %d.\n", number_to_guess);
            done = 1;
        }
    }

    return 0;
}