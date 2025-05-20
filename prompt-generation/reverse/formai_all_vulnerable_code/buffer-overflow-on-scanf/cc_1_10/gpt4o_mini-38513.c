//GPT-4o-mini DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100, and you have to guess it.\n");
    printf("For each incorrect guess, you will lose points.\n");
    printf("Try to guess in as few attempts as possible to maximize your score!\n");
    printf("Type 'exit' to quit the game at any time.\n");
}

int getRandomNumber() {
    return rand() % 100 + 1; // Generate random number between 1 and 100
}

int calculateScore(int attempts) {
    return attempts <= 10 ? 100 - (attempts * 10) : 0; // Score logic
}

void playGame() {
    int targetNumber, guessedNumber, attempts = 0, score;
    char userInput[10];

    targetNumber = getRandomNumber();
    printf("A number has been chosen between 1 and 100. Start guessing!\n");

    while (1) {
        printf("Enter your guess (or type 'exit' to quit): ");
        fgets(userInput, sizeof(userInput), stdin);

        if (strncmp(userInput, "exit", 4) == 0) {
            printf("Thanks for playing! Goodbye!\n");
            return;
        }

        guessedNumber = atoi(userInput);
        attempts++;

        if (guessedNumber < 1 || guessedNumber > 100) {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }

        if (guessedNumber < targetNumber) {
            printf("Too low! Try again.\n");
        } else if (guessedNumber > targetNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", targetNumber, attempts);
            score = calculateScore(attempts);
            printf("Your score is: %d\n", score);
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int choice;

    displayInstructions();

    while (1) {
        printf("\nWould you like to play the game? (1: Yes, 0: No): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            playGame();
        } else {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }
    }

    return 0;
}