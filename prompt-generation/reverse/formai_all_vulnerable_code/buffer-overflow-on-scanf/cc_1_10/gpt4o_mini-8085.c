//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int low, int high);
void ask_for_hint(int guess, int secret_number);
void invalid_choice();
void play_again();

int main() {
    srand(time(0)); // Seed random number generator
    int low = 1, high = 100; // Define the range for the game
    printf("Welcome to the Number Guessing Game!\n");
    play_game(low, high);
    return 0;
}

void play_game(int low, int high) {
    int secret_number = (rand() % (high - low + 1)) + low; // Generate random secret number
    int guess = 0;
    int attempts = 0;

    printf("I have selected a number between %d and %d. Try to guess it!\n", low, high);
    
    while (guess != secret_number) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < low || guess > high) {
            printf("Please guess a number within the range %d to %d.\n", low, high);
            continue;
        }

        if (guess > secret_number) {
            printf("Too high! ");
            ask_for_hint(guess, secret_number);
        } else if (guess < secret_number) {
            printf("Too low! ");
            ask_for_hint(guess, secret_number);
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", secret_number, attempts);
        }
    }
    
    play_again();
}

void ask_for_hint(int guess, int secret_number) {
    char choice;
    printf("Would you like a hint? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        if (secret_number % 2 == 0) {
            printf("Here's a hint: The secret number is even.\n");
        } else {
            printf("Here's a hint: The secret number is odd.\n");
        }
        
        // Provide a range hint
        if (guess < secret_number) {
            printf("Try a higher number!\n");
        } else {
            printf("Try a lower number!\n");
        }
    } else if (choice == 'n' || choice == 'N') {
        printf("No hint provided, take your next guess!\n");
    } else {
        invalid_choice();
        ask_for_hint(guess, secret_number); // Recursion in case of invalid input
    }
}

void invalid_choice() {
    printf("Invalid choice! Please enter 'y' to get a hint or 'n' to skip.\n");
}

void play_again() {
    char choice;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        main(); // Restart game
    } else if (choice == 'n' || choice == 'N') {
        printf("Thanks for playing! Goodbye!\n");
    } else {
        invalid_choice();
        play_again(); // Recursion for invalid play again choice
    }
}