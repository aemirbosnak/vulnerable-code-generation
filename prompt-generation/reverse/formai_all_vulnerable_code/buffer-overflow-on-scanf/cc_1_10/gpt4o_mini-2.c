//GPT-4o-mini DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void print_instructions() {
    printf("Welcome to 'Guess the Number' Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess it. Good luck!\n", MAX_TRIES);
}

int main() {
    int number_to_guess, user_guess, attempts = 0;
    char play_again;

    // Seed the random number generator
    srand(time(NULL));

    do {
        // Generate a random number between 1 and 100
        number_to_guess = rand() % 100 + 1;

        print_instructions();
        
        while (attempts < MAX_TRIES) {
            printf("Enter your guess: ");
            scanf("%d", &user_guess);
            attempts++;

            if (user_guess < 1 || user_guess > 100) {
                printf("Please guess a number between 1 and 100.\n");
                attempts--; // Don't count invalid attempts
            }
            else if (user_guess < number_to_guess) {
                printf("Too low! Try again.\n");
            }
            else if (user_guess > number_to_guess) {
                printf("Too high! Try again.\n");
            }
            else {
                printf("Congratulations! You've guessed the number %d in %d attempts.\n", number_to_guess, attempts);
                break;
            }
        }
        
        if (attempts == MAX_TRIES) {
            printf("Sorry, you've used all your attempts. The number was %d.\n", number_to_guess);
        }

        printf("Would you like to play again? (Y/N): ");
        scanf(" %c", &play_again);
        attempts = 0; // Reset attempts for the next game

    } while (play_again == 'Y' || play_again == 'y');

    printf("Thank you for playing! Goodbye!\n");
    
    return 0;
}