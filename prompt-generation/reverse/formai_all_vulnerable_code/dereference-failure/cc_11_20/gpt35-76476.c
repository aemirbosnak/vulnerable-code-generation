//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>

// DEFINING THE CONSTANTS

#define BOARD_SIZE 8

// DEFINING THE STRUCTURES

typedef enum {
    NO_PIECE,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} Pieces;

typedef enum {
    WHITE,
    BLACK
} Colors;

typedef struct {
    Pieces piece;
    Colors color;
} PieceColor;

typedef struct {
    PieceColor piece_color;
    int row;
    int col;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Board;

// DEFINING THE FUNCTIONS

Board *initial_board() {
    Board *new_board = malloc(sizeof(Board));
    int row, col;

    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            if(row == 0) {
                switch(col) {
                    case 0:
                        new_board->board[row][col].piece_color =
                            (PieceColor){ROOK, WHITE};
                        break;
                    case 1:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KNIGHT, WHITE};
                        break;
                    case 2:
                        new_board->board[row][col].piece_color =
                            (PieceColor){BISHOP, WHITE};
                        break;
                    case 3:
                        new_board->board[row][col].piece_color =
                            (PieceColor){QUEEN, WHITE};
                        break;
                    case 4:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KING, WHITE};
                        break;
                    case 5:
                        new_board->board[row][col].piece_color =
                            (PieceColor){BISHOP, WHITE};
                        break;
                    case 6:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KNIGHT, WHITE};
                        break;
                    case 7:
                        new_board->board[row][col].piece_color =
                            (PieceColor){ROOK, WHITE};
                        break;
                }
            } else if(row == 1) {
                new_board->board[row][col].piece_color =
                    (PieceColor){PAWN, WHITE};
            } else if(row == BOARD_SIZE - 2) {
                new_board->board[row][col].piece_color =
                    (PieceColor){PAWN, BLACK};
            } else if(row == BOARD_SIZE - 1) {
                switch(col) {
                    case 0:
                        new_board->board[row][col].piece_color =
                            (PieceColor){ROOK, BLACK};
                        break;
                    case 1:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KNIGHT, BLACK};
                        break;
                    case 2:
                        new_board->board[row][col].piece_color =
                            (PieceColor){BISHOP, BLACK};
                        break;
                    case 3:
                        new_board->board[row][col].piece_color =
                            (PieceColor){QUEEN, BLACK};
                        break;
                    case 4:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KING, BLACK};
                        break;
                    case 5:
                        new_board->board[row][col].piece_color =
                            (PieceColor){BISHOP, BLACK};
                        break;
                    case 6:
                        new_board->board[row][col].piece_color =
                            (PieceColor){KNIGHT, BLACK};
                        break;
                    case 7:
                        new_board->board[row][col].piece_color =
                            (PieceColor){ROOK, BLACK};
                        break;
                }
            } else {
                new_board->board[row][col].piece_color =
                    (PieceColor){NO_PIECE, WHITE};
            }

            new_board->board[row][col].row = row;
            new_board->board[row][col].col = col;
        }
    }

    return new_board;
}

void free_board(Board *board) {
    free(board);
}

void print_board(Board *board) {
    int row, col;

    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            switch(board->board[row][col].piece_color.piece) {
                case NO_PIECE:
                    printf("+ ");
                    break;
                case PAWN:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("P ");
                    } else {
                        printf("p ");
                    }
                    break;
                case KNIGHT:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("N ");
                    } else {
                        printf("n ");
                    }
                    break;
                case BISHOP:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("B ");
                    } else {
                        printf("b ");
                    }
                    break;
                case ROOK:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("R ");
                    } else {
                        printf("r ");
                    }
                    break;
                case QUEEN:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("Q ");
                    } else {
                        printf("q ");
                    }
                    break;
                case KING:
                    if(board->board[row][col].piece_color.color == WHITE) {
                        printf("K ");
                    } else {
                        printf("k ");
                    }
                    break;
            }
        }
        printf("\n");
    }
}

bool is_valid_location(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

bool is_move_obstructed(Board *board, int from_row, int from_col,
                        int to_row, int to_col) {
    int row, col;
    int delta_x = to_col - from_col;
    int delta_y = to_row - from_row;
    int x_dir = delta_x > 0 ? 1 : delta_x < 0 ? -1 : 0;
    int y_dir = delta_y > 0 ? 1 : delta_y < 0 ? -1 : 0;

    // Check horizontal and vertical moves
    if(delta_x != 0 && delta_y != 0 && abs(delta_x) != abs(delta_y)) {
        return true;
    } else if(delta_x == 0) { // Vertical move
        for(row = from_row + y_dir; row != to_row; row += y_dir) {
            if(board->board[row][from_col].piece_color.piece != NO_PIECE) {
                return true;
            }
        }
    } else if(delta_y == 0) { // Horizontal move
        for(col = from_col + x_dir; col != to_col; col += x_dir) {
            if(board->board[from_row][col].piece_color.piece != NO_PIECE) {
                return true;
            }
        }
    } else { // Diagonal move
        for(row = from_row + y_dir, col = from_col + x_dir;
            row != to_row;
            row += y_dir, col += x_dir) {
            if(board->board[row][col].piece_color.piece != NO_PIECE) {
                return true;
            }
        }
    }

    return false;
}

bool is_move_valid(Board *board, int from_row, int from_col,
                   int to_row, int to_col) {
    PieceColor from_piece = board->board[from_row][from_col].piece_color;
    PieceColor to_piece = board->board[to_row][to_col].piece_color;
    int row_delta = to_row - from_row;
    int col_delta = to_col - from_col;
    int abs_row_delta = abs(row_delta);
    int abs_col_delta = abs(col_delta);

    if(from_row == to_row && from_col == to_col) {
        return false;
    }

    switch(from_piece.piece) {
        case NO_PIECE: // No piece selected
            return false;
            break;
        case PAWN: // Pawn selected
            if(from_piece.color == WHITE) {
                // Moving forward
                if(row_delta < 0) {
                    return false;
                }

                // Capturing piece diagonally
                if(abs_col_delta == 1 && row_delta == 1) {
                    if(to_piece.color == from_piece.color || to_piece.piece == NO_PIECE) {
                        return false;
                    }

                    return true;
                }

                // Moving forward one or two spaces
                if(col_delta != 0 || abs_row_delta > 2) {
                    return false;
                }

                // Check obstructed moves
                if(to_piece.piece == NO_PIECE) {
                    if(abs_row_delta == 1) {
                        return true;
                    } else if(abs_row_delta == 2 && from_row == 1) {
                        return !is_move_obstructed(board, from_row, from_col, to_row, to_col);
                    } else {
                        return false;
                    }
                }
            } else { // Black pawn
                // Moving forward
                if(row_delta > 0) {
                    return false;
                }

                // Capturing piece diagonally
                if(abs_col_delta == 1 && row_delta == -1) {
                    if(to_piece.color == from_piece.color || to_piece.piece == NO_PIECE) {
                        return false;
                    }

                    return true;
                }

                // Moving forward one or two spaces
                if(col_delta != 0 || abs_row_delta > 2) {
                    return false;
                }

                // Check obstructed moves
                if(to_piece.piece == NO_PIECE) {
                    if(abs_row_delta == 1) {
                        return true;
                    } else if(abs_row_delta == 2 && from_row == 6) {
                        return !is_move_obstructed(board, from_row, from_col, to_row, to_col);
                    } else {
                        return false;
                    }
                }
            }
            break;
        case KNIGHT: // Knight selected
            if(row_delta == 0 || col_delta == 0 || abs_row_delta + abs_col_delta != 3) {
                return false;
            }

            if(to_piece.color == from_piece.color) {
                return false;
            }

            return true;
            break;
        case BISHOP: // Bishop selected
            if(abs_row_delta != abs_col_delta) {
                return false;
            }

            if(to_piece.color == from_piece.color) {
                return false;
            }

            return !is_move_obstructed(board, from_row, from_col, to_row, to_col);
            break;
        case ROOK: // Rook selected
            if(row_delta != 0 && col_delta != 0) {
                return false;
            }

            if(to_piece.color == from_piece.color) {
                return false;
            }

            return !is_move_obstructed(board, from_row, from_col, to_row, to_col);
            break;
        case QUEEN: // Queen selected
            if(abs_row_delta != abs_col_delta && row_delta != 0 && col_delta != 0) {
                return false;
            }

            if(to_piece.color == from_piece.color) {
                return false;
            }

            return !is_move_obstructed(board, from_row, from_col, to_row, to_col);
            break;
        case KING: // King selected
            if((abs_row_delta > 1 || abs_col_delta > 1) &&
               !(abs_row_delta == 0 && abs_col_delta == 2) &&
               !(abs_row_delta == 2 && abs_col_delta == 0)) {
                return false;
            }

            if(to_piece.color == from_piece.color) {
                return false;
            }

            return true;
            break;
    }

    return false;
}

bool is_check(Board *board, Colors color) {
    int row, col;
    PieceColor king_color = (PieceColor){KING, color};
    int king_row = -1, king_col = -1;

    // Find king's location
    for(row = 0; row < BOARD_SIZE && king_row == -1; row++) {
        for(col = 0; col < BOARD_SIZE && king_col == -1; col++) {
            if(board->board[row][col].piece_color.piece == KING &&
               board->board[row][col].piece_color.color == color) {
                king_row = row;
                king_col = col;
            }
        }
    }

    // Check for threat from opposite team
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            if(board->board[row][col].piece_color.color != color &&
               is_move_valid(board, row, col, king_row, king_col)) {
                return true;
            }
        }
    }

    return false;
}

bool is_checkmate(Board *board, Colors color) {
    int row, col, to_row, to_col;
    Board *temp_board = NULL;
    bool valid_move_found = false;

    for(row = 0; row < BOARD_SIZE && !valid_move_found; row++) {
        for(col = 0; col < BOARD_SIZE && !valid_move_found; col++) {
            if(board->board[row][col].piece_color.color == color) {
                for(to_row = 0; to_row < BOARD_SIZE && !valid_move_found; to_row++) {
                    for(to_col = 0; to_col < BOARD_SIZE && !valid_move_found; to_col++) {
                        if(is_move_valid(board, row, col, to_row, to_col)) {
                            temp_board = malloc(sizeof(Board));
                            memcpy(temp_board, board, sizeof(Board));
                            temp_board->board[to_row][to_col].piece_color = 
                                temp_board->board[row][col].piece_color;
                            temp_board->board[row][col].piece_color = 
                                (PieceColor){NO_PIECE, WHITE};

                            if(!is_check(temp_board, color)) {
                                valid_move_found = true;
                            }

                            free_board(temp_board);
                        }
                    }
                }
            }
        }
    }

    return !valid_move_found;
}

// MAIN FUNCTION

int main() {
    Board *board = initial_board();
    Colors turn = WHITE;
    char move[5];

    while(!is_checkmate(board, turn)) {
        print_board(board);
        printf("%s turn. Enter move (example: e2e4): ", turn == WHITE ? "White" : "Black");
        scanf("%s", move);

        int from_row = move[1] - '1';
        int from_col = move[0] - 'a';
        int to_row = move[3] - '1';
        int to_col = move[2] - 'a';

        if(is_valid_location(from_row, from_col) &&
           is_valid_location(to_row, to_col) &&
           board->board[from_row][from_col].piece_color.color == turn &&
           is_move_valid(board, from_row, from_col, to_row, to_col)) {
            board->board[to_row][to_col].piece_color =
                board->board[from_row][from_col].piece_color;
            board->board[from_row][from_col].piece_color = (PieceColor){NO_PIECE, WHITE};
            turn = (turn == WHITE ? BLACK : WHITE);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    print_board(board);
    printf("Checkmate! %s wins.\n", turn == WHITE ? "Black" : "White");
    free_board(board);

    return 0;
}