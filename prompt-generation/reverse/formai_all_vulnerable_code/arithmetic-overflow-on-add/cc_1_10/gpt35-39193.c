//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define PLAYER_ONE 1
#define PLAYER_TWO 2

void initialize_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
int is_valid_move(int board[][BOARD_SIZE], int player, int row, int col, int new_row, int new_col);
int move_piece(int board[][BOARD_SIZE], int player, int row, int col, int new_row, int new_col);
void play_game(int board[][BOARD_SIZE]);

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    play_game(board);
    return 0;
}

void initialize_board(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = PLAYER_ONE;
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = PLAYER_TWO;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(int board[][BOARD_SIZE], int player, int row, int col, int new_row, int new_col) {
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0;
    }
    if (board[new_row][new_col] != 0) {
        return 0;
    }
    if (player == PLAYER_ONE) {
        if (new_row >= row) {
            return 0;
        }
        if (new_row == row - 1 && (new_col == col - 1 || new_col == col + 1)) {
            return 1;
        }
        if (new_row == row - 2 && (new_col == col - 2 || new_col == col + 2)) {
            if (board[row-1][(new_col+col)/2] == PLAYER_TWO) {
                return 1;
            }
        }
    } else {
        if (new_row <= row) {
            return 0;
        }
        if (new_row == row + 1 && (new_col == col - 1 || new_col == col + 1)) {
            return 1;
        }
        if (new_row == row + 2 && (new_col == col - 2 || new_col == col + 2)) {
            if (board[row+1][(new_col+col)/2] == PLAYER_ONE) {
                return 1;
            }
        }
    }
    return 0;
}

int move_piece(int board[][BOARD_SIZE], int player, int row, int col, int new_row, int new_col) {
    int i, j;
    if (is_valid_move(board, player, row, col, new_row, new_col)) {
        board[new_row][new_col] = player;
        board[row][col] = 0;
        if (new_row == 0 || new_row == BOARD_SIZE - 1) {
            board[new_row][new_col] = player + 2;
        }
        if (new_row == row + 2 || new_row == row - 2) {
            i = (row + new_row) / 2;
            j = (col + new_col) / 2;
            board[i][j] = 0;
        }
        return 1;
    }
    return 0;
}

void play_game(int board[][BOARD_SIZE]) {
    int player = PLAYER_ONE;
    int row, col, new_row, new_col;
    while (1) {
        print_board(board);
        printf("Player %d, enter row and column of piece you want to move: ", player);
        scanf("%d %d", &row, &col);
        printf("Enter row and column of new position: ");
        scanf("%d %d", &new_row, &new_col);
        if (move_piece(board, player, row, col, new_row, new_col)) {
            if (player == PLAYER_ONE) {
                player = PLAYER_TWO;
            } else {
                player = PLAYER_ONE;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
        if (player == PLAYER_ONE) {
            printf("Player One's turn.\n");
        } else {
            printf("Player Two's turn.\n");
        }
    }
}