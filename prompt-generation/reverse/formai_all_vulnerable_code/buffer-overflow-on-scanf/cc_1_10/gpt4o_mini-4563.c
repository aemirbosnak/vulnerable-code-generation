//GPT-4o-mini DATASET v1.0 Category: Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void print_instructions() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n", MAX_ATTEMPTS);
    printf("After each guess, I will give you hints whether the actual number is higher or lower.\n");
    printf("Good luck!\n");
}

int main() {
    int number_to_guess, player_guess, attempts = 0;

    // Seed the random number generator
    srand(time(NULL));
    number_to_guess = rand() % 100 + 1; // Random number between 1 and 100

    print_instructions();

    while (attempts < MAX_ATTEMPTS) {
        printf("\nEnter your guess: ");
        if (scanf("%d", &player_guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear the invalid input
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (player_guess < 1 || player_guess > 100) {
            printf("Your guess is out of range! Please guess a number between 1 and 100.\n");
        } else if (player_guess < number_to_guess) {
            printf("Higher! You've used %d out of %d attempts.\n", attempts, MAX_ATTEMPTS);
        } else if (player_guess > number_to_guess) {
            printf("Lower! You've used %d out of %d attempts.\n", attempts, MAX_ATTEMPTS);
        } else {
            printf("Congratulations! You've guessed the number %d correctly in %d attempts.\n", number_to_guess, attempts);
            break;
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry, you've used all your attempts. The number was %d.\n", number_to_guess);
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}