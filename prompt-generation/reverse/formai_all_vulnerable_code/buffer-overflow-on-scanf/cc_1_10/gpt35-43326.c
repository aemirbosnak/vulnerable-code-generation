//FormAI DATASET v1.0 Category: Chess engine ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum { WHITE, BLACK } Color;
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Color current_turn;
} Game;

void init_game(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                game->board[i][j].piece = PAWN;
                game->board[i][j].color = BLACK;
            } else if (i == 6) {
                game->board[i][j].piece = PAWN;
                game->board[i][j].color = WHITE;
            } else {
                game->board[i][j].piece = 0;
                game->board[i][j].color = -1;
            }
        }
    }
    game->current_turn = WHITE;
}

int main() {
    Game game;
    init_game(&game);

    while (1) {
        // Print the board
        printf("\n    a b c d e f g h\n");
        printf("  +-----------------+\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d | ", i+1);
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game.board[i][j].color == WHITE) {
                    printf("W");
                } else if (game.board[i][j].color == BLACK) {
                    printf("B");
                } else {
                    printf(" ");
                }
                switch (game.board[i][j].piece) {
                    case PAWN:
                        printf("P ");
                        break;
                    case KNIGHT:
                        printf("N ");
                        break;
                    case BISHOP:
                        printf("B ");
                        break;
                    case ROOK:
                        printf("R ");
                        break;
                    case QUEEN:
                        printf("Q ");
                        break;
                    case KING:
                        printf("K ");
                        break;
                    default:
                        printf(". ");
                }
            }
            printf("|\n");
        }
        printf("  +-----------------+\n\n");

        // Ask for input
        printf("Enter a move (e.g. e2-e4): ");
        char input[6];
        scanf("%s", input);

        // Parse input
        int from_x = input[0] - 'a';
        int from_y = input[1] - '1';
        int to_x = input[3] - 'a';
        int to_y = input[4] - '1';

        // Move the piece
        game.board[to_y][to_x] = game.board[from_y][from_x];
        game.board[from_y][from_x].piece = 0;
        game.board[from_y][from_x].color = -1;

        // Switch turn
        game.current_turn = game.current_turn == WHITE ? BLACK : WHITE;
    }
    
    return 0;
}