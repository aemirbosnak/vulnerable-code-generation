//FormAI DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number
int getRandomNumber(int min, int max)
{
    srand(time(NULL));
    int randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int main()
{
    printf("Welcome to the surrealist world of C game programming!\n\n");

    // declare variables
    int userInput, randomNumber, guessCount = 0;
    char playerName[50];

    // get player's name
    printf("Before we begin, please enter your name: ");
    scanf("%s", playerName);

    // introduce the game
    printf("\nHello %s, let's play a game! I'll think of a number between 1 and 100, and you have to guess it.\n", playerName);

    // generate random number
    randomNumber = getRandomNumber(1, 100);

    // loop until player guesses the correct number
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &userInput);

        // check if the guess is correct
        if (userInput == randomNumber) {
            printf("Congratulations %s, you guessed the number in %d tries!\n", playerName, guessCount);
        }
        // if guess is too low
        else if (userInput < randomNumber) {
            printf("Nope! The number is higher than %d\n", userInput);
        }
        // if guess is too high
        else {
            printf("Nope! The number is lower than %d\n", userInput);
        }
        // increment guess count
        guessCount++;
    } while (userInput != randomNumber);

    // return 0 to indicate success
    return 0;
}