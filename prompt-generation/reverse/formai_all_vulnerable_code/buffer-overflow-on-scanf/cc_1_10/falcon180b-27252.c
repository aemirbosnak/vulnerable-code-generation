//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define EMPTY 0
#define WIN_CONDITION_HORIZONTAL 0
#define WIN_CONDITION_VERTICAL 1
#define WIN_CONDITION_DIAGONAL 2

int board[BOARD_SIZE][BOARD_SIZE];
int current_player = PLAYER_ONE;
int win_condition = 0;

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win_condition() {
    int win_row, win_col;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) {
            win_condition = WIN_CONDITION_HORIZONTAL;
            win_row = i;
            return 1;
        }
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == current_player && board[1][j] == current_player && board[2][j] == current_player) {
            win_condition = WIN_CONDITION_VERTICAL;
            win_col = j;
            return 1;
        }
    }
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) {
        win_condition = WIN_CONDITION_DIAGONAL;
        return 1;
    }
    if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player) {
        win_condition = WIN_CONDITION_DIAGONAL;
        return 1;
    }
    return 0;
}

int check_valid_move(int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
        return 1;
    }
    return 0;
}

int main() {
    initialize_board();
    print_board();
    int player_one_move, player_two_move;
    while (1) {
        printf("Player %d's turn:\n", current_player);
        scanf("%d", &player_one_move);
        if (!check_valid_move(player_one_move / 3, player_one_move % 3)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[player_one_move / 3][player_one_move % 3] = current_player;
        print_board();
        if (check_win_condition()) {
            printf("Player %d wins!\n", current_player);
            break;
        }
        current_player =!current_player;
    }
    return 0;
}