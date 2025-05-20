//Gemma-7B DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    char name[20];
    printf("Welcome to the exciting game of Guess the Number!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hi, %s! Let's play!\n", name);

    // Generate a random number between 1 and 10
    int number = rand() % 10 + 1;

    // Set the number of guesses to 5
    int guesses = 5;

    // Start the game loop
    while (guesses > 0)
    {
        printf("Guess the number: ");
        int guess = atoi(scanf("%d"));

        // Check if the guess is correct
        if (guess == number)
        {
            printf("Congratulations, %s! You won!\n", name);
            score = 100;
            break;
        }
        else if (guess < number)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n");
        }

        // Decrement the number of guesses
        guesses--;
    }

    // If the player loses, display the final score
    if (score == 0)
    {
        printf("Sorry, %s. You lost. Your final score is: %d\n", name, score);
    }

    return 0;
}