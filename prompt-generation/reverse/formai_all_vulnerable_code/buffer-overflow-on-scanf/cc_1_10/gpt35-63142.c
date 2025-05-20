//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the surprise C Table Game!\n");
    printf("In this game, you will be playing against a computer.\n");
    printf("The goal of the game is to successfully guess the numbers in the table.\n");
    printf("The numbers will be between 0 and 4, inclusive.\n");
    printf("You will have three chances to guess the correct number in each round.\n");
    printf("Let's get started!\n\n");

    srand(time(NULL)); // initialize random number generator

    int table[5][5];
    int i, j;

    // generate random table
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            table[i][j] = rand() % 5;
        }
    }

    // display table
    printf("Here is the table:\n\n");
    printf("    0 1 2 3 4\n");
    printf("   -----------\n");
    for (i = 0; i < 5; i++) {
        printf("%d | ", i);
        for (j = 0; j < 5; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int round, guess, correctGuesses = 0;

    for (round = 1; round <= 5; round++) {
        printf("Round %d\n", round);

        // computer guesses correct number
        int computerGuess = rand() % 5;
        printf("The computer guessed %d.\n", computerGuess);

        // player guesses number
        int chances = 3;
        do {
            printf("You have %d chances to guess the correct number.\n", chances);
            printf("Enter your guess (between 0 and 4): ");
            scanf("%d", &guess);

            if (guess == computerGuess) {
                printf("Congratulations! You guessed the correct number.\n\n");
                correctGuesses++;
                break;
            } else {
                printf("Sorry, that is not the correct number.\n");
                chances--;
            }
        } while (chances > 0);

        if (chances == 0) {
            printf("Sorry, you ran out of chances. The correct number was %d.\n\n", computerGuess);
        }
    }

    printf("Game over! You guessed %d out of 5 correct numbers.\n", correctGuesses);

    return 0;
}