//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers between a range
int generateRandomInt(int min, int max) 
{
    return (min + rand() % (max - min + 1));
}

// Function to check if guess is correct, return 1 if correct, 0 if incorrect
int checkGuess(int guess, int numberToGuess)
{
    if (guess == numberToGuess) {
        return 1;
    } else if (guess < numberToGuess) {
        printf("Too low!\n");
    } else if (guess > numberToGuess) {
        printf("Too high!\n");
    }
    return 0;
}

// Game function
void playGame()
{
    int minNumber = 1;
    int maxNumber = 100;
    int numberToGuess = generateRandomInt(minNumber, maxNumber);
    int guess;
    int guessCount = 0;

    printf("\n");
    printf("New game starting with range %d to %d\n", minNumber, maxNumber);
    printf("Enter -1 to quit.\n");
    
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess == -1) {
            break;
        }
        guessCount++;
        if (checkGuess(guess, numberToGuess)) {
            printf("Congratulations! You guessed the number in %d tries.\n", guessCount);
            break;
        }
    }
}

int main()
{
    int selection;

    printf("Welcome to Number Guessing Game!\n");

    while (1) {
        printf("\nMENU:\n");
        printf("1. Play Game\n");
        printf("2. Quit\n");
        printf("\nEnter selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                playGame();
                break;
            case 2:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid selection. Try again.\n");
                break;
        }
    }
    return 0;
}