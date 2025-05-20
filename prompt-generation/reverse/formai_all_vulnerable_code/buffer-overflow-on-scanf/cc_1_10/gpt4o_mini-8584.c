//GPT-4o-mini DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10
#define MAX_ATTEMPTS 5
#define SECRET_RANGE 100

int get_random_number() {
    return rand() % SECRET_RANGE + 1; // Random number between 1 and 100
}

void record_history(int history[], int index, int number) {
    history[index % MAX_HISTORY] = number; // Circular record of the last MAX_HISTORY numbers
}

void display_history(int history[], int count) {
    printf("History of your guesses: ");
    for (int i = 0; i < count && i < MAX_HISTORY; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int secret_number = get_random_number();
    int guess = 0;
    int attempts = 0;
    int history[MAX_HISTORY] = {0};
    
    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and %d. Can you guess it?\n", SECRET_RANGE);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d/%d: Enter your guess: ", attempts + 1, MAX_ATTEMPTS);
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input, please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue; // Prompt again
        }

        record_history(history, attempts, guess);
        attempts++;

        if (guess < 1 || guess > SECRET_RANGE) {
            printf("Your guess must be between 1 and %d.\n", SECRET_RANGE);
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d correctly!\n", secret_number);
            break;
        }

        display_history(history, attempts);
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Sorry, you've used all your attempts. The secret number was %d.\n", secret_number);
    }

    return 0;
}