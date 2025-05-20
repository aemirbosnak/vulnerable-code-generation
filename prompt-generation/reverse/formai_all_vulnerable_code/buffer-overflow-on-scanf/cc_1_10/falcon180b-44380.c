//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define NUM_PLAYERS 2

int table[TABLE_SIZE][TABLE_SIZE];
int players[NUM_PLAYERS];

void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = 0;
        }
    }
}

void init_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i] = 0;
    }
}

void draw_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (table[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

void play_game() {
    srand(time(NULL));
    init_table();
    init_players();

    int player = 0;
    while (1) {
        draw_table();
        int x, y;
        printf("Player %d's turn. Enter your move (row, column): ", player + 1);
        scanf("%d %d", &x, &y);
        if (table[x][y] == 0) {
            table[x][y] = (player % 2) + 1;
            player++;
            if (player >= NUM_PLAYERS) {
                printf("Game over! Player %d wins!\n", (player - 1) % 2 + 1);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    play_game();
    return 0;
}