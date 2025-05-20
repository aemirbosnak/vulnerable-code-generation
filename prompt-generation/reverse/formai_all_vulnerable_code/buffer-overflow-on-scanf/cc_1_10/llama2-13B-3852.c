//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num_guesses = 10; // Number of guesses to try
    int correct_guesses = 0; // Number of correct guesses so far
    int highest_number = 100; // Highest number to guess
    int lowest_number = 1; // Lowest number to guess

    // Generate a random number between highest and lowest numbers
    int random_number = (highest_number + lowest_number) / 2;

    // Print the random number and ask the user to guess
    printf("I'm thinking of a number between %d and %d... guess it! \n", lowest_number, highest_number);
    printf("Random number: %d\n", random_number);

    // Loop through the user's guesses
    for (int i = 0; i < num_guesses; i++) {
        // Get the user's guess
        int user_guess = get_user_guess();

        // Check if the user's guess is correct
        if (user_guess == random_number) {
            correct_guesses++;
            printf("Correct guess! The number was %d\n", random_number);
        } else {
            // If the user's guess is incorrect, tell them the number is higher or lower
            if (user_guess < random_number) {
                printf("Too low! The number is higher than %d\n", user_guess);
            } else {
                printf("Too high! The number is lower than %d\n", user_guess);
            }
        }

        // If the user has guessed correctly, stop the loop
        if (correct_guesses == num_guesses) {
            break;
        }
    }

    // If the user has not guessed correctly after all attempts, tell them the number
    if (correct_guesses == 0) {
        printf("You didn't guess the number! It was %d\n", random_number);
    }

    return 0;
}

// Function to get the user's guess
int get_user_guess() {
    int guess;
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &guess);
    return guess;
}