//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, target, tries = 0;
    char play_again = 'y';

    printf("Welcome to Guess the Number!\n");

    while (play_again == 'y')
    {
        srand(time(NULL));
        target = rand() % 100 + 1;

        printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

        do
        {
            printf("Enter your guess:\n");
            scanf("%d", &guess);
            tries++;

            if (guess < target)
            {
                printf("Too low! Try again.\n");
            }
            else if (guess > target)
            {
                printf("Too high! Try again.\n");
            }

        } while (guess != target);

        printf("Congratulations! You guessed the number in %d tries.\n", tries);

        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &play_again);

        if (play_again != 'y' && play_again != 'n')
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            scanf(" %c", &play_again);
        }

        tries = 0;

        printf("\n"); // just to separate each game visually
    }

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}