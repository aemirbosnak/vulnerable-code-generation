//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_PLAYERS 2
#define BOARD_SIZE 10
#define MAX_TURNS 100

int players[NUM_PLAYERS];
int turns = 0;
int board[BOARD_SIZE][BOARD_SIZE] = {{0}};

void print_board() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col) {
    if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
        return 1;
    }
    return 0;
}

void make_move(int player, int row, int col) {
    board[row][col] = player;
    turns++;
    if(turns == MAX_TURNS) {
        printf("Game over! Player %d wins!\n", player);
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    int i;
    for(i = 0; i < NUM_PLAYERS; i++) {
        players[i] = rand() % 2;
    }
    int current_player = 0;
    while(1) {
        system("clear");
        print_board();
        printf("Player %d's turn\n", players[current_player]);
        int choice;
        scanf("%d", &choice);
        if(!is_valid_move(choice/BOARD_SIZE, choice%BOARD_SIZE)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        make_move(players[current_player], choice/BOARD_SIZE, choice%BOARD_SIZE);
        if(turns >= MAX_TURNS) {
            break;
        }
        current_player = (current_player + 1) % NUM_PLAYERS;
    }
    return 0;
}