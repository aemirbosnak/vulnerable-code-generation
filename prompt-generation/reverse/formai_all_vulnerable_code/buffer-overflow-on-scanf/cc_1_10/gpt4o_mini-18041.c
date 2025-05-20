//GPT-4o-mini DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess the correct number.\n", MAX_ATTEMPTS);
    printf("Good luck!\n\n");
}

int main() {
    int number_to_guess, user_guess;
    int attempts = 0;

    // Seed the random number generator
    srand(time(NULL));
    number_to_guess = rand() % 100 + 1;  // Generate a number between 1 and 100

    print_instructions();

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess (%d/%d): ", attempts + 1, MAX_ATTEMPTS);
        scanf("%d", &user_guess);

        if (user_guess < 1 || user_guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the correct number: %d\n", number_to_guess);
            break;
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry! You've used all your attempts. The correct number was: %d\n", number_to_guess);
        }
    }
    
    return 0;
}