//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define function prototypes
void displayIntro();
int chooseDifficulty();
int generateRandomNumber(int, int);
void play(int);

int main()
{
    // seed the random number generator
    srand(time(NULL));

    // display game intro
    displayIntro();

    // set game difficulty level
    int difficulty = chooseDifficulty();

    // play game
    play(difficulty);

    return 0;
}

/**
 * Displays game introduction
 */
void displayIntro()
{
    printf("Welcome to the Guessing Game!\n\n");
    printf("In this game, a random number will be generated and you have to guess it correctly.\n");
    printf("You can set the difficulty level: easy, medium, or hard.\n\n");
}

/**
 * Allows player to choose game difficulty level
 * Returns the range of possible random numbers based on the difficulty level
 */
int chooseDifficulty()
{
    int difficulty;
    printf("Please choose a difficulty level:\n");
    printf("1. Easy: Random number between 1 and 10\n");
    printf("2. Medium: Random number between 1 and 50\n");
    printf("3. Hard: Random number between 1 and 100\n");

    // loop until valid input is chosen
    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &difficulty);
    } while (difficulty < 1 || difficulty > 3);

    // return range of possible random numbers
    switch (difficulty) {
        case 1:
            return 10;
        case 2:
            return 50;
        case 3:
            return 100;
        default:
            return 0;
    }
}

/**
 * Generates a random number within a specified range
 */
int generateRandomNumber(int minRange, int maxRange)
{
    return (rand() % (maxRange - minRange + 1)) + minRange;
}

/**
 * Main game function
 * Prompts player to enter guesses until correct guess is made
 */
void play(int difficulty)
{
    // generate random number within specified difficulty range
    int answer = generateRandomNumber(1, difficulty);

    // initialize guess counter
    int guessCount = 0;

    // loop until correct guess is made
    int guess;
    do {
        printf("Enter your guess (1-%d): ", difficulty);
        scanf("%d", &guess);
        guessCount++;

        if (guess > answer) {
            printf("Too high! Try again.\n\n");
        } else if (guess < answer) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", guessCount);
        }
    } while (guess != answer);

}