//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define LOWER_BOUND 1
#define UPPER_BOUND 100

void display_intro();
int get_guess();
void evaluate_guess(int guess, int secret_number, int attempts_left);

int main() {
    srand(time(NULL));  // Seed the random number generator
    int secret_number = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;
    int attempts_left = MAX_ATTEMPTS;
    int guess;

    display_intro();

    while (attempts_left > 0) {
        guess = get_guess();
        evaluate_guess(guess, secret_number, attempts_left);
        attempts_left--;
    }

    printf("Sorry, you've run out of attempts! The number was: %d\n", secret_number);
    
    return 0;
}

void display_intro() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between %d and %d.\n", LOWER_BOUND, UPPER_BOUND);
    printf("You have %d attempts to guess the number.\n", MAX_ATTEMPTS);
    printf("Good luck!\n");
}

int get_guess() {
    int guess;

    printf("Please enter your guess: ");
    while (scanf("%d", &guess) != 1) {
        printf("Invalid input. Please enter a number: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    while (guess < LOWER_BOUND || guess > UPPER_BOUND) {
        printf("Out of bounds! Please guess a number between %d and %d: ", LOWER_BOUND, UPPER_BOUND);
        scanf("%d", &guess);
    }

    return guess;
}

void evaluate_guess(int guess, int secret_number, int attempts_left) {
    if (guess == secret_number) {
        printf("Congratulations! You've guessed the number %d correctly!\n", secret_number);
        exit(0);  // Exit the program if guessed correctly
    } else if (guess < secret_number) {
        printf("Your guess is too low!\n");
    } else {
        printf("Your guess is too high!\n");
    }

    if (attempts_left > 1) {
        printf("You have %d attempts left.\n", attempts_left - 1);
    } else {
        printf("This was your last attempt.\n");
    }
}