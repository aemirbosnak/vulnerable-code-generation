//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_PLAYERS 2

typedef struct player {
    int x;
    int y;
    int score;
} player;

typedef struct game {
    player players[NUM_PLAYERS];
    int grid[GRID_SIZE][GRID_SIZE];
} game;

// Initialize the game
void init_game(game *g) {
    // Create the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            g->grid[i][j] = 0;
        }
    }

    // Initialize the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        g->players[i].x = 0;
        g->players[i].y = 0;
        g->players[i].score = 0;
    }
}

// Print the game board
void print_board(game *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (g->grid[i][j] == 0) {
                printf("  ");
            } else if (g->grid[i][j] == 1) {
                printf("■ ");
            } else if (g->grid[i][j] == 2) {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

// Check if the game is over
int is_game_over(game *g) {
    // Check if there are any empty cells
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (g->grid[i][j] == 0) {
                return 0;
            }
        }
    }

    // Check if any player has won
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (g->players[i].score >= 5) {
            return 1;
        }
    }

    // The game is a draw
    return 2;
}

// Get the winner of the game
int get_winner(game *g) {
    int winner = -1;
    int max_score = -1;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (g->players[i].score > max_score) {
            max_score = g->players[i].score;
            winner = i;
        }
    }

    return winner;
}

// Main game loop
int main() {
    // Initialize the game
    game g;
    init_game(&g);

    // Print the initial board
    print_board(&g);

    // Main game loop
    while (1) {
        // Get the player's move
        int player = 0;
        int x, y;
        printf("Player %d's turn: ", player + 1);
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || g.grid[x][y] != 0) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the player's piece on the board
        g.grid[x][y] = player + 1;

        // Check if the player has won
        if (g.players[player].score >= 5) {
            break;
        }

        // Switch to the next player
        player = (player + 1) % NUM_PLAYERS;

        // Print the updated board
        print_board(&g);
    }

    // Get the winner of the game
    int winner = get_winner(&g);

    // Print the results
    if (winner == -1) {
        printf("The game is a draw.\n");
    } else {
        printf("Player %d wins!\n", winner + 1);
    }

    return 0;
}