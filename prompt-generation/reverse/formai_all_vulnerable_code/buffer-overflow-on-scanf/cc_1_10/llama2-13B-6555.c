//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAGIC_NUMBER 42
#define MAX_NUMBER 100000
#define MIN_NUMBER 1
#define GUESS_COUNT 5

// Function to generate a random number between MIN_NUMBER and MAX_NUMBER
int random_number(void) {
    return rand() % (MAX_NUMBER - MIN_NUMBER) + MIN_NUMBER;
}

// Function to check if a guess is correct
int is_correct(int guess, int number) {
    return abs(guess - number) <= 1;
}

// Function to play the game
void play_game(void) {
    int number = random_number();
    int guess = 0;
    int correct = 0;

    // Print the game instructions
    printf("Welcome to the magic number game! \n");
    printf("I am thinking of a number between %d and %d. Can you guess it?\n", MIN_NUMBER, MAX_NUMBER);

    // Loop until the user guesses correctly or runs out of guesses
    while (guess < GUESS_COUNT && !is_correct(guess, number)) {
        // Print the current guess and the correct answer
        printf("Your guess: %d\n", guess);
        printf("Correct answer: %d\n", number);

        // Get the user's next guess
        scanf("%d", &guess);

        // Check if the user guessed correctly
        correct += is_correct(guess, number);
    }

    // Print the final result
    printf("You guessed correctly %d times out of %d attempts.\n", correct, GUESS_COUNT);
    printf("The magic number was: %d\n", number);
}

int main(void) {
    srand(time(NULL));  // Initialize the random number generator

    // Play the game
    play_game();

    return 0;
}