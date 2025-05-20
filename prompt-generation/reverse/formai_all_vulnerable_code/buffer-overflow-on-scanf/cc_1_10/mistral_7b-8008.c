//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define MIN_NUMBER 1
#define MAX_NUMBER 10
#define ROUND_NUMBER 5

void generateNumber(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void printResult(int player, int number) {
    if (number % 2 == 0) {
        printf("Player %d wins!\n", player);
    } else {
        printf("Player %d loses.\n", player);
    }
}

int main() {
    int players[NUM_PLAYERS];
    int number, winner = 0;
    int roundsWon[NUM_PLAYERS] = {0};

    srand(time(NULL));

    for (int round = 1; round <= ROUND_NUMBER; round++) {
        generateNumber(&number);

        for (int player = 1; player <= NUM_PLAYERS; player++) {
            printf("Player %d, predict the parity of the number: even or odd? ", player);
            scanf("%d", &players[player]);

            if (players[player] == number % 2) {
                roundsWon[player]++;
                winner = player;
                break;
            }
        }
    }

    for (int player = 1; player <= NUM_PLAYERS; player++) {
        printf("Player %d has won %d rounds.\n", player, roundsWon[player]);
    }

    printf("The game is over. Player %d has won the most rounds (%d).\n", winner, roundsWon[winner]);

    return 0;
}