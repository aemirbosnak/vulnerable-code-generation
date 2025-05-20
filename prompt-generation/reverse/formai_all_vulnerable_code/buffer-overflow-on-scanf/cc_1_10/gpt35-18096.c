//FormAI DATASET v1.0 Category: Chess engine ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Surrealist Chess Engine
// This program plays chess with a surrealist twist.
// The pieces don't behave as they normally would!

// Declare constants for the board dimensions.
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

// Declare static arrays to store the current state of the board and the positions of the pieces.
static int chess_board[BOARD_HEIGHT][BOARD_WIDTH] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 2, 2, 2, 2, 2, 1},
    {0, 1, 2, 3, 3, 3, 2, 1},
    {0, 1, 2, 3, 4, 3, 2, 1},
    {0, 1, 2, 3, 3, 3, 2, 1},
    {0, 1, 2, 2, 2, 2, 2, 1},
    {0, 1, 1, 1, 1, 1, 1, 1}
};

// Declare a structure to represent a chess piece.
typedef struct ChessPiece {
    int x;
    int y;
} ChessPiece;

// Declare function prototypes.
void run_game();
void draw_board();
bool is_move_valid(int from_x, int from_y, int to_x, int to_y, int player_piece);
bool make_move(int from_x, int from_y, int to_x, int to_y, int player_piece);
bool is_piece(char piece);

// Main function - runs the game.
int main(int argc, char **argv) {
    run_game();
    return 0;
}

// Runs the game loop.
void run_game() {
    int turn = 1;
    while (true) {
        draw_board();
        printf("\n\nPlayer %d's turn.\n", turn);
        printf("Enter move in the format 'ax,by': ");
        int from_x, from_y, to_x, to_y;
        char comma;
        scanf("%d%c%d%c", &from_x, &comma, &from_y, &comma);
        scanf("%d%c%d%c", &to_x, &comma, &to_y, &comma);
        if (is_move_valid(from_x, from_y, to_x, to_y, turn)) {
            make_move(from_x, from_y, to_x, to_y, turn);
            turn = turn == 1 ? 2 : 1;
        }
        else {
            printf("Invalid move!\n");
        }
    }
}

// Draws the current state of the board to the terminal.
void draw_board() {
    printf("\n   a b c d e f g h \n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        printf("%d| ", i + 1);
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (chess_board[i][j] == 0) {
                printf("  ");
            }
            else if (chess_board[i][j] == 1) {
                printf("P ");
            }
            else if (chess_board[i][j] == 2) {
                printf("@ ");
            }
            else if (chess_board[i][j] == 3) {
                printf("# ");
            }
            else if (chess_board[i][j] == 4) {
                printf("& ");
            }
        }
        printf("|%d\n", i + 1);
    }
    printf("  -----------------\n");
    printf("   a b c d e f g h \n");
}

// Checks whether a move is valid.
bool is_move_valid(int from_x, int from_y, int to_x, int to_y, int player_piece) {
    if (from_x < 0 || from_x >= BOARD_WIDTH || from_y < 0 || from_y >= BOARD_HEIGHT ||
        to_x < 0 || to_x >= BOARD_WIDTH || to_y < 0 || to_y >= BOARD_HEIGHT) {
        return false;
    }
    if (!is_piece(chess_board[from_y][from_x])) {
        return false;
    }
    if (chess_board[to_y][to_x] == player_piece) {
        return false;
    }
    if (abs(to_x - from_x) > 1 || abs(to_y - from_y) > 1) {
        return false;
    }
    return true;
}

// Makes a move on the board.
bool make_move(int from_x, int from_y, int to_x, int to_y, int player_piece) {
    if (!is_move_valid(from_x, from_y, to_x, to_y, player_piece)) {
        return false;
    }
    chess_board[from_y][from_x] = 0;
    chess_board[to_y][to_x] = player_piece;
    return true;
}

// Determines whether a given integer represents a piece on the board.
bool is_piece(char piece) {
    return piece == 1 || piece == 2 || piece == 3 || piece == 4;
}