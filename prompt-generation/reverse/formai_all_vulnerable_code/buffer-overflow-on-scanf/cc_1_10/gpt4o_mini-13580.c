//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void print_welcome_message() {
    printf("====================================\n");
    printf("         Number Guessing Game       \n");
    printf("====================================\n");
    printf("Welcome! You have to guess a number between 1 and 100.\n");
    printf("You have a maximum of %d attempts. Good luck!\n\n", MAX_ATTEMPTS);
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int number_to_guess, guess, attempts = 0;
    int min_range = 1, max_range = 100;

    // Seed the random number generator
    srand(time(NULL));

    print_welcome_message();
    
    // Generate a random number
    number_to_guess = get_random_number(min_range, max_range);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d of %d: Enter your guess (1-100): ", attempts + 1, MAX_ATTEMPTS);
        scanf("%d", &guess);
        
        // Validate user input
        if (guess < min_range || guess > max_range) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min_range, max_range);
            continue;
        }

        attempts++;

        if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", number_to_guess, attempts);
            break;
        }

        // If attempts run out
        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry, you've used all your attempts! The number was %d.\n", number_to_guess);
        }
    }

    printf("Thank you for playing! Would you like to play again? (yes/no): ");
    char play_again[4];
    scanf("%s", play_again);
    
    if (play_again[0] == 'y' || play_again[0] == 'Y') {
        main(); // Restart the game
    } else {
        printf("Exiting the game. Goodbye!\n");
    }

    return 0;
}