//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_intro() {
    printf("Welcome to Number Guessing Adventure!\n");
    printf("You need to guess a number between 1 and 100.\n");
    printf("For each guess, I'll let you know if it's too high or too low.\n");
    printf("Try to guess it in as few attempts as possible!\n");
    printf("Good luck!\n\n");
}

int get_guess() {
    int guess;
    printf("Enter your guess: ");
    while (scanf("%d", &guess) != 1) {
        while (getchar() != '\n'); // clear invalid input
        printf("Invalid input. Please enter a number: ");
    }
    return guess;
}

void play_game() {
    int number_to_guess, guess, attempts = 0;

    number_to_guess = rand() % 100 + 1; // Random number between 1 and 100

    while (1) {
        guess = get_guess();
        attempts++;

        if (guess < number_to_guess) {
            printf("Too low! Try again.\n\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", number_to_guess, attempts);
            break;
        }
    }
}

int main() {
    char play_again;

    srand(time(0)); // Seed the random number generator
    print_intro();

    do {
        play_game();
        printf("Do you want to play again? (y/n): ");
        while (scanf(" %c", &play_again) != 1 || (play_again != 'y' && play_again != 'n')) {
            printf("Invalid input. Please enter 'y' to play again or 'n' to quit: ");
            while (getchar() != '\n'); // clear invalid input
        }
        printf("\n");
    } while (play_again == 'y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}