//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandom()
{
    srand(time(0)); 
    int randomNum = rand() % 100 + 1; 
    return randomNum;
}

int main()
{
    printf("Welcome to the Visionary Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have 10 chances to guess the number.\n");

    int numToGuess = generateRandom();
    int numOfGuesses = 0;
    int guess;

    while (numOfGuesses < 10) {
        printf("Guess #%d: ", numOfGuesses+1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Please enter a number between 1 and 100.\n");
            continue;
        }

        if (guess == numToGuess) {
            printf("Congratulations! You've guessed the number in just %d attempt(s)!\n", numOfGuesses+1);
            return 0;
        } else if (guess < numToGuess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        numOfGuesses++;
    }

    if (numOfGuesses == 10) {
        printf("Sorry, you've run out of chances to guess the number. The correct number was %d.\n", numToGuess);
        return 0;
    }

    return 0;
}