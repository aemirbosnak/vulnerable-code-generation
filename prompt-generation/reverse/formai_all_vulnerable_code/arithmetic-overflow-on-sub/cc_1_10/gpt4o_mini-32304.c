//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2, PLAYER1_KING, PLAYER2_KING } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} GameState;

void initialize_game(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    for (int j = 0; j < SIZE; j += 2) {
        game->board[0][j] = PLAYER2;
        game->board[1][j + 1] = PLAYER2;
        game->board[2][j] = PLAYER2;
        game->board[5][j] = PLAYER1;
        game->board[6][j + 1] = PLAYER1;
        game->board[7][j] = PLAYER1;
    }
}

void print_board(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == PLAYER1) {
                printf(" P1 ");
            } else if (game->board[i][j] == PLAYER2) {
                printf(" P2 ");
            } else if (game->board[i][j] == PLAYER1_KING) {
                printf(" K1 ");
            } else if (game->board[i][j] == PLAYER2_KING) {
                printf(" K2 ");
            } else {
                printf(" .  ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(GameState *game, int start_x, int start_y, int end_x, int end_y) {
    Piece piece = game->board[start_x][start_y];
    if (piece == EMPTY || game->board[end_x][end_y] != EMPTY) {
        return 0;
    }

    int direction = (piece == PLAYER1 || piece == PLAYER1_KING) ? -1 : 1;
    int delta_x = end_x - start_x;
    int delta_y = end_y - start_y;

    if (abs(delta_x) == 1 && abs(delta_y) == 1 && game->board[end_x][end_y] == EMPTY) {
        return 1; // Simple move
    } else if (abs(delta_x) == 2 && abs(delta_y) == 2) {
        int middle_x = (start_x + end_x) / 2;
        int middle_y = (start_y + end_y) / 2;
        if (game->board[middle_x][middle_y] != EMPTY &&
            game->board[middle_x][middle_y] != piece) {
            return 1; // Jump move
        }
    }
    return 0;
}

void make_move(GameState *game, int start_x, int start_y, int end_x, int end_y) {
    Piece piece = game->board[start_x][start_y];
    game->board[end_x][end_y] = piece;
    game->board[start_x][start_y] = EMPTY;

    if (end_x == 0 && piece == PLAYER1) {
        game->board[end_x][end_y] = PLAYER1_KING;
    } else if (end_x == SIZE - 1 && piece == PLAYER2) {
        game->board[end_x][end_y] = PLAYER2_KING;
    }

    int delta_x = end_x - start_x;
    int delta_y = end_y - start_y;
   
    if (abs(delta_x) == 2 && abs(delta_y) == 2) {
        int middle_x = (start_x + end_x) / 2;
        int middle_y = (start_y + end_y) / 2;
        game->board[middle_x][middle_y] = EMPTY; // Remove captured piece
    }
}

int main() {
    GameState game;
    initialize_game(&game);
    int start_x, start_y, end_x, end_y;
    
    while (1) {
        print_board(&game);
        printf("Enter move (start_x start_y end_x end_y): ");
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        
        if (is_valid_move(&game, start_x, start_y, end_x, end_y)) {
            make_move(&game, start_x, start_y, end_x, end_y);
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    
    return 0;
}