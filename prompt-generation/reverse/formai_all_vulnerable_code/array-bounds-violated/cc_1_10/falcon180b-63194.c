//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define NUM_PLAYERS 4
#define NUM_TURNS 10
#define NUM_ROUNDS 5
#define MAX_SCORE 100

int player_scores[NUM_PLAYERS];
int current_player = 0;
int current_round = 0;
int current_turn = 0;
int game_over = 0;

void print_scores() {
    printf("Player scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", i+1, player_scores[i]);
    }
    printf("\n");
}

void start_game() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLAYERS; i++) {
        player_scores[i] = rand() % MAX_SCORE;
    }
    current_player = 0;
    current_round = 0;
    current_turn = 0;
    game_over = 0;
}

int play_turn(int player_num) {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int move = dice1 + dice2;
    if (move == 7 || move == 11 || move == 2 || move == 3 || move == 12) {
        printf("Player %d rolled a %d and %d for a total of %d. They move forward %d spaces.\n", player_num+1, dice1, dice2, move, move);
    } else {
        printf("Player %d rolled a %d and %d for a total of %d. They move forward 1 space.\n", player_num+1, dice1, dice2, move);
    }
    return move;
}

void play_round() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int move = play_turn(i);
        if (move > current_player) {
            current_player = move;
        }
    }
    if (current_player >= NUM_TURNS) {
        printf("Player %d has completed the game!\n", current_player+1);
        player_scores[current_player] += 10;
        current_player = (current_player+1) % NUM_PLAYERS;
        current_round++;
        if (current_round >= NUM_ROUNDS) {
            game_over = 1;
        }
    } else {
        current_turn++;
    }
}

int main() {
    start_game();
    while (!game_over) {
        play_round();
        print_scores();
    }
    return 0;
}