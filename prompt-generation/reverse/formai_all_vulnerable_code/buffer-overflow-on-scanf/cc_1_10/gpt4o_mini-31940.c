//GPT-4o-mini DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10

void print_welcome_message() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess it? You have %d attempts.\n", MAX_GUESSES);
}

int main() {
    int number_to_guess, user_guess;
    int attempts = 0;
    int hint_trigger = 0;

    // Seed the random number generator
    srand(time(NULL));
    number_to_guess = (rand() % 100) + 1; // Random number between 1 and 100

    print_welcome_message();

    while (attempts < MAX_GUESSES) {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

        if (user_guess < 1 || user_guess > 100) {
            printf("Please guess a number between 1 and 100!\n");
            attempts--; // Don't count this as a valid attempt
            continue;
        }

        if (user_guess == number_to_guess) {
            printf("Congratulations! You've guessed the right number %d in %d attempts!\n", number_to_guess, attempts);
            break;
        } else if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        hint_trigger++;
        if (hint_trigger % 3 == 0 && attempts < MAX_GUESSES) {
            // Provide a hint after every three incorrect attempts
            if (number_to_guess % 2 == 0) {
                printf("Hint: The number is even.\n");
            } else {
                printf("Hint: The number is odd.\n");
            }

            if (number_to_guess < 50) {
                printf("Hint: The number is less than 50.\n");
            } else {
                printf("Hint: The number is 50 or more.\n");
            }
        }
    }

    if (attempts == MAX_GUESSES) {
        printf("Sorry, you've used all your attempts! The number was %d.\n", number_to_guess);
    }
    
    // Final message
    printf("Thank you for playing the Number Guessing Game!\n");

    return 0;
}