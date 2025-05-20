//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 3

int main() {
    srand(time(NULL));
    int num_players = rand() % MAX_PLAYERS + 2;
    int players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        players[i] = i + 1;
    }
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 100;
        }
    }
    int turn = 0;
    while (turn < num_players * BOARD_SIZE * BOARD_SIZE) {
        int player = players[turn % num_players];
        int x = turn / (BOARD_SIZE * num_players);
        int y = turn % BOARD_SIZE;
        printf("Player %d's turn: ", player);
        int move;
        scanf("%d", &move);
        if (move < 1 || move > BOARD_SIZE) {
            printf("Invalid move.\n");
        } else {
            int value = board[x][y];
            board[x][y] = 0;
            int sum = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                sum += board[x][i];
            }
            for (int i = 0; i < BOARD_SIZE; i++) {
                sum += board[i][y];
            }
            if (value > 0 && (sum % value == 0 || value == 1)) {
                board[x][y] = value;
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
        }
        turn++;
    }
    printf("Game over.\n");
    return 0;
}