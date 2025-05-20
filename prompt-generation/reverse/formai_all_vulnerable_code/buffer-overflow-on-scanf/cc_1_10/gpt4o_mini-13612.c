//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSurpriseMessage(int attempts) {
    if (attempts == 1) {
        printf("Wow! You guessed it on the first try! You're a mind reader!\n");
    } else if (attempts <= 3) {
        printf("Impressive! You got it in just a few tries! Do you do this for a living?\n");
    } else if (attempts <= 5) {
        printf("Not bad! You got it in a decent amount of tries. Keep it up!\n");
    } else if (attempts <= 10) {
        printf("Hmm, looks like you need a bit more practice. But don't give up!\n");
    } else {
        printf("Wow, you really had to work for this one! Good persistence!\n");
    }
}

int main() {
    int secretNumber, userGuess, attempts = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(NULL));

    do {
        // Generate a secret number between 1 and 100
        secretNumber = rand() % 100 + 1;

        printf("WOW! A secret number has been generated between 1 and 100! Can you guess it? (Enter your guess):\n");

        // Reset attempts for each round
        do {
            attempts++;
            printf("Your guess: ");
            scanf("%d", &userGuess);

            if (userGuess < secretNumber) {
                printf("Oops! Too low! Try again.\n");
            } else if (userGuess > secretNumber) {
                printf("Whoa! Too high! Give it another go.\n");
            } else {
                printf("YAY! You've guessed the secret number %d!\n", secretNumber);
                printSurpriseMessage(attempts);
            }

        } while (userGuess != secretNumber);

        printf("Would you like to play again? (y/n): ");
        getchar();  // to consume the newline left by previous input
        scanf("%c", &playAgain);
        attempts = 0;  // Reset attempts for the next game

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! See you next time!\n");
    return 0;
}