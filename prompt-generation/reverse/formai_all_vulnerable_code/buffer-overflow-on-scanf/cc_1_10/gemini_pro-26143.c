//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define board size
#define BOARD_SIZE 3

// Define game states
typedef enum {
    STATE_PLAYING,
    STATE_PLAYER_WON,
    STATE_AI_WON,
    STATE_DRAW
} GameState;

// Define player types
typedef enum {
    PLAYER_HUMAN,
    PLAYER_AI
} PlayerType;

// Define board cell values
typedef enum {
    CELL_EMPTY,
    CELL_PLAYER,
    CELL_AI
} CellValue;

// Define board structure
typedef struct {
    CellValue cells[BOARD_SIZE][BOARD_SIZE];
} Board;

// Define game structure
typedef struct {
    GameState state;
    PlayerType current_player;
    Board board;
} Game;

// Initialize game
void game_init(Game *game) {
    game->state = STATE_PLAYING;
    game->current_player = PLAYER_HUMAN;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board.cells[i][j] = CELL_EMPTY;
        }
    }
}

// Print game board
void game_print_board(const Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board.cells[i][j]) {
                case CELL_EMPTY:
                    printf(" ");
                    break;
                case CELL_PLAYER:
                    printf("X");
                    break;
                case CELL_AI:
                    printf("O");
                    break;
            }
        }
        printf("\n");
    }
}

// Check if game is over
GameState game_is_over(const Game *game) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board.cells[i][0] != CELL_EMPTY &&
            game->board.cells[i][0] == game->board.cells[i][1] &&
            game->board.cells[i][1] == game->board.cells[i][2]) {
            return game->board.cells[i][0] == CELL_PLAYER ? STATE_PLAYER_WON : STATE_AI_WON;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game->board.cells[0][j] != CELL_EMPTY &&
            game->board.cells[0][j] == game->board.cells[1][j] &&
            game->board.cells[1][j] == game->board.cells[2][j]) {
            return game->board.cells[0][j] == CELL_PLAYER ? STATE_PLAYER_WON : STATE_AI_WON;
        }
    }

    // Check diagonals
    if (game->board.cells[0][0] != CELL_EMPTY &&
        game->board.cells[0][0] == game->board.cells[1][1] &&
        game->board.cells[1][1] == game->board.cells[2][2]) {
        return game->board.cells[0][0] == CELL_PLAYER ? STATE_PLAYER_WON : STATE_AI_WON;
    }
    if (game->board.cells[2][0] != CELL_EMPTY &&
        game->board.cells[2][0] == game->board.cells[1][1] &&
        game->board.cells[1][1] == game->board.cells[0][2]) {
        return game->board.cells[2][0] == CELL_PLAYER ? STATE_PLAYER_WON : STATE_AI_WON;
    }

    // Check for draw
    bool is_draw = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board.cells[i][j] == CELL_EMPTY) {
                is_draw = false;
            }
        }
    }
    if (is_draw) {
        return STATE_DRAW;
    }

    // Otherwise, game is still playing
    return STATE_PLAYING;
}

// Get player move
void game_get_human_move(Game *game) {
    int row, col;
    printf("Enter move (row, col): ");
    scanf("%d %d", &row, &col);
    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || game->board.cells[row][col] != CELL_EMPTY) {
        printf("Invalid move. Enter move (row, col): ");
        scanf("%d %d", &row, &col);
    }
    game->board.cells[row][col] = CELL_PLAYER;
}

// Get AI move
void game_get_ai_move(Game *game) {
    // TODO: Implement AI move using minimax algorithm or other AI technique
}

// Main game loop
void game_loop(Game *game) {
    while (game->state == STATE_PLAYING) {
        // Print game board
        game_print_board(game);

        // Get move from current player
        if (game->current_player == PLAYER_HUMAN) {
            game_get_human_move(game);
        } else {
            game_get_ai_move(game);
        }

        // Check game state
        game->state = game_is_over(game);

        // Switch current player
        game->current_player = game->current_player == PLAYER_HUMAN ? PLAYER_AI : PLAYER_HUMAN;
    }

    // Print final game board and result
    game_print_board(game);
    switch (game->state) {
        case STATE_PLAYER_WON:
            printf("Player won!\n");
            break;
        case STATE_AI_WON:
            printf("AI won!\n");
            break;
        case STATE_DRAW:
            printf("Draw!\n");
            break;
    }
}

int main() {
    // Initialize game
    Game game;
    game_init(&game);

    // Start game loop
    game_loop(&game);

    return 0;
}