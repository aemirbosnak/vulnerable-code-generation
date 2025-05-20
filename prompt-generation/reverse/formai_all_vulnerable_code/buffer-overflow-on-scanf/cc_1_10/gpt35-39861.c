//FormAI DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rounds = 0, score = 0, guess = 0, num = 0;

    // Introduction
    printf("Welcome to Number Guessing Game!\n\n");
    printf("You have to guess a number between 1 to 100 within 5 rounds.\n");
    printf("Every right answer will give you 20 points.\n\n");

    // Generating random number
    srand(time(NULL));
    num = rand() % 100 + 1;

    // Game loop
    while (rounds < 5)
    {
        printf("\nRound %d\n", rounds + 1);
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Validating user input
        if (guess < 1 || guess > 100)
        {
            printf("Invalid input! Enter a number between 1 and 100.\n");
            continue;
        }

        // Checking if the guess is correct
        if (guess == num)
        {
            printf("Congratulations! You have guessed the number.\n");
            score += 20;
            rounds++;
            num = rand() % 100 + 1;
            continue;
        }

        // Guiding the user to make a better guess
        if (guess < num)
        {
            printf("Your guess is lower than the number.\n");
        }
        else
        {
            printf("Your guess is higher than the number.\n");
        }

        // Decreasing the number of remaining rounds
        rounds++;
    }

    // Displaying the final score
    printf("\nYour final score is %d.\n\n", score);

    return 0;
}