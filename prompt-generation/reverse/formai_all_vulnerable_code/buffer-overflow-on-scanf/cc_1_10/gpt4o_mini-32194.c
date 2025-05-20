//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int white_to_move;
} ChessGame;

void initialize_board(ChessGame *game) {
    const char *initial_board[BOARD_SIZE] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "........",
        "........",
        "........",
        "........",
        "pppppppp",
        "rnbqkbnr"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(game->board[i], initial_board[i]);
    }
    game->white_to_move = 1; // White starts
}

void print_board(const ChessGame *game) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(const ChessGame *game, int src_x, int src_y, int dest_x, int dest_y) {
    char piece = game->board[src_x][src_y];

    if (piece == EMPTY) {
        printf("Whoa there! No piece at that source!\n");
        return 0; // No piece to move
    }
    if ((game->white_to_move && piece >= 'a' && piece <= 'z') || 
        (!game->white_to_move && piece <= 'Z')) {
        printf("Oh no! Cannot move your opponent's piece!\n");
        return 0; // Moving opponent's piece
    }
    
    // This is a very simplified checking mechanism for a knight move
    if (piece == 'N' || piece == 'n') {
        if (!((abs(src_x - dest_x) == 2 && abs(src_y - dest_y) == 1) || 
              (abs(src_x - dest_x) == 1 && abs(src_y - dest_y) == 2))) {
            printf("Yikes! That's not a valid knight move!\n");
            return 0; // Invalid knight move
        }
    }
    
    // Assume destination is valid for now (no checking on pieces)
    return 1;
}

void make_move(ChessGame *game, int src_x, int src_y, int dest_x, int dest_y) {
    char moved_piece = game->board[src_x][src_y];
    game->board[dest_x][dest_y] = moved_piece;
    game->board[src_x][src_y] = EMPTY;
    game->white_to_move = !game->white_to_move; // Switch turns
}

void get_user_input(int *src_x, int *src_y, int *dest_x, int *dest_y) {
    printf("Surprise! Please enter your move (src_x src_y dest_x dest_y): ");
    scanf("%d %d %d %d", src_x, src_y, dest_x, dest_y);
}

int main() {
    ChessGame game;
    initialize_board(&game);
    
    while (1) {
        print_board(&game);
        int src_x, src_y, dest_x, dest_y;
        get_user_input(&src_x, &src_y, &dest_x, &dest_y);
        
        printf("You entered: (%d, %d) to (%d, %d)\n", src_x, src_y, dest_x, dest_y);
        
        if (is_valid_move(&game, src_x, src_y, dest_x, dest_y)) {
            make_move(&game, src_x, src_y, dest_x, dest_y);
            printf("Move made successfully!\n");
        } else {
            printf("Oops! Move was not successful. Try again!\n");
        }
    }

    return 0; // This line will never be reached
}