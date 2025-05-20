//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_turn;
} Game;

void initialize_board(Game *game) {
    const char *initial_position[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(game->board[i], initial_position[i]);
    }
    game->current_turn = WHITE; // White starts
}

void print_board(const Game *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i); // Row numbers 8 to 1
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_position(char *move) {
    return strlen(move) == 4 &&
           move[0] >= 'a' && move[0] <= 'h' &&
           move[1] >= '1' && move[1] <= '8' &&
           move[2] >= 'a' && move[2] <= 'h' &&
           move[3] >= '1' && move[3] <= '8';
}

void make_move(Game *game, const char *move) {
    int start_col = move[0] - 'a';
    int start_row = BOARD_SIZE - (move[1] - '0') - 1;
    int end_col = move[2] - 'a';
    int end_row = BOARD_SIZE - (move[3] - '0') - 1;

    char piece = game->board[start_row][start_col];

    if (piece != EMPTY && 
        ((piece >= 'A' && piece <= 'Z' && game->current_turn == WHITE) || 
         (piece >= 'a' && piece <= 'z' && game->current_turn == BLACK))) {

        game->board[end_row][end_col] = piece;  // Move the piece
        game->board[start_row][start_col] = EMPTY; // Empty the start position
        game->current_turn = (game->current_turn == WHITE) ? BLACK : WHITE; // Switch turn
    } else {
        printf("Invalid move\n");
    }
}

void play_game() {
    Game game;
    initialize_board(&game);
    char move[5];

    while (1) {
        print_board(&game);
        printf("%c's turn. Enter your move (e.g. e2e4): ", game.current_turn);
        scanf("%s", move);

        if (strcmp(move, "quit") == 0) {
            printf("Game ended.\n");
            break;
        }

        if (is_valid_position(move)) {
            make_move(&game, move);
        } else {
            printf("Invalid input. Please enter your move in the format 'e2e4'.\n");
        }
    }
}

int main() {
    printf("Welcome to the Simple C Chess Engine!\n");
    play_game();
    return 0;
}