//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SYM 4
#define LOWEST_SYM 0
#define HIGHEST_SYM 3

typedef enum { HEARTS, DIAMONDS, SPADES, CLUBS } Symbol;

Symbol get_random_symbol() {
    Symbol symbols[NUM_SYM] = {HEARTS, DIAMONDS, SPADES, CLUBS};
    int index = rand() % NUM_SYM;
    return symbols[index];
}

void print_symbol(Symbol sym) {
    switch (sym) {
        case HEARTS:
            printf("♥\n");
            break;
        case DIAMONDS:
            printf("♦\n");
            break;
        case SPADES:
            printf("♠\n");
            break;
        case CLUBS:
            printf("♣\n");
            break;
        default:
            printf("Invalid symbol\n");
            break;
    }
}

void game_start() {
    Symbol secret_symbol = get_random_symbol();
    int guess;
    int num_guesses = 0;

    printf("Welcome to the Guess the Love Symbol game!\n");
    printf("I have chosen a love symbol secretly. You have to guess it.\n");

    while (1) {
        printf("Enter your guess (%d): ", NUM_SYM);
        scanf("%d", &guess);

        if (guess < 0 || guess >= NUM_SYM) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        num_guesses++;
        if (guess == secret_symbol) {
            printf("Congratulations! You guessed the love symbol correctly.\n");
            printf("You made it in %d guesses.\n", num_guesses);
            break;
        } else {
            printf("Sorry, that's not the correct symbol. Try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));

    game_start();

    return 0;
}