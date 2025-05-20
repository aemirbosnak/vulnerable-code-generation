//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

// Function to play game
int playGame(int n)
{
    int randomNumber = generateNumber(n);
    int guess, attempts = 0;

    do
    {
        printf("Guess a number between 0 and %d: ", n - 1);
        scanf("%d", &guess);
        attempts++;

        if (guess > randomNumber)
        {
            printf("Lower number please!\n");
        }
        else if (guess < randomNumber)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("You guessed it in %d attempts!\n", attempts);
            return 0;
        }
    } while (1);
}

int main()
{
    int choice, n = 100;

    do
    {
        printf("\n---Welcome to the Number Guessing Game---\n");
        printf("\n1. Play game");
        printf("\n2. Set Maximum Number to play with (currently %d)", n);
        printf("\n3. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            playGame(n);
            break;

        case 2:
            printf("Enter maximum value for the game: ");
            scanf("%d", &n);
            break;

        case 3:
            printf("Thanks for playing!");
            exit(0);

        default:
            printf("Invalid choice! Try Again!");
        }

    } while (1);

    return 0;
}