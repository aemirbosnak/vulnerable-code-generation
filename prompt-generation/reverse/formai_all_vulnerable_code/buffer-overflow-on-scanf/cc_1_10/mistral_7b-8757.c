//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 10

void print_intro() {
    printf("\n\n");
    printf("------------------------------------------\n");
    printf("|                                        |\n");
    printf("| Welcome to Ada's Number Guessing Game!   |\n");
    printf("|                                        |\n");
    printf("------------------------------------------\n");
}

int generate_random_number() {
    srand(time(NULL));
    return rand() % (MAX_NUMBER + 1) + MIN_NUMBER;
}

void print_game_over(int user_guess, int number_to_guess) {
    if (user_guess > number_to_guess) {
        printf("Sorry, your guess is too high. The number was %d.\n", number_to_guess);
    } else if (user_guess < number_to_guess) {
        printf("Sorry, your guess is too low. The number was %d.\n", number_to_guess);
    } else {
        printf("Congratulations! You have guessed the number %d correctly.\n", number_to_guess);
    }
}

int main() {
    int number_to_guess = generate_random_number();
    int user_guess;

    print_intro();

    do {
        printf("Please guess a number between 1 and 10: ");
        scanf("%d", &user_guess);

        print_game_over(user_guess, number_to_guess);

    } while (user_guess != number_to_guess);

    printf("------------------------------------------\n");
    printf("|                                        |\n");
    printf("| Game Over! Thank you for playing!        |\n");
    printf("|                                        |\n");
    printf("------------------------------------------\n");

    return 0;
}