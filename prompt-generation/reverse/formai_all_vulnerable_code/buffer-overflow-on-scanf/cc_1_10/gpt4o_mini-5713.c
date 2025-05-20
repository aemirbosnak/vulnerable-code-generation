//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void display_instructions() {
    printf("Welcome to 'Guess the Number'!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have to guess the number within %d attempts!\n", MAX_ATTEMPTS);
    printf("Good luck!\n");
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void play_game() {
    int target_number;
    int guess;
    int attempts_left = MAX_ATTEMPTS;

    target_number = get_random_number(1, 100);
    printf("I have selected a number between 1 and 100. Try to guess it!\n");

    while (attempts_left > 0) {
        printf("You have %d attempts left. Enter your guess: ", attempts_left);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }

        attempts_left--;
        
        if (guess < target_number) {
            printf("Too low! Try again.\n");
        } else if (guess > target_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d correctly!\n", target_number);
            return;
        }
    }

    printf("You've run out of attempts! The number was %d. Better luck next time!\n", target_number);
}

int main() {
    int keep_playing = 1;

    srand(time(NULL));  // Seed the random number generator

    display_instructions();

    while (keep_playing) {
        play_game();

        printf("Do you want to play again? (1 for YES, 0 for NO): ");
        scanf("%d", &keep_playing);
    }

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}