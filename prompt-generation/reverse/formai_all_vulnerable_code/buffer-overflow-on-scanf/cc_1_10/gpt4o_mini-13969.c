//GPT-4o-mini DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void print_instructions(int min, int max) {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I have chosen a number between %d and %d.\n", min, max);
    printf("You need to guess the number within %d attempts!\n", MAX_ATTEMPTS);
    printf("Good luck!\n\n");
}

int main() {
    int min = 1, max = 100;
    int number_to_guess, player_guess;
    int attempts = 0;
    int correct = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between min and max
    number_to_guess = (rand() % (max - min + 1)) + min;

    // Print the game instructions
    print_instructions(min, max);

    // Game loop: allow the player to guess the number
    while (attempts < MAX_ATTEMPTS && !correct) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &player_guess);
        
        if (player_guess < min || player_guess > max) {
            printf("Please guess a number between %d and %d.\n", min, max);
            continue;
        }

        attempts++;

        // Check if the guess is correct
        if (player_guess == number_to_guess) {
            correct = 1;
            printf("Congratulations! You guessed the correct number: %d\n", number_to_guess);
        } else {
            if (attempts < MAX_ATTEMPTS) {
                if (player_guess < number_to_guess) {
                    printf("Too low! Try again.\n");
                } else {
                    printf("Too high! Try again.\n");
                }
            } else {
                printf("Sorry, you've used all your attempts. The correct number was %d.\n", number_to_guess);
            }
        }
    }

    // End of the game message
    printf("Thank you for playing! Have a great day!\n");
    return 0;
}