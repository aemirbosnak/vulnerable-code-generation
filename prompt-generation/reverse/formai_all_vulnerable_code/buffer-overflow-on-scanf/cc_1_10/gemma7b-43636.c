//Gemma-7B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int score = 0;
    char name[20];
    time_t tStart, tEnd;

    printf("Enter your name: ");
    scanf("%s", name);

    tStart = time(NULL);

    // Game loop
    for (int i = 0; i < 10; i++)
    {
        // Generate a random number between 1-10
        int number = rand() % 10 + 1;

        // Check if the number is even or odd
        char evenOdd = number % 2 == 0 ? 'E' : 'O';

        // Display the number and ask the player to guess
        printf("Guess a number between 1-10: ");
        int guess = atoi(stdin);

        // Check if the guess is correct
        if (guess == number)
        {
            score++;
            printf("Congratulations! You guessed the number.\n");
        }
        else
        {
            printf("Sorry, that is not the number. The number was: %d.\n", number);
        }
    }

    tEnd = time(NULL);

    // Calculate the time taken
    int timeTaken = tEnd - tStart;

    // Display the final score and time taken
    printf("Your final score: %d\n", score);
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}