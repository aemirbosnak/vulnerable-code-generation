//Falcon-180B DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int board[ROWS][COLS] = {0};
int player_pos_row = 0;
int player_pos_col = 0;
int player_pos_dir = 0;
int game_over = 0;

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 1;
        }
    }
    board[ROWS / 2][COLS / 2] = 0;
    player_pos_row = ROWS / 2;
    player_pos_col = COLS / 2;
    player_pos_dir = 0;
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void move_player(int dir) {
    int new_row = player_pos_row + dir;
    int new_col = player_pos_col + dir;

    if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS) {
        if (board[new_row][new_col] == 0) {
            player_pos_row = new_row;
            player_pos_col = new_col;
        }
    }
}

int main() {
    srand(time(NULL));
    init_board();

    while (!game_over) {
        print_board();

        int choice;
        printf("Enter your move (w/a/s/d): ");
        scanf("%d", &choice);
        move_player(choice);

        if (player_pos_row == 0 && player_pos_col == 0) {
            printf("You won!\n");
            game_over = 1;
        } else if (player_pos_row == ROWS - 1 && player_pos_col == COLS - 1) {
            printf("You lost!\n");
            game_over = 1;
        }
    }

    return 0;
}