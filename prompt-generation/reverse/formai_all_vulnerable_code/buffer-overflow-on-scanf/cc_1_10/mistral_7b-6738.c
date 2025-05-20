//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 1
#define MAX_NUM 100

void generate_number(int *num);
void print_menu();
void play_game(int *num);

int main() {
    int number;
    generate_number(&number);

    printf("Welcome to the Number Guessing Game!\n");
    print_menu();

    play_game(&number);

    return 0;
}

void generate_number(int *num) {
    *num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
}

void print_menu() {
    printf("\nOptions:\n");
    printf("1. Guess the number\n");
    printf("2. Quit the game\n");
}

void play_game(int *num) {
    int guess, attempts = 0;
    char choice;

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess == *num) {
            printf("\nCongratulations! You guessed the number correctly.\n");
            printf("You took %d attempts to guess the number.\n", attempts);
            break;
        } else if (guess < *num) {
            printf("\nYour guess is too low. Try again.\n");
        } else {
            printf("\nYour guess is too high. Try again.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice != 'n');
}