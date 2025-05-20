//FormAI DATASET v1.0 Category: Game ; Style: careful
/* Unique C game example program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game instructions
void displayInstructions()
{
    printf("\n********** WELCOME TO THE GUESSING GAME **********\n");
    printf("\nINSTRUCTIONS: \n");
    printf("\n1. The computer will randomly choose a number between 1 and 100");
    printf("\n2. You have to guess the number within 5 attempts");
    printf("\n3. If your guess matches with the computer's chosen number, you win the game!");
    printf("\n4. If your guess is higher/lower than the computer's chosen number, the game will give you hints");
    printf("\n5. You can quit the game anytime by entering 0 as your guess\n");
}

int main()
{
    // Declare and initialize the variables
    int num, guess, nguesses = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    // Display the game instructions
    displayInstructions();

    // Start the game loop
    do
    {
        // Get the user's guess
        printf("\nEnter your guess between 1 and 100: ");
        scanf("%d", &guess);

        // Check if the user wants to quit
        if (guess == 0)
        {
            printf("\nYou have quit the game. Better luck next time!\n");
            break;
        }

        // Check if the guess is within the range
        if (guess < 1 || guess > 100)
        {
            printf("\nInvalid input! Your guess should be between 1 and 100\n");
            continue;
        }

        // Increase the number of guesses
        nguesses++;

        // Check if the user has won
        if (guess == num)
        {
            printf("\nCongratulations! You have won the game in %d attempts\n", nguesses);
            break;
        }

        // Give hints based on the user's guess
        if (guess > num)
        {
            printf("\nSorry, your guess is too high. Try again!\n");
        }
        else
        {
            printf("\nSorry, your guess is too low. Try again!\n");
        }

        // Check if the user has reached the maximum number of guesses
        if (nguesses == 5)
        {
            printf("\nYou have used all your attempts. Better luck next time!\n");
            break;
        }

        // Display the number of remaining guesses
        printf("\nYou have %d attempts left\n", 5 - nguesses);

    } while (nguesses < 5);

    // End the game
    printf("\nThank you for playing the game!\n");

    return 0;
}