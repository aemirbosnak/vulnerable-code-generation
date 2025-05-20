//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 100

// Piece definitions
typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { WHITE, BLACK, NONE } Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Color turn;
} ChessGame;

void initialize_board(ChessGame *game) {
    memset(game, 0, sizeof(ChessGame));

    // Set up pieces for both players
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = (Square){ PAWN, BLACK };
        game->board[6][i] = (Square){ PAWN, WHITE };
    }

    game->board[0][0] = (Square){ ROOK, BLACK };
    game->board[0][1] = (Square){ KNIGHT, BLACK };
    game->board[0][2] = (Square){ BISHOP, BLACK };
    game->board[0][3] = (Square){ QUEEN, BLACK };
    game->board[0][4] = (Square){ KING, BLACK };
    game->board[0][5] = (Square){ BISHOP, BLACK };
    game->board[0][6] = (Square){ KNIGHT, BLACK };
    game->board[0][7] = (Square){ ROOK, BLACK };

    game->board[7][0] = (Square){ ROOK, WHITE };
    game->board[7][1] = (Square){ KNIGHT, WHITE };
    game->board[7][2] = (Square){ BISHOP, WHITE };
    game->board[7][3] = (Square){ QUEEN, WHITE };
    game->board[7][4] = (Square){ KING, WHITE };
    game->board[7][5] = (Square){ BISHOP, WHITE };
    game->board[7][6] = (Square){ KNIGHT, WHITE };
    game->board[7][7] = (Square){ ROOK, WHITE };

    game->turn = WHITE;
}

void print_board(const ChessGame *game) {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        printf("%d|", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            Square square = game->board[row][col];
            if (square.piece == EMPTY) {
                printf(" .");
            } else {
                char piece_char;
                if (square.color == WHITE) {
                    piece_char = " PNBQRK"[square.piece];
                } else {
                    piece_char = " pnbqrk"[square.piece];
                }
                printf(" %c", piece_char);
            }
        }
        printf(" |\n");
    }
    printf(" +----------------+\n");
}

bool move_piece(ChessGame *game, int startX, int startY, int endX, int endY) {
    // Simple move logic (non-validating for the sake of this example)
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return false; // Out of bounds
    }

    Square *from = &game->board[startY][startX];
    Square *to = &game->board[endY][endX];

    if (from->color == game->turn && to->color != from->color) {
        *to = *from; // Move the piece
        *from = (Square){ EMPTY, NONE }; // Clear original position
        game->turn = (game->turn == WHITE) ? BLACK : WHITE; // Toggle turn
        return true;
    }
    return false; // Invalid move
}

void configure_game(ChessGame *game) {
    printf("Welcome to the Chess Game!\n");
    printf("Choose your color (W/B): ");
    char choice;
    scanf(" %c", &choice);
    game->turn = (choice == 'W' || choice == 'w') ? WHITE : BLACK;

    initialize_board(game);
    print_board(game);
}

void play_game(ChessGame *game) {
    char move[10];
    while (true) {
        printf("Enter your move (e.g., e2 e4): ");
        fgets(move, sizeof(move), stdin);
        
        int startX = move[0] - 'a';
        int startY = move[1] - '1';
        int endX = move[3] - 'a';
        int endY = move[4] - '1';

        if (move_piece(game, startX, startY, endX, endY)) {
            print_board(game);
        } else {
            printf("Invalid move!\n");
        }
    }
}

int main() {
    ChessGame game;
    configure_game(&game);
    play_game(&game);
    return 0;
}