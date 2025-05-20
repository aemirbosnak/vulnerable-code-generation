//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
/*
 * The following program is a game of Tic-Tac-Toe.
 * It allows two players to take turns placing pieces on a 3x3 grid.
 * The first player to get three pieces in a row, column, or diagonal, wins.
 * The game ends in a tie if no player wins before the grid is filled up.
 *
 * Author: Donald Knuth
 * Date: 2021-10-15
 */

#include <stdio.h>

#define ROWS 3
#define COLS 3

enum Piece { EMPTY = 0, PLAYER_ONE = 1, PLAYER_TWO = 2 };

typedef enum {
    OK,
    DRAW,
    PLAYER_ONE_WON,
    PLAYER_TWO_WON,
    INVALID_MOVE,
} Outcome;

typedef struct {
    enum Piece grid[ROWS][COLS];
    int num_moves;
} Board;

typedef struct {
    int row;
    int col;
} Move;

/**
 * Initialize the game board.
 */
void initialize_board(Board *board) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board->grid[row][col] = EMPTY;
        }
    }
    board->num_moves = 0;
}

/**
 * Print the game board.
 */
void print_board(const Board *board) {
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            switch (board->grid[row][col]) {
                case EMPTY:
                    printf("| ");
                    break;
                case PLAYER_ONE:
                    printf("|X");
                    break;
                case PLAYER_TWO:
                    printf("|O");
                    break;
                default:
                    printf("|?");
                    break;
            }
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * Get the piece at a specified board position.
 */
enum Piece get_piece(const Board *board, int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return INVALID_MOVE;
    }
    return board->grid[row][col];
}

/**
 * Place a player's piece on the board at a specified position.
 */
Outcome make_move(Board *board, Move move, enum Piece player) {
    if (get_piece(board, move.row, move.col) != EMPTY) {
        return INVALID_MOVE;
    }
    board->grid[move.row][move.col] = player;
    board->num_moves++;

    // Check if the player has won.
    int row_count = 0;
    int col_count = 0;
    int diag_count1 = 0;
    int diag_count2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board->grid[move.row][i] == player) {
            row_count++;
        }
        if (board->grid[i][move.col] == player) {
            col_count++;
        }
        if (board->grid[i][i] == player) {
            diag_count1++;
        }
        if (board->grid[i][ROWS - i - 1] == player) {
            diag_count2++;
        }
    }
    if (row_count == 3 || col_count == 3 || diag_count1 == 3 || diag_count2 == 3) {
        if (player == PLAYER_ONE) {
            return PLAYER_ONE_WON;
        } else {
            return PLAYER_TWO_WON;
        }
    }

    // Check if the game is a draw.
    if (board->num_moves == ROWS * COLS) {
        return DRAW;
    }

    return OK;
}

/**
 * Get the next move from the player.
 */
Move get_move_from_player(const Board *board, enum Piece player) {
    Move move;
    printf("Player %d's turn: ", player);
    scanf("%d %d", &move.row, &move.col);
    return move;
}

int main() {
    Board board;
    initialize_board(&board);
    Outcome outcome = OK;

    while (outcome == OK) {
        print_board(&board);
        Move move = get_move_from_player(&board, board.num_moves % 2 == 0 ? PLAYER_ONE : PLAYER_TWO);
        outcome = make_move(&board, move, board.num_moves % 2 == 0 ? PLAYER_ONE : PLAYER_TWO);
    }

    print_board(&board);

    switch (outcome) {
        case DRAW:
            printf("Game ended in a draw.\n");
            break;
        case PLAYER_ONE_WON:
            printf("Player 1 (X) has won the game!\n");
            break;
        case PLAYER_TWO_WON:
            printf("Player 2 (O) has won the game!\n");
            break;
        case INVALID_MOVE:
            printf("Invalid move. Game over.\n");
            break;
        default:
            printf("Unknown outcome. Game over.\n");
            break;
    }

    return 0;
}