//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

// Constants
#define BOARD_SIZE 5
#define MAX_PIECES 4

// Type definitions
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char symbol;
    bool is_player1;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int player1_pieces_count;
    int player2_pieces_count;
} Game;

// Function declarations
bool is_valid_move(const Game *game, const Position *from, const Position *to);
void make_move(Game *game, const Position *from, const Position *to);
void print_game(const Game *game);
bool is_game_over(const Game *game);
char get_winner(const Game *game);

// Main function
int main()
{
    // Create a new game
    Game game;
    game.player1_pieces_count = 0;
    game.player2_pieces_count = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game.board[i][j].symbol = '.';
        }
    }

    // Place the player 1 pieces
    for (int i = 0; i < MAX_PIECES; i++) {
        Position position = { .x = i, .y = 0 };
        game.board[position.y][position.x].symbol = 'O';
        game.player1_pieces_count++;
    }

    // Place the player 2 pieces
    for (int i = 0; i < MAX_PIECES; i++) {
        Position position = { .x = i, .y = BOARD_SIZE - 1 };
        game.board[position.y][position.x].symbol = 'X';
        game.player2_pieces_count++;
    }

    // Print the initial board
    print_game(&game);

    // Main game loop
    while (!is_game_over(&game)) {
        // Get the player 1 move
        Position from;
        printf("Player 1, enter the position of the piece you want to move (x, y): ");
        scanf("%d %d", &from.x, &from.y);

        // Get the player 2 move
        Position to;
        printf("Player 2, enter the position where you want to move the piece (x, y): ");
        scanf("%d %d", &to.x, &to.y);

        // Check if the moves are valid
        if (!is_valid_move(&game, &from, &to)) {
            printf("Invalid move!\n");
            continue;
        }

        // Make the moves
        make_move(&game, &from, &to);

        // Print the updated board
        print_game(&game);
    }

    // Print the winner
    char winner = get_winner(&game);
    if (winner == 'O') {
        printf("Player 1 wins!\n");
    } else if (winner == 'X') {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

// Function definitions

bool is_valid_move(const Game *game, const Position *from, const Position *to)
{
    if (from->x < 0 || from->x >= BOARD_SIZE || from->y < 0 || from->y >= BOARD_SIZE ||
        to->x < 0 || to->x >= BOARD_SIZE || to->y < 0 || to->y >= BOARD_SIZE ||
        game->board[from->y][from->x].symbol == '.' ||
        game->board[to->y][to->x].symbol != '.') {
        return false;
    } else {
        return true;
    }
}

void make_move(Game *game, const Position *from, const Position *to)
{
    game->board[to->y][to->x] = game->board[from->y][from->x];
    game->board[from->y][from->x].symbol = '.';
}

void print_game(const Game *game)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j].symbol);
        }
        printf("\n");
    }
}

bool is_game_over(const Game *game)
{
    if (game->player1_pieces_count == 0 || game->player2_pieces_count == 0) {
        return true;
    } else {
        return false;
    }
}

char get_winner(const Game *game)
{
    if (game->player1_pieces_count == 0) {
        return 'X';
    } else if (game->player2_pieces_count == 0) {
        return 'O';
    } else {
        return 'T';
    }
}