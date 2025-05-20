//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generateRandomNumber();
int getUserGuess();
void playGame();
int playAgain();

int main() {
    int choice;

    printf("Welcome to the Number Guessing Game!\n");

    do {
        playGame();
        printf("Do you want to play again? (1 = yes, 0 = no): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Thank you for playing the Number Guessing Game!\n");

    return 0;
}

int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int getUserGuess() {
    int guess;
    printf("Guess the number (between 1 and 100): ");
    scanf("%d", &guess);
    return guess;
}

void playGame() {
    int randomNumber = generateRandomNumber();
    int userGuess, attempts = 0;

    do {
        attempts++;
        userGuess = getUserGuess();

        if (userGuess > randomNumber) {
            printf("Too high, try again.\n");
        } else if (userGuess < randomNumber) {
            printf("Too low, try again.\n");
        }
    } while (userGuess != randomNumber);

    printf("Congratulations! You guessed the number in %d attempt(s)!\n", attempts);
}

int playAgain() {
    int choice;
    printf("Do you want to play again? (1 = yes, 0 = no): ");
    scanf("%d", &choice);
    return choice;
}