//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define MAX_ATTEMPTS 10

void print_instructions() {
    printf("\nWelcome to Number Guessing Game!\n");
    printf("I will think of a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have %d attempts to guess it.\n", MAX_ATTEMPTS);
}

int generate_random_number() {
    srand(time(NULL));
    return rand() % (MAX_NUMBER + 1) + MIN_NUMBER;
}

int main() {
    int random_number, player_guess, attempts_left = MAX_ATTEMPTS;

    print_instructions();

    random_number = generate_random_number();

    while (attempts_left > 0) {
        printf("\nEnter your guess: ");
        scanf("%d", &player_guess);

        if (player_guess < 1 || player_guess > MAX_NUMBER) {
            printf("Invalid input! Please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        attempts_left--;

        if (player_guess > random_number) {
            printf("Too high! You have %d attempts left.\n", attempts_left);
        } else if (player_guess < random_number) {
            printf("Too low! You have %d attempts left.\n", attempts_left);
        } else {
            printf("Congratulations! You guessed the number %d correctly.\n", random_number);
            break;
        }
    }

    if (attempts_left == 0) {
        printf("Game Over! The number was %d.\n", random_number);
    }

    return 0;
}