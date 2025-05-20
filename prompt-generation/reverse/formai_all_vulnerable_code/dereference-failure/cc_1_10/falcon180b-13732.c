//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 24
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int card[ROWS][COLS];
} Player;

void print_card(Player* player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", player->card[i][j]);
        }
        printf("\n");
    }
}

int get_empty_cell(Player* player) {
    int row = 0, col = 0;
    while (row < ROWS && col < COLS) {
        if (player->card[row][col] == 0) {
            return row * COLS + col;
        }
        col++;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int players = 1;
    Player* player = malloc(sizeof(Player));
    player->id = 1;
    strcpy(player->name, "Player 1");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            player->card[i][j] = rand() % TOTAL_NUMBERS + 1;
        }
    }
    int called_numbers[TOTAL_NUMBERS];
    memset(called_numbers, 0, sizeof(called_numbers));
    int bingo_count = 0;
    while (bingo_count < players) {
        int num = rand() % TOTAL_NUMBERS + 1;
        if (num!= 0 &&!called_numbers[num]) {
            called_numbers[num] = 1;
            printf("Called number: %d\n", num);
            for (int k = 0; k < players; k++) {
                int cell = get_empty_cell(player + k);
                if (cell!= -1) {
                    player[k].card[cell / COLS][cell % COLS] = num;
                }
            }
        }
    }
    for (int k = 0; k < players; k++) {
        print_card(player + k);
    }
    return 0;
}