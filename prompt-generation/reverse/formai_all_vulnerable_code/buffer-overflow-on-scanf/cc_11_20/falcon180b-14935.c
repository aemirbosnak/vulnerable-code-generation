//Falcon-180B DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_guesses, guess, target;
    int min = 1, max = 100;
    int correct_guesses = 0;
    int total_guesses = 0;
    int attempts_left = 10;
    int difficulty = 3;
    int user_difficulty;
    srand(time(NULL));
    target = rand() % (max - min + 1) + min;

    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number between %d and %d. Can you guess it?\n", min, max);
    printf("Difficulty level (1-5): ");
    scanf("%d", &user_difficulty);

    if (user_difficulty < 1 || user_difficulty > 5) {
        printf("Invalid difficulty level. Setting to default: %d\n", difficulty);
    } else {
        difficulty = user_difficulty;
    }

    if (difficulty == 1) {
        printf("Easy mode: You have %d attempts to guess the number.\n", attempts_left);
    } else if (difficulty == 2) {
        printf("Medium mode: You have %d attempts to guess the number.\n", attempts_left - 2);
    } else if (difficulty == 3) {
        printf("Hard mode: You have %d attempts to guess the number.\n", attempts_left - 3);
    } else if (difficulty == 4) {
        printf("Very hard mode: You have %d attempts to guess the number.\n", attempts_left - 4);
    } else {
        printf("Extremely hard mode: You have %d attempts to guess the number.\n", attempts_left - 5);
    }

    while (attempts_left > 0 && correct_guesses == 0) {
        printf("Guess a number: ");
        scanf("%d", &guess);
        total_guesses++;

        if (guess == target) {
            printf("Congratulations! You guessed the number in %d attempts.\n", total_guesses);
            correct_guesses = 1;
        } else if (guess < target) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        attempts_left--;
    }

    if (correct_guesses == 0) {
        printf("Sorry, you ran out of attempts. The number was %d.\n", target);
    }

    return 0;
}