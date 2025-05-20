//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define NUM_PLAYERS 2

// Function to generate a random number between min and max
int rand_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int secret_number, player_guess, winner = -1;
    int players[NUM_PLAYERS] = {0};
    int turns = 0;

    srand(time(NULL));

    // Generate a random secret number
    secret_number = rand_number(1, MAX_NUMBER);

    printf("Welcome to the Number Guessing Game!\n");
    printf("Two players will take turns to guess a number between 1 and %d.\n", MAX_NUMBER);

    while (winner == -1) {
        turns++;

        // Player 1's turn
        printf("\nPlayer 1, it's your turn. Guess the number: ");
        scanf("%d", &player_guess);

        if (player_guess == secret_number) {
            printf("Congratulations, Player 1! You guessed the number in %d turns.\n", turns);
            winner = 1;
            players[0] += turns;
        } else {
            printf("Sorry, Player 1. That's not the correct number. Try again.\n");
        }

        // Player 2's turn
        if (winner == -1) {
            printf("\nPlayer 2, it's your turn. Guess the number: ");
            scanf("%d", &player_guess);

            if (player_guess == secret_number) {
                printf("Congratulations, Player 2! You guessed the number in %d turns.\n", turns);
                winner = 2;
                players[1] += turns;
            } else {
                printf("Sorry, Player 2. That's not the correct number. Try again.\n");
            }
        }
    }

    printf("\nThe game is over! Player %d won.", winner + 1);
    printf("\nPlayer 1 scored %d points.\n", players[0]);
    printf("Player 2 scored %d points.\n", players[1]);

    return 0;
}