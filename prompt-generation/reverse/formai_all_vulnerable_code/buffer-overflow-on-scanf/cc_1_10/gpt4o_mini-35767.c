//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void print_instructions(int lower_bound, int upper_bound) {
    printf("Welcome to the Guess the Number Game!\n");
    printf("I have chosen a number between %d and %d.\n", lower_bound, upper_bound);
    printf("You have %d attempts to guess it.\n", MAX_ATTEMPTS);
    printf("Let's see if you can guess my number!\n\n");
}

int main() {
    int lower_bound = 1, upper_bound = 100;
    int random_number, guess, attempts = 0;

    // Seed the random number generator
    srand(time(NULL));
    random_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

    print_instructions(lower_bound, upper_bound);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);
        
        attempts++;

        if (guess < lower_bound || guess > upper_bound) {
            printf("Please enter a number between %d and %d.\n\n", lower_bound, upper_bound);
            attempts--; // Do not count invalid guess
            continue;
        }

        if (guess < random_number) {
            printf("Too low! Try again.\n\n");
        } else if (guess > random_number) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", random_number, attempts);
            break;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Sorry, you've used all your attempts! The number was %d.\n", random_number);
    }
    
    return 0;
}