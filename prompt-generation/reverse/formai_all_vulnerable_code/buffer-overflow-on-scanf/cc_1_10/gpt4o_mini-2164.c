//GPT-4o-mini DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

// Function prototypes
void displayInstructions();
int generateRandomNumber(int lower, int upper);
int getUserGuess();
int evaluateGuess(int guess, int target);
int playGame();
void playAgainPrompt();

int main() {
    srand(time(0)); // Seed the random number generator
    displayInstructions();
    
    do {
        playGame();
        playAgainPrompt();
    } while (1);
    
    return 0;
}

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess a number between 1 and 100.\n");
    printf("You have %d attempts to guess the correct number.\n", MAX_TRIES);
}

// Function to generate a random number between lower and upper
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to get the user's guess
int getUserGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to evaluate the user's guess
int evaluateGuess(int guess, int target) {
    if (guess < target) {
        printf("Higher!\n");
        return 1; // Guess is too low
    } else if (guess > target) {
        printf("Lower!\n");
        return -1; // Guess is too high
    } else {
        printf("Congratulations! You've guessed the correct number!\n");
        return 0; // Correct guess
    }
}

// Function to play the game
int playGame() {
    int target = generateRandomNumber(1, 100);
    int guess;
    int attempts = 0;
    int result;
    
    printf("A number has been generated. Let's start guessing!\n");
    
    while (attempts < MAX_TRIES) {
        guess = getUserGuess();
        attempts += 1;
        
        result = evaluateGuess(guess, target);
        
        if (result == 0) {
            break; // Correct guess, exit loop
        }
        
        if (attempts == MAX_TRIES) {
            printf("Sorry! You've used all your attempts. The correct number was %d.\n", target);
        }
    }
    
    return 0; // Indicate the end of the game
}

// Function to prompt the player to play again
void playAgainPrompt() {
    char choice;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice != 'y' && choice != 'Y') {
        printf("Thank you for playing! Goodbye!\n");
        exit(0); // Exit the program
    }
}