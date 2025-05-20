//LLAMA2-13B DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define INF 1000000

int main() {
    int numGuesses;
    int secretNumber;
    int guess;

    srand(time(NULL));

    printf("Welcome to the Magic Number Game!\n");

    // Generate a random secret number
    secretNumber = rand() % 100;

    printf("The secret number is: %d\n", secretNumber);

    // Ask the player to guess the number
    printf("Guess the number: ");
    scanf("%d", &guess);

    // Keep track of the number of guesses
    numGuesses = 1;

    while (guess != secretNumber) {
        // Check if the player guessed too high
        if (guess > secretNumber) {
            numGuesses++;
            printf("Too high! Try again...\n");
        }

        // Check if the player guessed too low
        else if (guess < secretNumber) {
            numGuesses++;
            printf("Too low! Try again...\n");
        }

        // Generate a new random number
        secretNumber = rand() % 100;

        // Update the guess
        guess = rand() % 100;

        // Print the new secret number
        printf("The new secret number is: %d\n", secretNumber);
    }

    // Congratulate the player if they guessed correctly
    if (guess == secretNumber) {
        printf("Congratulations! You guessed the number in %d attempts!\n", numGuesses);
    }

    return 0;
}