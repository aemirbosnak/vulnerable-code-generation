//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'
#define WHITE_KING 'K'
#define BLACK_KING 'k'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initialize_board(ChessBoard* chess) {
    const char* initial_setup[BOARD_SIZE] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "        ",
        "        ",
        "        ",
        "        ",
        "pppppppp",
        "rnbqkbnr"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(chess->board[i], initial_setup[i]);
    }
}

void print_board(const ChessBoard* chess) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chess->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(const ChessBoard* chess, int x1, int y1, int x2, int y2) {
    // Basic bounds checking
    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    char piece = chess->board[x1][y1];
    char target = chess->board[x2][y2];
    
    // Simplistic rules: you can't capture your own pieces
    if ((piece >= 'A' && piece <= 'Z' && target >= 'A' && target <= 'Z') || 
        (piece >= 'a' && piece <= 'z' && target >= 'a' && target <= 'z')) {
        return 0;
    }
    return 1;
}

void move_piece(ChessBoard* chess, int x1, int y1, int x2, int y2) {
    if (is_valid_move(chess, x1, y1, x2, y2)) {
        chess->board[x2][y2] = chess->board[x1][y1];
        chess->board[x1][y1] = EMPTY;
    } else {
        printf("Invalid move!\n");
    }
}

void play_game() {
    ChessBoard chess;
    initialize_board(&chess);
    
    int x1, y1, x2, y2;
    char col_start, col_end;
    while (1) {
        print_board(&chess);
        printf("Enter move (e.g. e2 e4) or q to quit: ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == 'q') break;

        if (sscanf(input, "%c%d %c%d", &col_start, &y1, &col_end, &y2) != 4) {
            printf("Invalid input format.\n");
            continue;
        }
        
        // Convert coordinates to indices
        x1 = BOARD_SIZE - y1;
        x2 = BOARD_SIZE - y2;
        y1 = col_start - 'a';
        y2 = col_end - 'a';

        move_piece(&chess, x1, y1, x2, y2);
    }
}

int main() {
    play_game();
    return 0;
}