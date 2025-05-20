//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 20
#define SECRET_NUMBER_MIN 1
#define SECRET_NUMBER_MAX 100

void print_surprise_message() {
    const char *surprises[] = {
        "🎉 Surprise! You're doing great!",
        "🤔 Keep going! You will get it soon!",
        "🎊 Almost there! Don't give up!",
        "🤯 Wow! So close! Can you feel the excitement?",
        "🥳 Fantastic effort! Just a bit more!"
    };

    int random_index = rand() % (sizeof(surprises) / sizeof(surprises[0]));
    printf("%s\n", surprises[random_index]);
}

int main() {
    int secret_number, guess, attempts = 0;

    srand(time(NULL));
    secret_number = rand() % (SECRET_NUMBER_MAX - SECRET_NUMBER_MIN + 1) + SECRET_NUMBER_MIN;

    printf("Welcome to the Surprise Number Guessing Game!\n");
    printf("I've picked a number between %d and %d. Can you guess it?\n", SECRET_NUMBER_MIN, SECRET_NUMBER_MAX);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < SECRET_NUMBER_MIN || guess > SECRET_NUMBER_MAX) {
            printf("📍 That's out of bounds! Try again.\n");
            continue;
        }

        attempts++;

        if (guess < secret_number) {
            printf("🔻 Your guess is too low!\n");
        } else if (guess > secret_number) {
            printf("🔺 Your guess is too high!\n");
        } else {
            printf("🎉 Congratulations! You guessed the number %d in %d attempts!\n", secret_number, attempts);
            break;
        }

        // Surprise message every 5 attempts
        if (attempts % 5 == 0) {
            print_surprise_message();
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("😱 You've used all your attempts! The number was %d. Better luck next time!\n", secret_number);
        }
    }

    return 0;
}