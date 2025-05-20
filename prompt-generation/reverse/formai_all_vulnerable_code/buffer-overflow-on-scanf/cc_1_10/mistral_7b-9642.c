//MISTRAL-7B DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void generate_random_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int main() {
    int user_guess, computer_guess, number, attempts = 0;
    char guess_result;

    srand(time(NULL));

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);

    generate_random_number(&number);

    do {
        attempts++;
        printf("\nYour turn! Enter your guess: ");
        scanf("%d", &user_guess);

        if (user_guess > number) {
            printf("Too high! Try again.\n");
        } else if (user_guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d correctly in %d attempts!\n", number, attempts);
            break;
        }

        generate_random_number(&computer_guess);

        if (user_guess > number) {
            printf("Computer guessed: %d (too low)\n", computer_guess);
        } else if (user_guess < number) {
            printf("Computer guessed: %d (too high)\n", computer_guess);
        } else {
            printf("Computer guessed the number %d in %d attempts!\n", number, attempts);
        }

    } while (user_guess != number);

    return 0;
}