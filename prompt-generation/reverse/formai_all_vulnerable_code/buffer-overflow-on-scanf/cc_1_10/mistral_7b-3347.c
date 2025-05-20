//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void print_instruction() {
    printf("\nWelcome to Number Guessing Game!\n");
    printf("I will generate a random number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("Your task is to guess the number in the least number of attempts.\n");
}

int generate_random_number() {
    return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_game_over_message(int user_guess, int random_number) {
    if (user_guess > random_number) {
        printf("Sorry, your guess %d is too high. The correct answer was %d.\n", user_guess, random_number);
    } else if (user_guess < random_number) {
        printf("Sorry, your guess %d is too low. The correct answer was %d.\n", user_guess, random_number);
    } else {
        printf("Congratulations! You guessed the number %d correctly.\n", random_number);
    }
}

int main() {
    srand(time(NULL));
    int random_number = generate_random_number();
    int user_guess;
    int attempts = 1;

    print_instruction();

    while (1) {
        printf("\nEnter your guess: ");
        scanf("%d", &user_guess);

        attempts++;

        print_game_over_message(user_guess, random_number);

        if (user_guess == random_number) {
            break;
        }
    }

    printf("You took %d attempts to guess the number.\n", attempts);

    return 0;
}