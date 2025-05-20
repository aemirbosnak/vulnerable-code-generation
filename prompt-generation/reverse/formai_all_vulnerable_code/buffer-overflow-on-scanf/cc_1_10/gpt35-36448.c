//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generateNumber(int max); 
void playGame(int max); 

int main() {
    int max = 10; // default maximum value
    char choice;

    do {
        // ask user for maximum value
        printf("Enter the maximum value (1-100): ");
        scanf("%d", &max);

        // validate input
        if (max < 1 || max > 100) {
            printf("Invalid Input. Please enter a number between 1-100.\n");
            continue;
        }

        // play game
        playGame(max);

        // ask user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

// function to generate a random number between 1 and max
int generateNumber(int max) {
    srand(time(NULL)); // seed the random number generator with the current time
    return rand() % max + 1;
}

// function to play the guessing game
void playGame(int max) {
    int randomNumber = generateNumber(max);
    int guess;
    int numGuesses = 0;

    printf("I am thinking of a number between 1 and %d. Can you guess what it is?\n", max);

    do {
        printf("Enter your guess (1-%d): ", max);
        scanf("%d", &guess);

        if (guess < 1 || guess > max) {
            printf("Invalid guess. Please enter a number between 1-%d.\n", max);
        } else if (guess < randomNumber) {
            printf("Too low. Guess again.\n");
            numGuesses++;
        } else if (guess > randomNumber) {
            printf("Too high. Guess again.\n");
            numGuesses++;
        }
    } while (guess != randomNumber);

    // player guessed correctly
    printf("Congratulations! You guessed the number in %d guesses!\n", numGuesses+1);
}