//GPT-4o-mini DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

void display_instructions() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n", MAX_TRIES);
    printf("Let's see if you can figure it out!\n\n");
}

int get_random_number(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void play_game() {
    int number_to_guess, user_guess, attempts = 0;
    int lower_bound = 1, upper_bound = 100;

    number_to_guess = get_random_number(lower_bound, upper_bound);

    while (attempts < MAX_TRIES) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &user_guess);

        attempts++;

        if (user_guess < lower_bound || user_guess > upper_bound) {
            printf("Please guess a number between %d and %d.\n", lower_bound, upper_bound);
            attempts--; // don't count this attempt
            continue;
        }

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", number_to_guess, attempts);
            return; // end the game
        }
    }

    printf("Sorry, you've run out of attempts! The number was %d.\n", number_to_guess);
}

int main() {
    srand(time(0));  // Seed the random number generator
    int play_again;

    do {
        display_instructions();
        play_game();
        
        printf("\nDo you want to play again? (1 = Yes, 0 = No): ");
        scanf("%d", &play_again);
    } while (play_again == 1);

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}