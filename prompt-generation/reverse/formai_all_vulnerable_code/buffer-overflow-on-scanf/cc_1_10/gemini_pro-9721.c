//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
    bool game_over;
} Game;

void initialize_game(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
    game->current_player = 'X';
    game->game_over = false;
}

void print_game(Game *game) {
    printf("  0 1 2\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(Game *game, Move move) {
    return move.x >= 0 && move.x < BOARD_SIZE && move.y >= 0 && move.y < BOARD_SIZE && game->board[move.x][move.y] == ' ';
}

void make_move(Game *game, Move move) {
    game->board[move.x][move.y] = game->current_player;
    game->current_player = game->current_player == 'X' ? 'O' : 'X';
}

bool is_game_over(Game *game) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] != ' ' && game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2]) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] != ' ' && game->board[0][j] == game->board[1][j] && game->board[1][j] == game->board[2][j]) {
            return true;
        }
    }

    // Check diagonals
    if (game->board[0][0] != ' ' && game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2]) {
        return true;
    }
    if (game->board[0][2] != ' ' && game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0]) {
        return true;
    }

    // Check for draw
    bool draw = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
    }
    if (draw) {
        game->game_over = true;
    }

    return game->game_over;
}

Move get_ai_move(Game *game) {
    // Implement your AI algorithm here
    // For now, we'll just return a random valid move
    Move move;
    do {
        move.x = rand() % BOARD_SIZE;
        move.y = rand() % BOARD_SIZE;
    } while (!is_valid_move(game, move));

    return move;
}

int main() {
    // Initialize the game
    Game game;
    initialize_game(&game);

    // Print the initial game board
    print_game(&game);

    // Main game loop
    while (!game.game_over) {
        // Get the player's move
        Move move;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move.x, &move.y);

        // Validate the move
        while (!is_valid_move(&game, move)) {
            printf("Invalid move. Enter a valid move: ");
            scanf("%d %d", &move.x, &move.y);
        }

        // Make the move
        make_move(&game, move);

        // Print the updated game board
        print_game(&game);

        // Check if the game is over
        if (is_game_over(&game)) {
            break;
        }

        // Get the AI's move
        move = get_ai_move(&game);

        // Make the AI's move
        make_move(&game, move);

        // Print the updated game board
        print_game(&game);
    }

    // Print the game result
    if (game.game_over) {
        if (game.current_player == 'X') {
            printf("O wins!");
        } else if (game.current_player == 'O') {
            printf("X wins!");
        } else {
            printf("Draw!");
        }
    }

    return 0;
}