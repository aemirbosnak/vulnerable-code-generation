//GPT-4o-mini DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_surprise_message(int attempts)
{
    if (attempts == 1) {
        printf("Wow! You guessed it on your first try! You're a wizard!\n");
    } else if (attempts <= 3) {
        printf("Amazing! You've got a fantastic intuition!\n");
    } else if (attempts <= 5) {
        printf("Not bad! You've got some good instincts!\n");
    } else {
        printf("Well, better luck next time! Practice makes perfect!\n");
    }
}

int main()
{
    int number, guess, attempts = 0;
    const int max_attempts = 10;

    // Initialize random number generator
    srand(time(NULL));
    number = rand() % 100 + 1;  // Random number between 1 and 100

    printf("Welcome to the Surprise Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");

    while (attempts < max_attempts)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please stick to the range! It's between 1 and 100.\n");
            attempts--; // Do not count invalid attempts
            continue;
        }

        if (guess == number) {
            printf("Congratulations! You've guessed the number %d in %d tries!\n", number, attempts);
            print_surprise_message(attempts);
            break;
        } else {
            if (abs(guess - number) <= 10) {
                printf("You're close! Try again!\n");
            } else {
                printf("Not even close. Give it another shot!\n");
            }

            if (attempts == max_attempts) {
                printf("Oops! You've used all your attempts! The number was %d.\n", number);
            }
        }
    }

    printf("Thanks for playing! See you next time!\n");
    return 0;
}