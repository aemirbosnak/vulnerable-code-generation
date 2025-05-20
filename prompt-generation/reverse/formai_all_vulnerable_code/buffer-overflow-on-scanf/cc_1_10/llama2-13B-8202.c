//LLAMA2-13B DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

// Global variables
int guess = 0;
int number = 50;
int attempts = 0;

// Function to generate a random number
void generate_number() {
    srand(time(NULL));
    number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

// Function to check if the player's guess is correct
int check_guess(int guess) {
    if (guess == number) {
        printf("Congratulations! You guessed the correct number: %d\n", number);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Welcome message
    printf("Welcome to the Guess My Number game! \n");

    // Generate the number
    generate_number();

    // Start the game loop
    while (1) {
        // Print the current number
        printf("I am thinking of a number between 1 and 100. Can you guess it?\n");

        // Get the player's guess
        scanf("%d", &guess);

        // Check if the guess is correct
        if (check_guess(guess)) {
            break;
        }

        // Increment the number of attempts
        attempts++;

        // Display the number of attempts
        printf("You have tried %d times so far. Keep going!\n", attempts);

        // Print a hint
        printf("Here's a hint: the number is higher than 25\n");
    }

    // Print the final message
    printf("Congratulations! You guessed the correct number: %d\n", number);

    return 0;
}