//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number between min and max
int getRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Print welcome message
    printf("Welcome to the Random Number Game!\n");
    printf("I will generate a random number between 1 and 100.\n");
    printf("You have 10 tries to guess the number.\n");
    printf("Good luck!\n");

    // Generate random number
    int randomNumber = getRandomNumber(1, 100);

    // Loop for 10 tries
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("\nTry %d: ", i);

        // Get user input
        int guess;
        scanf("%d", &guess);

        // Check if guess is correct
        if (guess == randomNumber)
        {
            printf("Congratulations! You guessed the number in %d tries.\n", i);
            break;
        }
        else if (guess < randomNumber)
        {
            printf("Too low. ");
        }
        else
        {
            printf("Too high. ");
        }
    }

    // Check if player ran out of tries
    if (i > 10)
    {
        printf("\nSorry, you ran out of tries. The number was %d.\n", randomNumber);
    }

    return 0;
}