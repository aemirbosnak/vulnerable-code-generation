//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // variable initialization
    int seed, number, guess, attempts, attempt_count = 1;

    // initialize random number generator
    srand(time(0));

    // generate random number between 1 and 100
    number = rand() % 100 + 1;

    // ask user for seed value
    printf("Welcome to Curious Number Guessing Game!\n");
    printf("Please enter a seed value: ");
    scanf("%d", &seed);

    // set random number generator seed
    srand(seed);

    // ask user for number of attempts
    printf("Please enter the number of attempts: ");
    scanf("%d", &attempts);

    // start game loop
    while (attempt_count <= attempts)
    {
        // ask user for guess
        printf("\nAttempt #%d: Guess the number between 1 and 100: ", attempt_count);
        scanf("%d", &guess);

        // check if guess is correct
        if (guess == number)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempt_count);
            exit(0);
        }
        else if (guess < number)
        {
            printf("Oops! Your guess was too low.\n");
        }
        else
        {
            printf("Oops! Your guess was too high.\n");
        }

        // increment attempt count
        attempt_count++;
    }

    // if number of attempts exceeded
    printf("Sorry, you have exceeded the maximum number of attempts.\n");
    printf("The number was %d. Better luck next time!\n", number);

    return 0;
}