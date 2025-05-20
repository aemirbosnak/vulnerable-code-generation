//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("In this game, the computer will randomly select a number between 1 and 100.\n");
    printf("Your task is to correctly guess the number. Good luck!\n\n");

    srand(time(NULL)); // Seed the random number generator with the current time
    int number = rand() % 100 + 1; // Generate a random number between 1 and 100

    int guess;
    int tries = 0;

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        tries++;

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);

            while (1) {
                printf("Do you want to play again? (y/n) ");

                char answer;
                scanf(" %c", &answer);

                if (answer == 'y') {
                    // Reset all variables and generate a new random number
                    number = rand() % 100 + 1;
                    guess = 0;
                    tries = 0;
                    break;
                } else if (answer == 'n') {
                    printf("Thanks for playing! Goodbye.\n");
                    return 0;
                } else {
                    printf("Invalid input.\n");
                }
            }
        }
    }
}