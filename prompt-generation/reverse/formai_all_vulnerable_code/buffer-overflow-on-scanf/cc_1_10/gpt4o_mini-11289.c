//GPT-4o-mini DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5
#define MAX_NUMBER 100

void drawWelcomeMessage() {
    printf("*******************************************\n");
    printf("*          Welcome to Guess the Number!  *\n");
    printf("*        Can you guess my number?        *\n");
    printf("*******************************************\n");
}

int generateRandomNumber() {
    srand(time(0));
    return rand() % MAX_NUMBER + 1;
}

void getFeedback(int guess, int actual) {
    if (guess > actual) {
        printf("Your guess is too high! Try again.\n");
    } else if (guess < actual) {
        printf("Your guess is too low! Try again.\n");
    } else {
        printf("Congratulations! You've guessed the correct number!\n");
    }
}

void playGame() {
    int numberToGuess = generateRandomNumber();
    int guess = 0;
    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("Enter your guess (1 to %d): ", MAX_NUMBER);
        scanf("%d", &guess);
        tries++;

        getFeedback(guess, numberToGuess);
        
        if (guess == numberToGuess) {
            break;
        }

        printf("You have %d tries left.\n", MAX_TRIES - tries);
    }

    if (guess != numberToGuess) {
        printf("Sorry, you've used all your tries. The number was %d.\n", numberToGuess);
    }
}

void drawGoodbyeMessage() {
    printf("*******************************************\n");
    printf("*         Thanks for playing!            *\n");
    printf("*        Hope to see you soon!           *\n");
    printf("*******************************************\n");
}

int main() {
    char playAgain;
    
    drawWelcomeMessage();

    do {
        playGame();
        
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    drawGoodbyeMessage();
    return 0;
}