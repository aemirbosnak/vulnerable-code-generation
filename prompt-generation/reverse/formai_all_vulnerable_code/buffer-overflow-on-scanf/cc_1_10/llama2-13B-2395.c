//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
    int number, guess, attempts = 0;
    char message[50];

    srand(time(NULL));

    printf("Welcome to the Arithmetic Adventure! \n");

    // Generate a random number between 1 and MAX_NUMBER
    number = rand() % MAX_NUMBER;

    // Prompt the user to guess the number
    printf("My number is between 1 and %d. Guess it! \n", MAX_NUMBER);

    // Loop until the user correctly guesses the number
    while (1) {
        scanf("%d", &guess);

        // Check if the user guessed the correct number
        if (guess == number) {
            break;
        }

        // If the user didn't guess correctly, display a hint
        if (guess < number) {
            printf("Your guess is too low. Try again! \n");
        } else {
            printf("Your guess is too high. Try again! \n");
        }

        // Increment the number of attempts
        attempts++;

        // Display a fun message after 5 incorrect guesses
        if (attempts == 5) {
            sprintf(message, "Oh no! You've used up all your guesses! The answer was %d. Better luck next time! \n", number);
            printf(message);
            break;
        }
    }

    // Display a final message if the user correctly guessed the number
    if (guess == number) {
        printf("Congratulations! You guessed the number in %d attempts! The answer was %d. \n", attempts, number);
    }

    return 0;
}