//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

typedef struct Player {
    int number;
    int score;
} Player;

void generate_number(int *number);
void announce_winner(Player players[], int num_players);

int main() {
    int num_players, i;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Number Guessing Game!\n");
    printf("Please enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Error: Maximum number of players exceeded.\n");
        return 1;
    }

    srand(time(NULL));
    int secret_number;
    generate_number(&secret_number);

    for (i = 0; i < num_players; i++) {
        players[i].score = 0;
    }

    printf("\nPlayer turn:\n");
    for (i = 0; i < num_players; i++) {
        int guess;
        printf("Player %d, please guess a number between %d and %d: ", i + 1, MIN_NUMBER, MAX_NUMBER);
        scanf("%d", &guess);

        if (guess == secret_number) {
            players[i].score += 10;
            printf("Congratulations! You guessed the number correctly.\n");
        } else {
            players[i].score -= 5;
            printf("Sorry, that's not the correct number. The number was %d.\n", secret_number);
        }

        printf("Player %d's current score is %d.\n", i + 1, players[i].score);
    }

    announce_winner(players, num_players);

    return 0;
}

void generate_number(int *number) {
    *number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void announce_winner(Player players[], int num_players) {
    int max_score_index = 0;
    int max_score = players[0].score;

    for (int i = 1; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            max_score_index = i;
        }
    }

    printf("\nThe game is over. The winner is Player %d with a score of %d.\n", max_score_index + 1, max_score);
}