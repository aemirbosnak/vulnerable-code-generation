//FormAI DATASET v1.0 Category: Game ; Style: grateful
// A Grateful C Game Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome the Player
    printf("Welcome to the Grateful C Game!\n\n");

    // Set up the game variables
    srand(time(NULL));
    int answer = rand() % 100 + 1;
    int guess, tries = 0;

    // Start the game loop
    do
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        tries++;

        if(guess > answer)
        {
            printf("Too high, try again!\n");
        }
        else if(guess < answer)
        {
            printf("Too low, try again!\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the right number in %d tries!\n\n", tries);
        }

        // End the game if the player has used up all of their tries
        if(tries >= 10)
        {
            printf("Sorry, you have used up all of your tries. The answer was %d. Please try again.\n", answer);
            return 0;
        }

    } while(guess != answer);

    // Thank the player for playing
    printf("Thank you for playing the Grateful C Game!\n");

    return 0;
}