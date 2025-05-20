//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number
int generateRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Welcome message
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have 10 chances to guess the number between 1 and 100\n");
    printf("Let's begin...\n\n");

    // Generate the random number
    int randomNumber = generateRandom(1, 100);

    // Initialize variables
    int guess, tries = 10;

    // Main loop
    while (tries > 0)
    {
        // Prompt the user to guess the number
        printf("Guess the number: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == randomNumber)
        {
            printf("Congratulations! You have won the game in %d tries!\n", (10 - tries) + 1);
            break;
        }
        else
        {
            printf("Wrong answer.\n");

            // Check the range of the guess
            if (guess < randomNumber)
                printf("Hint: The number is higher.\n");
            else
                printf("Hint: The number is lower.\n");

            // Decrement the number of tries
            tries--;
        }

        // Display the number of remaining tries
        printf("You have %d tries left.\n\n", tries);
    }

    // If the user has used all of their tries, the game is lost
    if (tries == 0)
        printf("Game over. You have used all your tries. The number was %d.\n", randomNumber);

    return 0;
}