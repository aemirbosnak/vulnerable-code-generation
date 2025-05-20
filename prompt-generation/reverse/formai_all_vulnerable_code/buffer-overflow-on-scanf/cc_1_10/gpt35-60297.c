//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void playGame();
int generateRandomNumber();
void clearScreen();

int main() {
    // Seed the random number generator
    srand(time(0));

    printf("Welcome to SURPRISE GAME!\n");
    printf("========================\n\n");

    char playAgain = 'y';
    while (playAgain == 'y') {
        playGame();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        clearScreen();
    }

    printf("\nThank you for playing SURPRISE GAME! Goodbye!\n");

    return 0;
}

void playGame() {
    int randomNumber = generateRandomNumber();
    int guess;
    int numGuesses = 0;
    bool isCorrect = false;

    printf("I have chosen a number between 1 and 100. Can you guess it?\n\n");

    while (!isCorrect) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess == randomNumber) {
            printf("\nCongratulations! You guessed the number in %d tries!\n", numGuesses);
            isCorrect = true;
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }
}

int generateRandomNumber() {
    return rand() % 100 + 1;
}

void clearScreen() {
    #ifdef _WIN32 // Windows OS
        system("cls");
    #else // Other OS
        system("clear");
    #endif
}