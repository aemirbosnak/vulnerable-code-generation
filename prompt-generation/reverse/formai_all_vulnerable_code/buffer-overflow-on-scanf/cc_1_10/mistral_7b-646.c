//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

typedef struct {
    int number;
    int guess;
    int status;
} Player;

void generateRandomNumber(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

int checkGuess(int number, int guess) {
    if (number == guess) {
        return 1;
    }
    return 0;
}

void printTable(Player players[TABLE_SIZE]) {
    printf("+---+---+---+\n");
    printf("| Number | Guess | Status |\n");
    printf("+---+---+---+\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("| %2d | %2d | %5s |\n", players[i].number, players[i].guess,
               checkGuess(players[i].number, players[i].guess) ? "Correct" : "Incorrect");
    }
    printf("+---+---+---+\n");
}

int main() {
    srand(time(NULL));
    Player players[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        generateRandomNumber(&(players[i].number));
        players[i].guess = -1;
        players[i].status = "Waiting";
    }

    int round = 1;
    while (1) {
        printf("Round %d:\n", round);
        printTable(players);

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (players[i].guess == -1) {
                printf("Player %d, enter your guess: ", i + 1);
                scanf("%d", &(players[i].guess));
            }
        }

        int correctGuessCount = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (checkGuess(players[i].number, players[i].guess)) {
                players[i].status = "Correct";
                correctGuessCount++;
            } else {
                players[i].status = "Incorrect";
            }
        }

        if (correctGuessCount == TABLE_SIZE) {
            printf("Congratulations! All players guessed the number correctly.\n");
            break;
        }

        round++;
    }

    return 0;
}