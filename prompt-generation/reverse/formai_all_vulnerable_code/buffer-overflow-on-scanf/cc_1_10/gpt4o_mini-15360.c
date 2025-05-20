//GPT-4o-mini DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5
#define MAX_NUMBER 100

void display_intro() {
    printf("========================================\n");
    printf("      Welcome to the Number Guessing Game!\n");
    printf("========================================\n");
    printf("Try to guess the number between 1 and %d.\n", MAX_NUMBER);
    printf("You have %d tries to make your guess.\n", MAX_TRIES);
    printf("Good luck!\n");
    printf("========================================\n\n");
}

int get_random_number() {
    return (rand() % MAX_NUMBER) + 1;  // random number between 1 and MAX_NUMBER
}

int get_user_input() {
    int guess;
    printf("Enter your guess: ");
    while (scanf("%d", &guess) != 1) {
        printf("Please enter a valid number: ");
        while(getchar() != '\n');  // clear invalid input
    }
    return guess;
}

void play_game() {
    int random_number = get_random_number();
    int user_guess;
    int remaining_tries = MAX_TRIES;

    printf("I have selected a number between 1 and %d!\n", MAX_NUMBER);

    while (remaining_tries > 0) {
        user_guess = get_user_input();
        remaining_tries--;

        if (user_guess == random_number) {
            printf("Congratulations! You guessed the number %d correctly!\n", random_number);
            break;
        } else if (user_guess < random_number) {
            printf("Too low! You have %d tries left.\n", remaining_tries);
        } else {
            printf("Too high! You have %d tries left.\n", remaining_tries);
        }

        if (remaining_tries == 0) {
            printf("Sorry! You've run out of tries. The correct number was %d.\n", random_number);
        }
    }
}

int main() {
    char play_again;

    srand(time(NULL));  // Seed random number generator

    do {
        display_intro();
        play_game();
        printf("Would you like to play again? (Y/N): ");
        while (scanf(" %c", &play_again) != 1 || (play_again != 'Y' && play_again != 'N' && play_again != 'y' && play_again != 'n')) {
            printf("Please enter 'Y' or 'N': ");
            while(getchar() != '\n');  // clear invalid input
        }
    } while (play_again == 'Y' || play_again == 'y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}