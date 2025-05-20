//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_GUESSES 10

// Prototypes
void play_game();
int generate_random_number();
int get_guess();
void check_guess(int guess, int answer);

int main(void) {
    srand(time(0)); // Seed the random number generator
    play_game(); // Start the game
    return 0;
}

/*
 * Plays a game of guessing the random number
 */
void play_game() {
    int answer = generate_random_number(); // Generate the random number to guess
    int guess_count = 0; // Initialize guess count to 0
    int guess; // The user's guess

    while(guess_count < MAX_GUESSES) { // While the user hasn't exceeded the maximum number of guesses
        guess = get_guess(); // Get the user's guess
        check_guess(guess, answer); // Check the user's guess against the answer
        guess_count++; // Increment the guess count
        if(guess == answer) { // If the user guessed correctly
            printf("Congratulations! You guessed the number in %d tries.\n", guess_count);
            return; // End the function
        }
    }

    printf("Sorry, you didn't guess the number in time. The number was %d.\n", answer);
}

/*
 * Generates a random number between 1 and 100
 */
int generate_random_number() {
    return (rand() % 100) + 1;
}

/*
 * Prompts the user for a guess and returns their input
 */
int get_guess() {
    int guess;
    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);
    return guess;
}

/*
 * Checks the user's guess against the answer and prints a message indicating the result
 */
void check_guess(int guess, int answer) {
    if(guess < answer) {
        printf("Your guess is too low.\n");
    } else if(guess > answer) {
        printf("Your guess is too high.\n");
    } else {
        printf("Your guess is correct!\n");
    }
}