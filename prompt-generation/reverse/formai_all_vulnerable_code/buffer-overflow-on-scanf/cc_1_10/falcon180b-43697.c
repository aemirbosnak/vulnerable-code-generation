//Falcon-180B DATASET v1.0 Category: Educational ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_ATTEMPTS 3
#define DELAY 1000000 // 1 second delay

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if the guess is correct
int checkGuess(int guess, int secretNumber) {
    if (guess == secretNumber) {
        printf("Congratulations! You guessed the number correctly.\n");
        return 1;
    } else if (guess < secretNumber) {
        printf("Too low. Guess again.\n");
    } else {
        printf("Too high. Guess again.\n");
    }
    return 0;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate a secret number between 1 and 100
    int secretNumber = generateRandomNumber(1, 100);

    int attemptsLeft = MAX_ATTEMPTS;
    int guess;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    // Main game loop
    while (attemptsLeft > 0 && secretNumber!= guess) {
        printf("You have %d attempts left.\n", attemptsLeft);
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (checkGuess(guess, secretNumber)) {
            break;
        }

        attemptsLeft--;
        printf("Incorrect guess. You have %d attempts left.\n", attemptsLeft);
        printf("Hint: The number is %s than your previous guess.\n", guess < secretNumber? "lower" : "higher");

        if (attemptsLeft == 0) {
            printf("Game over. The correct number was %d.\n", secretNumber);
        }

        usleep(DELAY); // Pause for 1 second
    }

    return 0;
}