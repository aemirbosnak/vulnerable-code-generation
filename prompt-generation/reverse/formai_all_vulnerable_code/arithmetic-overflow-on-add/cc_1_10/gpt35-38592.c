//FormAI DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a and b
int randomNumber(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    int numAttempts, numGuesses, guess, answer, maxRange;

    // Set the range of numbers to be guessed
    printf("Enter the maximum number to be guessed: ");
    scanf("%d", &maxRange);

    // Set the number of attempts allowed
    printf("Enter the number of attempts allowed: ");
    scanf("%d", &numAttempts);

    // Set the number of guesses per attempt
    printf("Enter the number of guesses per attempt: ");
    scanf("%d", &numGuesses);

    // Seed the random number generator
    srand(time(0));

    // Play the game
    for (int attempt = 1; attempt <= numAttempts; attempt++) {
        printf("\nAttempt #%d\n", attempt);

        // Generate the answer
        answer = randomNumber(1, maxRange);

        // Guessing phase
        for (int guessNum = 1; guessNum <= numGuesses; guessNum++) {
            printf("Guess %d: ", guessNum);
            scanf("%d", &guess);

            if (guess == answer) {
                printf("Congratulations! You guessed the right number.\n");
                break;
            } else if (guess < answer) {
                printf("Your guess is too low.\n");
            } else {
                printf("Your guess is too high.\n");
            }
        }

        // Ran out of guesses
        if (guess != answer) {
            printf("Sorry, you ran out of guesses. The number was %d.\n", answer);
        }
    }

    return 0;
}