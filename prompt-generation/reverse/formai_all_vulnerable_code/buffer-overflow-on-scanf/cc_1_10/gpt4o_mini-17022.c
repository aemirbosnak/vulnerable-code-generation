//GPT-4o-mini DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRiddle() {
    printf("Welcome to the Number Guessing Riddle!\n");
    printf("I am a number between 1 and 100.\n");
    printf("I am more than 50 but less than 80.\n");
    printf("If you divide me by 10, the remainder is 3.\n");
    printf("What number am I?\n");
}

int main() {
    int target, guess, attempts = 10;
    int min = 51, max = 79; // based on the riddle's hints

    // Generate a random target number based on the riddle's constraints
    srand(time(NULL));
    target = (rand() % (max - min + 1)) + min;  // Random number within range [51, 79]

    printRiddle();

    printf("You have %d attempts to find the number.\n", attempts);

    while (attempts > 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check the guess
        if (guess < 1 || guess > 100) {
            printf("Out of bounds! Please guess a number between 1 and 100.\n");
            continue;
        }

        if (guess == target) {
            printf("Congratulations! You guessed the number %d correctly!\n", target);
            break;
        } else {
            printf("Incorrect guess.\n");
            attempts--;

            // Provide hints based on the guess
            if (guess < target) {
                printf("My number is higher than %d.\n", guess);
            } else {
                printf("My number is lower than %d.\n", guess);
            }

            if (attempts > 0) {
                printf("You have %d attempts remaining.\n", attempts);
            } else {
                printf("You have exhausted your attempts. The number was %d. Better luck next time!\n", target);
            }
        }
    }

    return 0;
}