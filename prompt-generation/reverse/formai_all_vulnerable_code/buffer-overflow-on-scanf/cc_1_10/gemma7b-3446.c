//Gemma-7B DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

int main()
{
    int score = 0, guess, attempts = 5;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! Let's play a game of Guess the Number.\n", name);

    // Generate a random number between 1 and 100
    int number = rand() % 100 + 1;

    // Loop until the player guesses the number or runs out of attempts
    while (score < number && attempts > 0)
    {
        printf("Guess a number: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == number)
        {
            score = number;
            attempts = 0;
            printf("Congratulations, %s! You guessed the number!\n", name);
        }
        else if (guess < number)
        {
            attempts--;
            printf("Too low, %s. Try again.\n", name);
        }
        else
        {
            attempts--;
            printf("Too high, %s. Try again.\n", name);
        }
    }

    // If the player runs out of attempts, display an error message
    if (attempts == 0)
    {
        printf("Sorry, %s. You ran out of attempts.\n", name);
    }

    // Display the final score
    printf("Your final score is: %d\n", score);

    return 0;
}