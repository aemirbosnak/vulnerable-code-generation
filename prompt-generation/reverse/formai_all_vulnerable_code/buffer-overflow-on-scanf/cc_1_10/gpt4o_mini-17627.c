//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 10

void print_welcome_message() {
    printf("🎉 Welcome to the Cheerful Number Guessing Game! 🎉\n");
    printf("Can you guess the secret number between 1 and %d?\n", MAX_NUMBER);
    printf("You have %d attempts to get it right!\n", MAX_GUESSES);
}

int get_random_number(int max) {
    return (rand() % max) + 1; // Return a number between 1 and 'max'
}

void play_game() {
    int secret_number = get_random_number(MAX_NUMBER);
    int guess, attempts = 0;

    while (attempts < MAX_GUESSES) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > MAX_NUMBER) {
            printf("🚫 Please enter a number between 1 and %d.\n", MAX_NUMBER);
        } else if (guess < secret_number) {
            printf("⬆️ Too low! Try again!\n");
        } else if (guess > secret_number) {
            printf("⬇️ Too high! Try again!\n");
        } else {
            printf("🎉 Congratulations! You've guessed it! The number was %d!\n", secret_number);
            return; // Exit the game successfully
        }
        
        attempts++;
    }

    printf("😔 Sorry, you've used all your attempts! The number was %d. Better luck next time!\n", secret_number);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    char play_again;

    do {
        print_welcome_message();
        play_game();
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("🌈 Thank you for playing! Have a fantastic day! 🌈\n");
    return 0;
}