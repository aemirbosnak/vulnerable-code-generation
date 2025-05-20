//Falcon-180B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define global variables
int playerScore = 0;
int computerScore = 0;

// define function prototypes
void startGame();
void playRound();
int getRandomNumber();

int main() {
    startGame();

    return 0;
}

void startGame() {
    int choice;

    printf("Welcome to the Cheerful Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    printf("Type 1 to play or 0 to quit: ");
    scanf("%d", &choice);

    if (choice == 1) {
        playRound();
    } else {
        printf("Thanks for playing! See you next time!\n");
    }
}

void playRound() {
    int guess, result;
    char playAgain;

    do {
        printf("\nRound %d\n", ++computerScore);
        printf("Computer's score: %d\n", computerScore);
        printf("Player's score: %d\n", playerScore);
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        result = guess - getRandomNumber();

        if (result == 0) {
            printf("Congratulations! You guessed the number correctly!\n");
            playerScore++;
        } else if (result < 0) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! See you next time!\n");
}

int getRandomNumber() {
    return rand() % 100 + 1;
}