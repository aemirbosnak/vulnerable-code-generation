//GPT-4o-mini DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

void display_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d tries to guess the number between %d and %d.\n", MAX_TRIES, MIN_NUMBER, MAX_NUMBER);
    printf("Good luck!\n");
}

int get_user_guess() {
    int guess;
    char buffer[128];

    while (1) {
        printf("Enter your guess: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        
        // Attempt to convert input to an integer
        if (sscanf(buffer, "%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("Please guess a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        break; // Input is valid
    }
    
    return guess;
}

int main() {
    int target_number, user_guess, tries = 0;
    srand(time(NULL));
    target_number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;

    display_instructions();

    while (tries < MAX_TRIES) {
        user_guess = get_user_guess();
        tries++;

        if (user_guess < target_number) {
            printf("Too low! You have %d tries left.\n", MAX_TRIES - tries);
        } else if (user_guess > target_number) {
            printf("Too high! You have %d tries left.\n", MAX_TRIES - tries);
        } else {
            printf("Congratulations! You guessed the number %d in %d tries.\n", target_number, tries);
            return 0; // Exit successfully
        }
    }

    printf("Sorry, you've used all your tries. The number was %d.\n", target_number);
    return 0; // Exit with a message
}