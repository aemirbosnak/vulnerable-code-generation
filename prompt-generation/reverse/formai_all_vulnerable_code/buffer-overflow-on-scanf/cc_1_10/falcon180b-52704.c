//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER 'X'
#define COMPUTER 'O'
#define FULL_BOARD " 111 "

char board[ROWS][COLS];
int player_row, player_col;
int computer_row, computer_col;
int game_over;

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
    player_row = 0;
    player_col = 1;
    computer_row = 0;
    computer_col = 2;
    game_over = 0;
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == EMPTY) {
        return 1;
    }
    return 0;
}

void player_move() {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d%d", &row, &col);
    if (is_valid_move(row, col)) {
        board[row][col] = PLAYER;
        player_row = row;
        player_col = col;
        if (game_over == 0) {
            game_over = 1;
            printf("You win!\n");
        }
    } else {
        printf("Invalid move.\n");
    }
}

void computer_move() {
    int row, col;
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (!is_valid_move(row, col));
    board[row][col] = COMPUTER;
    computer_row = row;
    computer_col = col;
    if (game_over == 0) {
        game_over = 1;
        printf("Computer wins!\n");
    }
}

int main() {
    srand(time(NULL));
    init_board();
    while (game_over == 0) {
        print_board();
        player_move();
        computer_move();
        if (game_over == 0) {
            printf("Current board:\n");
        }
    }
    return 0;
}