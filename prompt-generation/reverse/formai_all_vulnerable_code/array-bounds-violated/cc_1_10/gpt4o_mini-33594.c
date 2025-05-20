//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Piece;
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } PieceType;

typedef struct {
    Piece piece;
    PieceType type;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        for (int file = 0; file < BOARD_SIZE; file++) {
            board[rank][file].piece = EMPTY;
            board[rank][file].type = PAWN; // Dummy type, will not matter for empty squares
        }
    }
    // Place pawns
    for (int file = 0; file < BOARD_SIZE; file++) {
        board[1][file].piece = WHITE;
        board[1][file].type = PAWN;
        board[6][file].piece = BLACK;
        board[6][file].type = PAWN;
    }
    // Place other pieces
    Piece colors[2] = { WHITE, BLACK };
    PieceType pieces[] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    for (int colorIndex = 0; colorIndex < 2; colorIndex++) {
        Piece color = colors[colorIndex];
        int rank = (color == WHITE) ? 0 : 7;
        for (int file = 0; file < BOARD_SIZE; file++) {
            board[rank][file].piece = color;
            board[rank][file].type = pieces[file];
        }
    }
}

void print_board() {
    printf("   a b c d e f g h\n");
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        printf("%d ", BOARD_SIZE - rank);
        for (int file = 0; file < BOARD_SIZE; file++) {
            if (board[rank][file].piece == WHITE) {
                printf("W ");
            } else if (board[rank][file].piece == BLACK) {
                printf("B ");
            } else {
                printf(". ");
            }
        }
        printf("%d\n", BOARD_SIZE - rank);
    }
    printf("   a b c d e f g h\n");
}

int is_valid_move(int from_rank, int from_file, int to_rank, int to_file) {
    // Simple validation, excluding checks for actual chess rules
    if (to_rank < 0 || to_rank >= BOARD_SIZE || to_file < 0 || to_file >= BOARD_SIZE)
        return 0;
    if (board[from_rank][from_file].piece == EMPTY)
        return 0;
    if (board[to_rank][to_file].piece == board[from_rank][from_file].piece)
        return 0;
    
    return 1;
}

void make_move(int from_rank, int from_file, int to_rank, int to_file) {
    if (is_valid_move(from_rank, from_file, to_rank, to_file)) {
        board[to_rank][to_file] = board[from_rank][from_file];
        board[from_rank][from_file].piece = EMPTY;
        printf("Move made from %c%d to %c%d.\n",
            'a' + from_file, BOARD_SIZE - from_rank,
            'a' + to_file, BOARD_SIZE - to_rank);
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    init_board();
    print_board();

    char command[6];
    while (1) {
        printf("Enter move (e.g., e2 to e4) or 'exit' to quit: ");
        fgets(command, sizeof(command), stdin);
        if (command[0] == 'e' && command[1] == 'x') break; // Exit command

        int from_file = command[0] - 'a';
        int from_rank = BOARD_SIZE - (command[1] - '0');
        int to_file = command[5] - 'a';
        int to_rank = BOARD_SIZE - (command[4] - '0');

        make_move(from_rank, from_file, to_rank, to_file);
        print_board();
    }

    printf("Thank you for playing!\n");
    return 0;
}