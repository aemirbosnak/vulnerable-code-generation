//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if the guessed number is within the bounds of min and max
int validGuess(int guess, int min, int max) {
    return (guess >= min && guess <= max);
}

int main() {
    // Setting up the game
    printf("Welcome to Number Guessing Game!\n");
    printf("You have 7 attempts to guess the number.\n");
    srand(time(NULL));
    int minNum = 1;
    int maxNum = 100;
    int guessLimit = 7;
    int answer = randomInt(minNum, maxNum);
    int guessCount = 0;
    int guess = 0;

    // Running the game loop
    while (guessCount < guessLimit) {
        printf("Guess a number between %d and %d: ", minNum, maxNum);
        scanf("%d", &guess);
        
        // End the game if the guess is correct
        if (guess == answer) {
            printf("Congratulations! You guessed the number in %d attempts.\n", guessCount+1);
            return 0;
        }
        
        // Check if the guess is valid
        if (!validGuess(guess, minNum, maxNum)) {
            printf("Invalid guess. Please enter a number between %d and %d.\n", minNum, maxNum);
            continue;
        }

        // Give hints to the player based on their guess
        if (guess < answer) {
            printf("Higher.\n");
        } else {
            printf("Lower.\n");
        }

        guessCount++;
    }

    // Game over. The player couldn't guess the number.
    printf("Game over! The number was %d.\n", answer);
    return 0;
}