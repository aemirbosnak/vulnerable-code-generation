//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int score = 0;
    int rand_num = 0;
    int rand_num_guess = 0;
    int guess = 0;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        rand_num_guess = rand() % 100 + 1;

        if (guess == rand_num_guess)
        {
            printf("You guessed it! The number was %d.\n", rand_num_guess);
            printf("Your score is: %d\n", score);
            break;
        }
        else
        {
            printf("Sorry, try again!\n");
        }

        if (guess > rand_num_guess)
        {
            printf("Too high, try again!\n");
        }
        else if (guess < rand_num_guess)
        {
            printf("Too low, try again!\n");
        }

        score++; // Increment the score with each guess
    }
    while (score < 5); // Continue until the player has guessed 5 times

    printf("Game over! The number was %d.\n", rand_num_guess);
    printf("Your score was %d.\n", score);

    return 0;
}