//GEMINI-pro DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_NAME_LENGTH 20
#define MAX_MOVES 100
#define MAX_PLAYERS 4

// Data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    int moves[MAX_MOVES];
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
    int current_player;
    int board[3][3];
} Game;

// Function prototypes
void initialize_game(Game *game);
void print_board(Game *game);
int make_move(Game *game, int player_index, int row, int col);
int check_for_winner(Game *game);
void print_winner(Game *game);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game
    Game game;
    initialize_game(&game);

    // Print the initial board
    print_board(&game);

    // Play the game
    while (check_for_winner(&game) == -1) {
        // Get the current player's move
        int player_index = game.current_player;
        int row, col;
        printf("Player %s, enter your move (row, col): ", game.players[player_index].name);
        scanf("%d %d", &row, &col);

        // Make the move
        if (make_move(&game, player_index, row, col) == -1) {
            printf("Invalid move. Try again.\n");
        } else {
            // Print the updated board
            print_board(&game);

            // Check for a winner
            int winner = check_for_winner(&game);
            if (winner != -1) {
                print_winner(&game);
                break;
            }

            // Switch to the next player
            game.current_player = (game.current_player + 1) % game.num_players;
        }
    }

    return 0;
}

// Initializes the game
void initialize_game(Game *game) {
    // Get the number of players
    printf("Enter the number of players (2-4): ");
    scanf("%d", &game->num_players);

    // Get the names of the players
    for (int i = 0; i < game->num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", game->players[i].name);
        game->players[i].score = 0;
    }

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game->board[i][j] = 0;
        }
    }

    // Set the current player to player 1
    game->current_player = 0;
}

// Prints the board
void print_board(Game *game) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->board[i][j] == 0) {
                printf(" ");
            } else if (game->board[i][j] == 1) {
                printf("X");
            } else if (game->board[i][j] == 2) {
                printf("O");
            }
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Makes a move for the specified player
int make_move(Game *game, int player_index, int row, int col) {
    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2 || game->board[row][col] != 0) {
        return -1;
    }

    // Make the move
    game->board[row][col] = player_index + 1;
    game->players[player_index].moves[game->players[player_index].score++] = row * 3 + col;
    return 0;
}

// Checks for a winner
int check_for_winner(Game *game) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2] && game->board[i][0] != 0) {
            return game->board[i][0] - 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i] && game->board[0][i] != 0) {
            return game->board[0][i] - 1;
        }
    }

    // Check diagonals
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2] && game->board[0][0] != 0) {
        return game->board[0][0] - 1;
    }
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0] && game->board[0][2] != 0) {
        return game->board[0][2] - 1;
    }

    // No winner yet
    return -1;
}

// Prints the winner
void print_winner(Game *game) {
    int winner = check_for_winner(game);
    printf("Player %s wins!\n", game->players[winner].name);
}