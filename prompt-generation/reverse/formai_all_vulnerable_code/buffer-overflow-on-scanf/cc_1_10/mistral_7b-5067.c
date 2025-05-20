//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define MIN_NUMBER 1
#define MAX_NUMBER 10

void generate_random_number(int *number);
void print_menu();
void print_winner(int players[NUM_PLAYERS], int number);

int main() {
    int players[NUM_PLAYERS] = {0};
    int number, guess;
    int i;

    srand(time(NULL));

    generate_random_number(&number);

    print_menu();

    for (i = 0; i < NUM_PLAYERS; i++) {
        do {
            printf("Player %d, guess the number: ", i + 1);
            scanf("%d", &guess);
        } while (guess != number);

        players[i] = 1;

        printf("Player %d guessed the number correctly! \n", i + 1);
    }

    print_winner(players, number);

    return 0;
}

void generate_random_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_menu() {
    printf("--------------------------------------\n");
    printf("| Welcome to the Number Guessing Game! |\n");
    printf("--------------------------------------\n");
    printf("| This game is for %d players.         |\n", NUM_PLAYERS);
    printf("--------------------------------------\n");
}

void print_winner(int players[NUM_PLAYERS], int number) {
    int i;

    printf("--------------------------------------\n");
    printf("|       The number was: %d           |\n", number);
    printf("--------------------------------------\n");

    for (i = 0; i < NUM_PLAYERS; i++) {
        if (players[i] == 0) {
            printf("| Player %d did not guess the number. |\n", i + 1);
        }
    }

    printf("--------------------------------------\n");

    for (i = 0; i < NUM_PLAYERS; i++) {
        if (players[i] == 1) {
            printf("| Player %d guessed the number correctly. |\n", i + 1);
        }
    }

    printf("--------------------------------------\n");
}