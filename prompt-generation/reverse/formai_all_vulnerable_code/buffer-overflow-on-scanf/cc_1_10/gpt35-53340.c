//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // the checkers board
enum Piece {EMPTY, RED_PAWN, RED_KING, WHITE_PAWN, WHITE_KING};

// initialize the board with EMPTY and pieces at starting positions
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) { // this is where the pieces are placed
                if (i < 3) {
                    board[i][j] = WHITE_PAWN;
                } else if (i > 4) {
                    board[i][j] = RED_PAWN;
                }
            }
        }
    }
}

// print out the current state of the board
void print_board() {
    printf("  0 1 2 3 4 5 6 7\n"); // column numbers
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // row number
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case RED_PAWN:
                    printf("r ");
                    break;
                case RED_KING:
                    printf("R ");
                    break;
                case WHITE_PAWN:
                    printf("w ");
                    break;
                case WHITE_KING:
                    printf("W ");
                    break;
            }
        }
        printf("%d\n", i); // row number
    }
    printf("  0 1 2 3 4 5 6 7\n"); // column numbers
}

// check if the move from to to is legal for the current player
bool is_legal_move(int from_row, int from_col, int to_row, int to_col, enum Piece player_piece) {
    if (from_row < 0 || from_row >= BOARD_SIZE || to_row < 0 || to_row >= BOARD_SIZE
        || from_col < 0 || from_col >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return false; // out of bounds
    }

    if (board[to_row][to_col] != EMPTY) {
        return false; // can't move to a non-empty space
    }

    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    if (player_piece == RED_PAWN && row_diff < 0) {
        return false; // red can only move down
    }
    if (player_piece == WHITE_PAWN && row_diff > 0) {
        return false; // white can only move up
    }
    if (player_piece == RED_KING || player_piece == WHITE_KING) {
        if (abs(row_diff) != abs(col_diff)) {
            return false; // not a diagonal move
        }
    } else {
        if (abs(row_diff) != abs(col_diff) || abs(row_diff) != 1) {
            return false; // not a valid pawn move
        }
    }

    return true;
}

// make the move from (from_row, from_col) to (to_row, to_col)
void make_move(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;
}

int main() {
    init_board();
    print_board();

    int current_player = 1; // red goes first
    bool game_over = false;

    while (!game_over) {
        printf("Current player: %s\n", current_player == 1 ? "Red" : "White");

        int from_row, from_col, to_row, to_col;
        printf("Enter move (from row, from col, to row, to col): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        if (is_legal_move(from_row, from_col, to_row, to_col, current_player == 1 ? RED_PAWN : WHITE_PAWN)) {
            make_move(from_row, from_col, to_row, to_col);
            print_board();
            current_player = -(current_player); // switch players
        } else {
            printf("Illegal move!\n");
        }
    }

    return 0;
}