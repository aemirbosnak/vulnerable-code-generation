//FormAI DATASET v1.0 Category: Chess AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Coord;

typedef struct {
    int row, col;
} ChessMove;

int determine_winner(const char board[8][8]);
void move_piece(char board[8][8], ChessMove move);
void print_board(const char board[8][8]);
Coord get_piece_coordinates(const char board[8][8], char piece, bool player_is_white);
bool does_move_put_king_in_check(const char board[8][8], ChessMove move, bool player_is_white);
bool is_piece_on_path(const char board[8][8], Coord start, Coord end);
bool is_path_clear(const char board[8][8], Coord start, Coord end);

int main() {
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    bool player_is_white = true;
    char player_color[6];
    int game_status = -1;

    printf("Welcome to the chess game program!\n\n");
    printf("Enter the player color (white/black): ");
    scanf("%s", player_color);

    if (strcmp(player_color, "black") == 0) {
        player_is_white = false;
    }

    while (game_status == -1) {
        print_board(board);

        char piece_to_move = ' ';
        int row, col;
        ChessMove move;
        bool invalid_input = true;

        while (invalid_input) {
            printf("Enter the piece to move and its destination (ex. e2-e4): ");
            scanf("%c%d-%c%d", &col, &row, &move.col, &move.row);

            col = col - 'a';
            move.col = move.col - 'a';
            row = row - 1;
            move.row = move.row - 1;

            if (row >= 0 && row <= 7 && col >= 0 && col <= 7 && move.row >= 0 && move.row <= 7
            && move.col >= 0 && move.col <= 7) {
                Coord piece_coordinates = {row, col};
                if ((player_is_white && board[row][col] >= 'A' && board[row][col] <= 'Z')
                || (!player_is_white && board[row][col] >= 'a' && board[row][col] <= 'z')) {
                    move_piece(board, move);
                    invalid_input = false;
                }
            }
        }

        game_status = determine_winner(board);
        player_is_white = !player_is_white;
    }

    if (game_status == 1) {
        printf("White wins!\n");
    } else {
        printf("Black wins!\n");
    }

    return 0;
}

int determine_winner(const char board[8][8]) {
    const char *king_white = "K";
    const char *king_black = "k";
    bool white_king_alive = false;
    bool black_king_alive = false;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == *king_white) {
                white_king_alive = true;
            } else if (board[i][j] == *king_black) {
                black_king_alive = true;
            }
        }
    }

    if (!white_king_alive) {
        return 0;
    } else if (!black_king_alive) {
        return 1;
    }

    // No winner yet.
    return -1;
}

void move_piece(char board[8][8], ChessMove move) {
    char piece_to_move = board[move.row][move.col];
    board[move.row][move.col] = ' ';
    board[move.row][move.col] = piece_to_move;
}

void print_board(const char board[8][8]) {
    printf("\n  A B C D E F G H\n");
    printf(" -----------------\n");

    for (int row = 0; row < 8; row++) {
        printf("%d|", row + 1);
        for (int col = 0; col < 8; col++) {
            printf("%c|", board[row][col]);
        }
        printf("%d\n", row + 1);
    }

    printf(" -----------------\n");
    printf("  A B C D E F G H\n");
}

Coord get_piece_coordinates(const char board[8][8], char piece, bool player_is_white) {
    Coord result = {-1, -1};
    char king_white = 'K';
    char king_black = 'k';

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] == piece) {
                result.x = row;
                result.y = col;
                break;
            }
        }
    }

    return result;
}

bool does_move_put_king_in_check(const char board[8][8], ChessMove move, bool player_is_white) {
    char king_white = 'K';
    char king_black = 'k';
    Coord king_coordinates;

    if (player_is_white) {
        king_coordinates = get_piece_coordinates(board, king_white, player_is_white);
    } else {
        king_coordinates = get_piece_coordinates(board, king_black, player_is_white);
    }
    return false;
}

bool is_piece_on_path(const char board[8][8], Coord start, Coord end) {
    return false;
}

bool is_path_clear(const char board[8][8], Coord start, Coord end) {
    return false;
}