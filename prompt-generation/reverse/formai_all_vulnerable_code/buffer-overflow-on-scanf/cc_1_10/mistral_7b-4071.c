//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

typedef struct {
    int number;
    int points;
} Player;

Player players[MAX_PLAYERS];
int secret_number;
int current_round = 1;
int current_player = 1;
int highest_guess = MIN_NUMBER;
int round_ended = 0;

void init_game() {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].number = i + 1;
        players[i].points = 0;
    }

    srand(time(NULL));
    secret_number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

void print_round_info() {
    printf("\nRound %d\n", current_round);
    printf("Player %d's turn\n", current_player);
    printf("Current highest guess: %d\n", highest_guess);
}

void take_turn(int player_number) {
    int guess;

    print_round_info();
    scanf("%d", &guess);

    if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
        printf("Invalid guess! Please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
        take_turn(player_number);
        return;
    }

    if (guess == secret_number) {
        printf("Congratulations, Player %d! You guessed the number %d and won the round.\n", player_number, secret_number);
        players[player_number - 1].points++;
        highest_guess = guess;
        round_ended = 1;
        return;
    } else {
        printf("Sorry, Player %d, your guess of %d is incorrect.\n", player_number, guess);
    }
}

void next_player() {
    current_player++;

    if (current_player > MAX_PLAYERS) {
        current_player = 1;
    }
}

int main() {
    int i;

    init_game();

    while (!round_ended) {
        take_turn(current_player);
        next_player();
    }

    printf("\nGame Over!\n");

    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d scored %d points.\n", players[i].number, players[i].points);
    }

    return 0;
}