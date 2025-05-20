//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print instructions at the start of the game
void printInstructions()
{
    printf("\nInstructions:\n");
    printf("1. You have 10 attempts to guess a number between 1 to 100.\n");
    printf("2. Each time you guess, I'll tell you if you're too high or too low.\n");
    printf("3. If you guess the correct number, you win!\n\n");
}

int main()
{
    // Initialize variables
    int number, guess, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    
    // Print instructions
    printInstructions();

    // Game loop
    while(tries < 10)
    {
        printf("Guess the number (Attempt %d): ", tries+1);
        scanf("%d", &guess);

        // Check if guessed number is too high or too low
        if(guess > number)
        {
            printf("Too high! Try again.\n");
        }
        else if(guess < number)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts!\n", tries+1);
            return 0;
        }
        
        tries++;
    }

    // If all attempts are used, print the correct number
    printf("Sorry, you've run out of attempts. The number was %d.\n", number);

    return 0;
}