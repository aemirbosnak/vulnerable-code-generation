//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int x;
    int y;
    char state;
} Cell;

Cell cells[BOARD_SIZE][BOARD_SIZE] = {{
    {.x = 0, .y = 0, .state = ' '},
    {.x = 0, .y = 1, .state = ' '},
    {.x = 0, .y = 2, .state = ' '},

    {.x = 1, .y = 0, .state = ' '},
    {.x = 1, .y = 1, .state = ' '},
    {.x = 1, .y = 2, .state = ' '},

    {.x = 2, .y = 0, .state = ' '},
    {.x = 2, .y = 1, .state = ' '},
    {.x = 2, .y = 2, .state = ' '}
}};

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cells[i][j].state == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int game_round = 0;
    char current_player = 'X';

    while (!is_board_full()) {
        int move_x, move_y;

        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        if (cells[move_x][move_y].state != ' ') {
            printf("Invalid move.\n");
            continue;
        }

        cells[move_x][move_y].state = current_player;

        game_round++;

        if (game_round % 2 == 0) {
            current_player = 'O';
        } else {
            current_player = 'X';
        }
    }

    printf("Game over!\n");

    return 0;
}