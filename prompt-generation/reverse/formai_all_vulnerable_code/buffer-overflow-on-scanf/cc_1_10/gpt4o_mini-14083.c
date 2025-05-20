//GPT-4o-mini DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void displayInstructions();
void startGame();
void playRound();
int getRandomNumber(int min, int max);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Game introduction
    printf("Welcome to the Curious Number Guessing Game!\n");
    displayInstructions();
    startGame();

    return 0;
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. You will be guessing a random number between 1 and 100.\n");
    printf("2. After each guess, you'll receive feedback.\n");
    printf("3. Try to guess the number with the least guesses possible.\n");
}

void startGame() {
    char choice;

    do {
        printf("Ready to play? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'y') {
            playRound();
        } else if (choice == 'n') {
            printf("Thanks for stopping by! Come back soon!\n");
        } else {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }
    } while (choice != 'n');
}

void playRound() {
    int numberToGuess = getRandomNumber(1, 100);
    int userGuess = 0;
    int attempts = 0;

    printf("I have selected a number between 1 and 100. Let's see if you can guess it!\n");

    while (userGuess != numberToGuess) {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess < numberToGuess) {
            printf("Your guess is too low. Try again!\n");
        } else if (userGuess > numberToGuess) {
            printf("Your guess is too high. Try again!\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", numberToGuess, attempts);
        }
    }

    char continueChoice;
    printf("Do you want to play another round? (y/n): ");
    scanf(" %c", &continueChoice);
    
    if (tolower(continueChoice) == 'y') {
        playRound();
    } else {
        printf("Thank you for playing! Goodbye!\n");
    }
}

int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}