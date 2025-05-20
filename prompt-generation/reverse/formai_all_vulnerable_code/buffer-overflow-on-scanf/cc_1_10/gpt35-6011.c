//FormAI DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 'min' and 'max'
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if the guessed number is correct or not
bool is_guess_correct(int guess, int random_number) {
    if (guess == random_number) {
        printf("Congratulations! You guessed it right.\n");
        return true;
    } else if (guess < random_number) {
        printf("Your guess is too low. Try again!\n");
        return false;
    } else {
        printf("Your guess is too high. Try again!\n");
        return false;
    }
}

int main() {
    srand(time(NULL));  // Initialize random seed

    int min_number, max_number, number_of_guesses;
    printf("Enter the minimum number: ");
    scanf("%d", &min_number);
    printf("Enter the maximum number: ");
    scanf("%d", &max_number);
    printf("Enter the number of guesses: ");
    scanf("%d", &number_of_guesses);

    int random_number = generate_random_number(min_number, max_number);

    printf("Guess a number between %d and %d\n", min_number, max_number);

    for (int i = 1; i <= number_of_guesses; i++) {
        int guess;
        printf("Guess #%d: ", i);
        scanf("%d", &guess);
        if (is_guess_correct(guess, random_number)) {
            break;
        }
    }

    printf("Thanks for playing.\n");

    return 0;
}