//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int upper, lower, num, guess, attempts = 0;

    printf("Welcome to the Guessing Game!\n\n");

    // Set the range for the random number
    printf("Enter the lower bound: ");
    scanf("%d", &lower);

    printf("Enter the upper bound: ");
    scanf("%d", &upper);

    printf("\nI am thinking of a number between %d and %d. Can you guess what it is?\n\n", lower, upper);

    // Seed the random number generator
    srand(time(0));

    // Generate the random number
    num = generateRandomNumber(lower, upper);

    // Loop until the user guesses the correct number
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > num)
        {
            printf("Too high! Try again.\n");
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d attempt(s)!\n", attempts);
        }
    } while (guess != num);

    return 0;
}