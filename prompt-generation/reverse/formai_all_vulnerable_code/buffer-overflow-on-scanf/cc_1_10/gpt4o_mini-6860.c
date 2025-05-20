//GPT-4o-mini DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TRIES 5
#define MAX_NUMBER 100

void print_welcome_message() {
    printf("*****************************************\n");
    printf("*          Welcome to The Guessing Game!*\n");
    printf("*****************************************\n");
    printf("Guess the number between 1 and %d.\n", MAX_NUMBER);
    printf("You have %d tries to guess the correct number!\n", MAX_TRIES);
}

int get_random_number() {
    srand(time(0));
    return (rand() % MAX_NUMBER) + 1; // Generates a number between 1 and MAX_NUMBER
}

bool is_input_valid(int input) {
    return (input >= 1 && input <= MAX_NUMBER);
}

void play_game() {
    int random_number = get_random_number();
    int user_guess = 0;
    int tries = 0;
    bool has_guessed_correctly = false;

    while (tries < MAX_TRIES && !has_guessed_correctly) {
        printf("\nAttempt %d/%d: Enter your guess: ", tries + 1, MAX_TRIES);
        scanf("%d", &user_guess);

        if (!is_input_valid(user_guess)) {
            printf("Invalid input! Please guess a number between 1 and %d.\n", MAX_NUMBER);
            continue;
        }
        
        tries++;

        if (user_guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (user_guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            has_guessed_correctly = true;
            printf("Congratulations! You've guessed the correct number: %d\n", random_number);
        }
    }

    if (!has_guessed_correctly) {
        printf("Sorry, you've used all your tries! The correct number was %d.\n", random_number);
    }
}

char play_again() {
    char response;
    printf("\nWould you like to play again? (y/n): ");
    scanf(" %c", &response);
    return response;
}

int main() {
    char response = 'y';

    while (response == 'y' || response == 'Y') {
        print_welcome_message();
        play_game();
        response = play_again();
    }

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}