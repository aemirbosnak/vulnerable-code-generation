//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 1
#define MAX_RANGE 100

void print_instruction() {
    printf("\nWelcome to Number Guessing Game!\n");
    printf("Guess a number between %d and %d.\n", MIN_RANGE, MAX_RANGE);
}

int random_number() {
    return rand() % (MAX_RANGE + 1 - MIN_RANGE) + MIN_RANGE;
}

void print_game_over(int user_guess, int secret_number) {
    if (user_guess < secret_number)
        printf("Your guess is too low. The secret number was %d.\n", secret_number);
    else if (user_guess > secret_number)
        printf("Your guess is too high. The secret number was %d.\n", secret_number);
    else
        printf("Congratulations! You've guessed the number %d.\n", secret_number);
}

int main() {
    srand(time(NULL));
    int secret_number = random_number();
    int user_guess;

    print_instruction();

    while (1) {
        scanf("%d", &user_guess);

        if (user_guess < MIN_RANGE || user_guess > MAX_RANGE) {
            printf("Invalid input. Please input a number between %d and %d.\n", MIN_RANGE, MAX_RANGE);
            continue;
        }

        if (user_guess == secret_number)
            break;

        printf("Try again.\n");
    }

    print_game_over(user_guess, secret_number);

    return 0;
}