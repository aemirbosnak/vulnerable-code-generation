//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void print_rules() {
    printf("***********************\n");
    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess the number between 1 and 100.\n");
    printf("You have a maximum of %d attempts.\n", MAX_ATTEMPTS);
    printf("Good luck!\n");
    printf("***********************\n");
}

int main() {
    int secret_number, guess, attempts = 0, score = 100;
    char play_again;

    // Seed random number generator
    srand(time(NULL));

    do {
        secret_number = (rand() % 100) + 1; // Number between 1 and 100
        attempts = 0;
        score = 100;

        print_rules();

        while (attempts < MAX_ATTEMPTS) {
            printf("Enter your guess (%d attempts left): ", MAX_ATTEMPTS - attempts);
            scanf("%d", &guess);
            attempts++;

            if (guess < 1 || guess > 100) {
                printf("Invalid guess! Please choose a number between 1 and 100.\n");
                attempts--; // do not count this attempt
                continue;
            }

            if (guess < secret_number) {
                printf("Too low! Try again.\n");
                score -= 10; // deduct points
            } else if (guess > secret_number) {
                printf("Too high! Try again.\n");
                score -= 10; // deduct points
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts!\n", secret_number, attempts);
                printf("Your score: %d\n", score);
                break; // correct guess
            }
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry! You've run out of attempts. The secret number was %d.\n", secret_number);
        }

        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &play_again);
    } while (play_again == 'Y' || play_again == 'y');

    printf("Thank you for playing!\n");

    return 0;
}