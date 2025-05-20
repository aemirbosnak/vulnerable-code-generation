//FormAI DATASET v1.0 Category: Chess AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum { WHITE, BLACK } Color;
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

typedef struct {
    Piece piece;
    Color color;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    // Setup white pieces
    board[0][0] = (Square) { ROOK, WHITE };
    board[0][1] = (Square) { KNIGHT, WHITE };
    board[0][2] = (Square) { BISHOP, WHITE };
    board[0][3] = (Square) { QUEEN, WHITE };
    board[0][4] = (Square) { KING, WHITE };
    board[0][5] = (Square) { BISHOP, WHITE };
    board[0][6] = (Square) { KNIGHT, WHITE };
    board[0][7] = (Square) { ROOK, WHITE };

    for (int i = 0; i < 8; i++) {
        board[1][i] = (Square) { PAWN, WHITE };
    }

    // Setup black pieces
    board[7][0] = (Square) { ROOK, BLACK };
    board[7][1] = (Square) { KNIGHT, BLACK };
    board[7][2] = (Square) { BISHOP, BLACK };
    board[7][3] = (Square) { QUEEN, BLACK };
    board[7][4] = (Square) { KING, BLACK };
    board[7][5] = (Square) { BISHOP, BLACK };
    board[7][6] = (Square) { KNIGHT, BLACK };
    board[7][7] = (Square) { ROOK, BLACK };

    for (int i = 0; i < 8; i++) {
        board[6][i] = (Square) { PAWN, BLACK };
    }

    // Set empty squares
    for (int i = 2; i <= 5; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = (Square) { '\0', '\0' };
        }
    }
}

void print_board() {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            Square square = board[i][j];
            if (square.piece != '\0') {
                printf("%c", square.piece);
                if (square.color == WHITE) {
                    printf("w");
                } else {
                    printf("b");
                }
            } else {
                printf(".");
            }
            printf(" ");
        }
        printf("%d", i + 1);
        printf("\n");
    }
    printf("   A B C D E F G H\n");
}

bool is_valid_piece(int row, int col, Color color) {
    Square square = board[row][col];
    if (square.color != color) {
        return false;
    }
    if (square.piece == KING) {
        return true;
    }
    return true;
}

int main() {
    printf("Welcome to Chess AI\n");

    initialize_board();
    print_board();

    int row, col;

    while (true) {
        printf("Enter coordinates for piece you want to move (row col): ");
        scanf("%d %d", &row, &col);

        if (!is_valid_piece(row, col, WHITE)) {
            printf("Invalid piece!\n");
            continue;
        }

        char move[5];
        printf("Enter move (ex. a2a3): ");
        scanf("%s", move);

        int start_row = row;
        int start_col = col;
        int end_row = move[1] - '1';
        int end_col = move[0] - 'a';

        Square start_square = board[start_row][start_col];
        if (start_square.piece == PAWN) {
            // TODO: Implement pawn movement
            printf("Pawn movement not yet implemented!\n");
        } else {
            // TODO: Implement other pieces' movement
            printf("%c movement not yet implemented!\n", start_square.piece);
        }

        // Swap positions
        Square temp = board[end_row][end_col];
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = temp;

        print_board();
    }

    return 0;
}