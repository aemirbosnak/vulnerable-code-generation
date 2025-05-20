//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, attempts = 0;

    srand(time(0)); // seed for random number generator
    
    num = rand() % 100 + 1; // generates random number between 1 and 100

    printf("--- Welcome to the Guessing Game! ---\n\n");
    printf("I have picked a number between 1 and 100, try to guess it in less than 10 attempts.\n");

    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > num)
        {
            printf("Too high. Guess again.\n");
        }
        else if (guess < num)
        {
            printf("Too low. Guess again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);

            if (attempts <= 5)
            {
                printf("Wow, you're a natural at this!\n");
            }
            else if (attempts <= 8)
            {
                printf("Great job!\n");
            }
            else
            {
                printf("Better luck next time.\n");
            }
        }
    } while (guess != num && attempts < 10);

    if (guess != num)
    {
        printf("\nSorry, you failed to guess the number in 10 attempts. The number was %d.\n", num);
    }

    return 0;
}