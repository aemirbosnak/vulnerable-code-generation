//FormAI DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void startGame(int difficulty);

int main() {
    int choice, difficulty;
    char playAgain;

    srand(time(NULL)); // Seed the random number generator

    do {
        displayMenu(); // Show main menu
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                difficulty = 1; // Set easy difficulty
                startGame(difficulty); // Start the game
                break;
            case 2:
                difficulty = 2; // Set medium difficulty
                startGame(difficulty); // Start the game
                break;
            case 3:
                difficulty = 3; // Set hard difficulty
                startGame(difficulty); // Start the game
                break;
            case 4:
                printf("Thanks for playing!\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); // Get user input to play again

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

// Show main menu to user
void displayMenu() {
    printf("===========================\n");
    printf("        GAME MENU\n");
    printf("===========================\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Quit\n");
}

// Play the game
void startGame(int difficulty) {
    int secretNumber, guess, numTries = 0, maxTries;

    switch (difficulty) { // Set number of tries depending on difficulty
        case 1:
            maxTries = 10;
            break;
        case 2:
            maxTries = 7;
            break;
        case 3:
            maxTries = 4;
            break;
        default:
            maxTries = 10;
            break;
    }

    secretNumber = rand() % 100 + 1; // Generate secret number

    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Enter your guess (tries left: %d): ", maxTries - numTries);
        scanf("%d", &guess);

        if (guess < secretNumber)
            printf("Too low. Try again.\n");
        else if (guess > secretNumber)
            printf("Too high. Try again.\n");
        else
            printf("Congratulations! You guessed it in %d tries.\n", numTries+1);

        numTries++;

    } while (guess != secretNumber && numTries < maxTries);

    if (numTries == maxTries)
        printf("You failed to guess the number in %d tries. The secret number was %d.\n", maxTries, secretNumber);
}