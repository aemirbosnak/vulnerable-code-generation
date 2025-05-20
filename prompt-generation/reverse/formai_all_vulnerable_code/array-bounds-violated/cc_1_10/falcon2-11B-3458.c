//Falcon2-11B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define BOARD_SIZE 3

typedef enum {PLAYER_X, PLAYER_O} Player;

typedef struct {
    Player player;
    int moves[BOARD_SIZE][BOARD_SIZE];
} Board;

void print_board(Board board);
Player get_player(Board board);
int is_valid_move(Board board, int row, int col);
void make_move(Board board, int row, int col, Player player);
void end_game(Board board, int result);

int main() {
    Board board;
    int row, col, player;

    srand(time(NULL));
    player = PLAYER_X;
    make_move(board, 0, 0, player);

    while (1) {
        print_board(board);
        printf("Player %c's turn\n", get_player(board) == PLAYER_X? 'X' : 'O');
        scanf("%d %d", &row, &col);
        if (!is_valid_move(board, row, col)) {
            printf("Invalid move!\n");
            continue;
        }
        make_move(board, row, col, get_player(board));
        player = (player == PLAYER_X)? PLAYER_O : PLAYER_X;
    }

    return 0;
}

void print_board(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board.moves[i][j]);
        }
        printf("\n");
    }
}

Player get_player(Board board) {
    return (board.moves[0][0] == 0)? PLAYER_X : PLAYER_O;
}

int is_valid_move(Board board, int row, int col) {
    return board.moves[row][col] == 0;
}

void make_move(Board board, int row, int col, Player player) {
    board.moves[row][col] = player;
    if (row == 2 && col == 2) {
        end_game(board, 1);
    }
}

void end_game(Board board, int result) {
    if (result == 1) {
        printf("Player %c wins!\n", get_player(board) == PLAYER_X? 'X' : 'O');
    } else if (result == 0) {
        printf("It's a draw!\n");
    }
}