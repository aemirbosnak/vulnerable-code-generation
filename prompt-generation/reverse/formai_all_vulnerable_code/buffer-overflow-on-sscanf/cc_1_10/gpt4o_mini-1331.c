//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING } PieceType;
typedef enum { WHITE, BLACK } Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} ChessBoard;

void initialize_board(ChessBoard *chessboard) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            chessboard->board[i][j].type = EMPTY;
            chessboard->board[i][j].color = WHITE; // Default to WHITE, we can set this later
        }
    }

    // Set up Pawns
    for (int j = 0; j < SIZE; j++) {
        chessboard->board[1][j].type = PAWN;
        chessboard->board[1][j].color = WHITE;
        chessboard->board[6][j].type = PAWN;
        chessboard->board[6][j].color = BLACK;
    }

    // Set up Rooks
    chessboard->board[0][0].type = ROOK; chessboard->board[0][0].color = WHITE;
    chessboard->board[0][7].type = ROOK; chessboard->board[0][7].color = WHITE;
    chessboard->board[7][0].type = ROOK; chessboard->board[7][0].color = BLACK;
    chessboard->board[7][7].type = ROOK; chessboard->board[7][7].color = BLACK;

    // Set up Knights
    chessboard->board[0][1].type = KNIGHT; chessboard->board[0][1].color = WHITE;
    chessboard->board[0][6].type = KNIGHT; chessboard->board[0][6].color = WHITE;
    chessboard->board[7][1].type = KNIGHT; chessboard->board[7][1].color = BLACK;
    chessboard->board[7][6].type = KNIGHT; chessboard->board[7][6].color = BLACK;

    // Set up Bishops
    chessboard->board[0][2].type = BISHOP; chessboard->board[0][2].color = WHITE;
    chessboard->board[0][5].type = BISHOP; chessboard->board[0][5].color = WHITE;
    chessboard->board[7][2].type = BISHOP; chessboard->board[7][2].color = BLACK;
    chessboard->board[7][5].type = BISHOP; chessboard->board[7][5].color = BLACK;

    // Set up Queens and Kings
    chessboard->board[0][3].type = QUEEN; chessboard->board[0][3].color = WHITE;
    chessboard->board[0][4].type = KING; chessboard->board[0][4].color = WHITE;
    chessboard->board[7][3].type = QUEEN; chessboard->board[7][3].color = BLACK;
    chessboard->board[7][4].type = KING; chessboard->board[7][4].color = BLACK;
}

void print_board(const ChessBoard *chessboard) {
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            Piece piece = chessboard->board[i][j];
            char display_char;
            switch (piece.type) {
                case EMPTY:
                    display_char = '.';
                    break;
                case PAWN:
                    display_char = (piece.color == WHITE) ? 'P' : 'p';
                    break;
                case ROOK:
                    display_char = (piece.color == WHITE) ? 'R' : 'r';
                    break;
                case KNIGHT:
                    display_char = (piece.color == WHITE) ? 'N' : 'n';
                    break;
                case BISHOP:
                    display_char = (piece.color == WHITE) ? 'B' : 'b';
                    break;
                case QUEEN:
                    display_char = (piece.color == WHITE) ? 'Q' : 'q';
                    break;
                case KING:
                    display_char = (piece.color == WHITE) ? 'K' : 'k';
                    break;
                default:
                    display_char = '.';
            }
            printf("%c ", display_char);
        }
        printf("\n");
    }
    printf("\n");
}

void move_piece(ChessBoard *chessboard, int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE ||
        chessboard->board[startX][startY].type == EMPTY) {
        printf("Invalid Move!\n");
        return;
    }

    chessboard->board[endX][endY] = chessboard->board[startX][startY];
    chessboard->board[startX][startY].type = EMPTY;
}

int main() {
    ChessBoard chessboard;
    initialize_board(&chessboard);

    print_board(&chessboard);
    
    char command[20];
    while (1) {
        printf("Enter move (e.g., 'e2 e4') or 'exit' to quit: ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        int startX, startY, endX, endY;
        if (sscanf(command, "%d %d %d %d", &startX, &startY, &endX, &endY) == 4) {
            move_piece(&chessboard, startX, startY, endX, endY);
        }

        print_board(&chessboard);
    }

    return 0;
}