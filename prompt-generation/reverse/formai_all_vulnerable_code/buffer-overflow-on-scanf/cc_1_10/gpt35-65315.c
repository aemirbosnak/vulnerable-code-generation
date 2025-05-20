//FormAI DATASET v1.0 Category: Chess engine ; Style: scalable
// C Chess engine example program

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum Piece {
    EMPTY,
    WP, BP,
    WN, BN,
    WB, BB,
    WR, BR,
    WQ, BQ,
    WK, BK
};

enum Color {
    WHITE,
    BLACK
};

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    enum Piece piece;
    enum Color color;
} Square;

typedef Square Board[BOARD_SIZE][BOARD_SIZE];

void init_board(Board board) {
    board[0][0] = (Square){ WR, WHITE };
    board[0][1] = (Square){ WN, WHITE };
    board[0][2] = (Square){ WB, WHITE };
    board[0][3] = (Square){ WQ, WHITE };
    board[0][4] = (Square){ WK, WHITE };
    board[0][5] = (Square){ WB, WHITE };
    board[0][6] = (Square){ WN, WHITE };
    board[0][7] = (Square){ WR, WHITE };

    for (int x = 0; x < BOARD_SIZE; x++) {
        board[1][x] = (Square){ WP, WHITE };
    }

    for (int y = 2; y < 6; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = (Square){ EMPTY, WHITE };
        }
    }

    for (int x = 0; x < BOARD_SIZE; x++) {
        board[6][x] = (Square){ BP, BLACK };
    }

    board[7][0] = (Square){ BR, BLACK };
    board[7][1] = (Square){ BN, BLACK };
    board[7][2] = (Square){ BB, BLACK };
    board[7][3] = (Square){ BQ, BLACK };
    board[7][4] = (Square){ BK, BLACK };
    board[7][5] = (Square){ BB, BLACK };
    board[7][6] = (Square){ BN, BLACK };
    board[7][7] = (Square){ BR, BLACK };
}

void print_board(Board board) {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        printf("%d ", y + 1);
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch (board[y][x].piece) {
                case WP:
                    printf("P ");
                    break;
                case BP:
                    printf("p ");
                    break;
                case WN:
                    printf("N ");
                    break;
                case BN:
                    printf("n ");
                    break;
                case WB:
                    printf("B ");
                    break;
                case BB:
                    printf("b ");
                    break;
                case WR:
                    printf("R ");
                    break;
                case BR:
                    printf("r ");
                    break;
                case WQ:
                    printf("Q ");
                    break;
                case BQ:
                    printf("q ");
                    break;
                case WK:
                    printf("K ");
                    break;
                case BK:
                    printf("k ");
                    break;
                default:
                    printf(". ");
                    break;
            }
        }
        printf("\n");
    }

    printf("  ");
    for (int x = 0; x < BOARD_SIZE; x++) {
        printf("%c ", 'a' + x);
    }
    printf("\n");
}

Coord coord_from_string(char* str) {
    Coord coord = { str[0] - 'a', str[1] - '1' };
    return coord;
}

int is_valid_coord(Coord coord) {
    return (coord.x >= 0 && coord.x < BOARD_SIZE && coord.y >= 0 && coord.y < BOARD_SIZE);
}

Square* get_square(Board board, Coord coord) {
    if (is_valid_coord(coord)) {
        return &(board[coord.y][coord.x]);
    } else {
        return NULL;
    }
}

int is_valid_move(Board board, Coord from, Coord to) {
    Square* from_square = get_square(board, from);
    Square* to_square = get_square(board, to);
    if (from_square == NULL || to_square == NULL || from.x == to.x && from.y == to.y) {
        return 0;
    }
    // TODO: Implement move validation
    return 1;
}

void make_move(Board board, Coord from, Coord to) {
    Square* from_square = get_square(board, from);
    Square* to_square = get_square(board, to);
    if (from_square == NULL || to_square == NULL || from.x == to.x && from.y == to.y) {
        return;
    }
    *to_square = *from_square;
    *from_square = (Square){ EMPTY, WHITE };
}

int main(void) {
    Board board;
    init_board(board);
    print_board(board);

    char from_str[3], to_str[3];
    printf("Enter move (e.g. e2 e4): ");
    scanf("%s %s", from_str, to_str);

    Coord from = coord_from_string(from_str);
    Coord to = coord_from_string(to_str);

    if (is_valid_move(board, from, to)) {
        make_move(board, from, to);
    } else {
        printf("Invalid move.\n");
    }

    print_board(board);

    return 0;
}