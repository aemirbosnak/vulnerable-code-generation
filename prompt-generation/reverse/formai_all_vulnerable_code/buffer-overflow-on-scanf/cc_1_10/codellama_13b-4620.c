//Code Llama-13B DATASET v1.0 Category: Game ; Style: safe
// A simple game program in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables
int guess;
int random_number;

// Function to generate a random number
int get_random_number() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

// Function to get input from user
int get_guess() {
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &guess);
    return guess;
}

// Function to check if the guess is correct
int check_guess(int guess) {
    if (guess == random_number) {
        printf("You guessed the number! Congratulations!\n");
        return 1;
    } else if (guess < random_number) {
        printf("Too low! Try again.\n");
        return 0;
    } else if (guess > random_number) {
        printf("Too high! Try again.\n");
        return 0;
    } else {
        printf("Invalid input. Try again.\n");
        return 0;
    }
}

int main() {
    // Generate a random number
    random_number = get_random_number();

    // Get input from user
    guess = get_guess();

    // Check if the guess is correct
    int correct = check_guess(guess);

    // If the guess is not correct, continue the game
    while (correct == 0) {
        guess = get_guess();
        correct = check_guess(guess);
    }

    return 0;
}