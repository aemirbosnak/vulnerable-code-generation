//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESS 5
#define MIN_GUESS 1
#define GUESS_DIFF 3

int main() {
    int correct = 0;
    int guesses = 0;
    int max_guesses = 5;
    int min_guess = 1;
    int guess_diff = 3;
    int secret_number = rand() % 100 + 1;

    printf("Welcome to the Statistical Guessing Game!\n");
    printf("I have a secret number between 1 and 100... can you guess it?\n");

    do {
        int guess = get_guess();
        int difference = abs(guess - secret_number);

        if (difference == 0) {
            correct++;
            printf("Correct! The secret number was %d\n", secret_number);
        } else if (difference == 1) {
            guesses++;
            printf("You guessed %d, but the secret number was %d\n", guess, secret_number);
        } else {
            printf("You guessed %d, but the secret number was %d (too far off)\n", guess, secret_number);
        }

        if (guesses == max_guesses) {
            printf("You ran out of guesses! The secret number was %d\n", secret_number);
            break;
        }
    } while (guesses < max_guesses);

    printf("You made %d correct guesses out of %d attempts (%.2f%% accuracy)\n", correct, guesses,
           (correct * 100) / guesses);
    printf("The secret number was %d\n", secret_number);

    return 0;
}

int get_guess() {
    int guess;
    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);
    return guess;
}