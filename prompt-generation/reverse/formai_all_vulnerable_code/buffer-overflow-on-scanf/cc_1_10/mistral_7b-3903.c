//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 10
#define MAX_TRIES 5

void generate_random_number(int *number);
void print_game_instructions();
void print_game_over_message(int number, int tries);
int user_guess(int number, int tries);

int main() {
    int number, user_guess_number, tries = 0;

    srand(time(NULL));
    generate_random_number(&number);

    print_game_instructions();

    do {
        user_guess_number = user_guess(number, tries);
        tries++;

        if (user_guess_number == number) {
            print_game_over_message(number, tries);
            break;
        } else {
            printf("Wrong guess! The number was %d. Try again.\n", number);
        }
    } while (tries < MAX_TRIES);

    if (tries == MAX_TRIES) {
        printf("Game over! You have run out of tries.\n");
        printf("The number was %d.\n", number);
    }

    return 0;
}

void generate_random_number(int *number) {
    *number = rand() % (MAX_NUMBER + 1) + MIN_NUMBER;
}

void print_game_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I will generate a random number between 1 and 10.\n");
    printf("Your task is to guess the number within 5 tries.\n");
    printf("Ready? Let's begin!\n");
}

void print_game_over_message(int number, int tries) {
    printf("Congratulations! You have guessed the number %d within %d tries.\n", number, tries);
}

int user_guess(int number, int tries) {
    int guess;

    scanf("%d", &guess);

    return guess;
}