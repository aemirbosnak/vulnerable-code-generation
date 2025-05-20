//GPT-4o-mini DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void display_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess the number correctly.\n", MAX_TRIES);
    printf("Good luck!\n\n");
}

int get_user_guess() {
    int guess;
    printf("Enter your guess (1-100): ");
    if (scanf("%d", &guess) != 1) {
        printf("Invalid input! Please enter a number.\n");
        while(getchar() != '\n'); // Clear input buffer
        return get_user_guess(); // Prompt again
    }
    return guess;
}

void play_game() {
    int target_number, user_guess, tries = 0;
    int found = 0;

    srand(time(NULL));
    target_number = (rand() % 100) + 1;

    while (tries < MAX_TRIES && !found) {
        user_guess = get_user_guess();
        tries++;

        if (user_guess < 1 || user_guess > 100) {
            printf("Please guess a number within the range (1-100).\n");
            tries--; // Not a valid attempt
            continue;
        }

        if (user_guess > target_number) {
            printf("Too high! Try again.\n");
        } else if (user_guess < target_number) {
            printf("Too low! Try again.\n");
        } else {
            found = 1;
            printf("Congratulations! You've guessed the number %d correctly in %d tries.\n", target_number, tries);
        }

        if (tries == MAX_TRIES && !found) {
            printf("Sorry, you've used all your attempts. The number was %d.\n", target_number);
        }
    }
}

int main() {
    char play_again;

    do {
        display_instructions();
        play_game();
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);
        while(getchar() != '\n'); // Clear input buffer
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}