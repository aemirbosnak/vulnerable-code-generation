//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Number of players
#define NUM_PLAYERS 2

// Player colors
#define PLAYER_1_COLOR 'R'
#define PLAYER_2_COLOR 'B'

// Grid state
char grid[GRID_WIDTH][GRID_HEIGHT];

// Player positions
int player_1_x, player_1_y;
int player_2_x, player_2_y;

// Game state
int game_over;

// Function to initialize the grid
void init_grid() {
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      grid[i][j] = '.';
    }
  }
}

// Function to print the grid
void print_grid() {
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_win(char player_color) {
  // Check if the player has connected the top and bottom of the grid
  for (int i = 0; i < GRID_WIDTH; i++) {
    if (grid[i][0] == player_color && grid[i][GRID_HEIGHT - 1] == player_color) {
      return 1;
    }
  }

  // Check if the player has connected the left and right of the grid
  for (int j = 0; j < GRID_HEIGHT; j++) {
    if (grid[0][j] == player_color && grid[GRID_WIDTH - 1][j] == player_color) {
      return 1;
    }
  }

  return 0;
}

// Function to get the next move from a player
int get_move(char player_color) {
  int move;

  printf("Player %c, enter your move (1-4): ", player_color);
  scanf("%d", &move);

  return move;
}

// Function to make a move for a player
void make_move(char player_color, int move) {
  // Get the current position of the player
  int player_x, player_y;

  if (player_color == PLAYER_1_COLOR) {
    player_x = player_1_x;
    player_y = player_1_y;
  } else {
    player_x = player_2_x;
    player_y = player_2_y;
  }

  // Make the move
  switch (move) {
    case 1: // Up
      if (player_y > 0) {
        player_y--;
      }
      break;
    case 2: // Down
      if (player_y < GRID_HEIGHT - 1) {
        player_y++;
      }
      break;
    case 3: // Left
      if (player_x > 0) {
        player_x--;
      }
      break;
    case 4: // Right
      if (player_x < GRID_WIDTH - 1) {
        player_x++;
      }
      break;
  }

  // Update the player's position
  if (player_color == PLAYER_1_COLOR) {
    player_1_x = player_x;
    player_1_y = player_y;
  } else {
    player_2_x = player_x;
    player_2_y = player_y;
  }

  // Place the player's color in the grid
  grid[player_x][player_y] = player_color;
}

// Main game loop
void game_loop() {
  // Initialize the grid
  init_grid();

  // Place the players in the grid
  player_1_x = 0;
  player_1_y = 0;
  player_2_x = GRID_WIDTH - 1;
  player_2_y = GRID_HEIGHT - 1;

  // Set the game state to not over
  game_over = 0;

  // Main game loop
  while (!game_over) {
    // Get the next move from player 1
    int move1 = get_move(PLAYER_1_COLOR);

    // Make the move for player 1
    make_move(PLAYER_1_COLOR, move1);

    // Check if player 1 has won
    if (check_win(PLAYER_1_COLOR)) {
      game_over = 1;
      printf("Player 1 wins!\n");
    }

    // If the game is not over, get the next move from player 2
    if (!game_over) {
      int move2 = get_move(PLAYER_2_COLOR);

      // Make the move for player 2
      make_move(PLAYER_2_COLOR, move2);

      // Check if player 2 has won
      if (check_win(PLAYER_2_COLOR)) {
        game_over = 1;
        printf("Player 2 wins!\n");
      }
    }

    // Print the grid
    print_grid();
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Start the game loop
  game_loop();

  return 0;
}