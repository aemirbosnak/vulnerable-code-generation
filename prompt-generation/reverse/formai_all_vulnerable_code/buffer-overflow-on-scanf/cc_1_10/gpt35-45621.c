//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the terminal
void clear() {
    system("clear || cls");
}

// Function to generate a random number between min and max
int randRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// The main game function
void playGame() {
    clear();

    printf("\n\nWelcome to the Number Guessing Game!\n\n");

    // Randomly generate a number between 1 and 100
    srand(time(NULL));
    int randomNumber = randRange(1, 100);

    // Set up variables for later use
    int guess = 0;
    int numGuesses = 0;

    // Loop through the guessing process until the user guesses the correct number
    while (guess != randomNumber) {
        printf("Please enter a guess between 1 and 100:\n");
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("That guess is out of range. Please try again.\n");
            continue;
        }

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        }

        numGuesses++;
    }

    // Congratulate the user and display their stats
    printf("\nCongratulations! You guessed the right number in %d tries.\n\n", numGuesses);
}

int main() {
    int choice = 0;

    do {
        clear();

        printf("\n\n====== Main Menu ======\n\n");
        printf("1. Play Game\n");
        printf("2. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                clear();
                printf("\n\nThanks for playing!\n\n");
                return 0;
            default:
                printf("\n\nInvalid choice. Please try again.\n\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
        getchar();

    } while (choice != 2);

    return 0;
}