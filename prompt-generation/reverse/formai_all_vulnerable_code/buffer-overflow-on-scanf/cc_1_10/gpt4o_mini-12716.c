//GPT-4o-mini DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void print_welcome_message() {
    printf("🎉 Welcome to the Number Guessing Adventure! 🎉\n");
    printf("Can you guess the secret number? Let's find out!\n");
    printf("You have a maximum of %d attempts to guess correctly.\n\n", MAX_ATTEMPTS);
}

int get_random_number(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int play_game(int round) {
    int lower = 1;
    int upper = 100;
    int secret_number = get_random_number(lower, upper);
    int guess;
    int attempts = 0;
    int score = 100; // Player starts with a score of 100

    printf("🕵️‍♂️ Round %d: Guess the number between %d and %d.\n", round, lower, upper);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your guess -> ", attempts + 1);
        scanf("%d", &guess);

        attempts++;

        if (guess < lower || guess > upper) {
            printf("🚫 Please guess a number within the given range!\n");
            attempts--; // Don't count an invalid attempt
            continue;
        }

        if (guess == secret_number) {
            printf("🎉 Congratulations! You've guessed the number %d correctly!\n", secret_number);
            printf("Your score for this round: %d\n", score);
            return score; // Return the score if guessed correctly
        } else if (guess < secret_number) {
            printf("😕 Too low! Try again.\n");
        } else {
            printf("😕 Too high! Try again.\n");
        }

        // Decrease score for each wrong attempt
        score -= (100 / MAX_ATTEMPTS);
    }

    printf("😢 Sorry! You've used all attempts. The secret number was %d\n\n", secret_number);
    return 0; // Return zero if not guessed correctly
}

int main() {
    srand(time(0)); // Seed for random number generation
    int total_score = 0;
    int rounds = 3; // Let's play 3 rounds for more fun!

    print_welcome_message();

    for (int round = 1; round <= rounds; round++) {
        total_score += play_game(round);
    }

    printf("🎊 Game Over! Your total score after %d rounds: %d\n", rounds, total_score);
    if (total_score > 0) {
        printf("🌟 You did great! Thanks for playing!\n");
    } else {
        printf("😓 Better luck next time! Keep practicing!\n");
    }

    return 0;
}