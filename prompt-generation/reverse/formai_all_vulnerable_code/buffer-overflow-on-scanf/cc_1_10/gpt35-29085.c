//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function to get user's input */
int getInput() {
    int input;
    scanf("%d", &input);
    return input;
}

/* A function to display game's instructions */
void displayInstructions() {
    printf("\nWelcome to Guess The Number!\n");
    printf("A random number between 1 and 100 has been generated. You have to guess it.\n");
    printf("You will be given hints after each guess. Good luck!\n\n");
}

/* The main function */
int main() {
    int randomNumber, guessCount = 0;

    /* Initialize random number generator with current time */
    srand(time(0));

    /* Generate random number between 1 and 100 */
    randomNumber = (rand() % 100) + 1;

    /* Display game's instructions */
    displayInstructions();

    while(1) {
        int guess;

        printf("Enter your guess: ");
        guess = getInput();

        guessCount++;

        if(guess < randomNumber) {
            printf("Too low!\n");
        } else if(guess > randomNumber) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", guessCount);
            break;
        }
    }

    printf("\nThank you for playing!\n");

    return 0;
}