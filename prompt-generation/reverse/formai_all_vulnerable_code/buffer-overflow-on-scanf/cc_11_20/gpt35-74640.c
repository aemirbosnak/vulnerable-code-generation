//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min = 1;
    int max = 100;
    int guess;
    int count = 0;
    char answer = ' ';

    printf("\nWelcome to the guessing game!\n");
    printf("I am thinking of a number between %d and %d.\n", min, max);
    printf("You have 7 chances to guess the number.\n");

    srand(time(0)); // Seed random number generator
    int number = rand() % (max - min + 1) + min; // Generate random number

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        count++; // Increase guess count

        // Check if guess is within range
        if (guess < min || guess > max) {
            printf("Invalid guess! Guess must be between %d and %d.\n", min, max);
        } else if (guess > number) {
            printf("Too high! You have %d guesses left.\n", 7 - count);
        } else if (guess < number) {
            printf("Too low! You have %d guesses left.\n", 7 - count);
        } else {
            printf("Congratulations, you guessed the number in %d guesses!\n", count);
            break; // Exit loop
        }

        // Ask user if they want to continue guessing
        if (count < 7) {
            printf("Do you want to guess again? (y/n): ");
            scanf(" %c", &answer);

            // Validate user input
            while (answer != 'y' && answer != 'n') {
                printf("Invalid answer! Enter 'y' to continue or 'n' to quit: ");
                scanf(" %c", &answer);
            }
        }

    } while (count < 7 && answer == 'y');

    if (count == 7) {
        printf("\nSorry, you have run out of guesses. The number was %d.\n", number);
    }

    return 0;
}