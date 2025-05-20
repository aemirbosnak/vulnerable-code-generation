//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal position
int goal_x, goal_y;

// Define the number of moves made
int moves;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }
}

// Place the player and goal on the board
void place_player_and_goal() {
  // Generate random coordinates for the player and goal
  srand(time(NULL));
  player_x = rand() % BOARD_SIZE;
  player_y = rand() % BOARD_SIZE;
  goal_x = rand() % BOARD_SIZE;
  goal_y = rand() % BOARD_SIZE;

  // Make sure the player and goal are not in the same position
  while (player_x == goal_x && player_y == goal_y) {
    goal_x = rand() % BOARD_SIZE;
    goal_y = rand() % BOARD_SIZE;
  }

  // Place the player and goal on the board
  board[player_x][player_y] = 'P';
  board[goal_x][goal_y] = 'G';
}

// Print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's move
void get_move() {
  char move;

  // Get the player's input
  printf("Enter your move (w, a, s, d): ");
  scanf(" %c", &move);

  // Update the player's position
  switch (move) {
  case 'w':
    player_y--;
    break;
  case 'a':
    player_x--;
    break;
  case 's':
    player_y++;
    break;
  case 'd':
    player_x++;
    break;
  }

  // Make sure the player stays on the board
  if (player_x < 0) {
    player_x = 0;
  } else if (player_x >= BOARD_SIZE) {
    player_x = BOARD_SIZE - 1;
  }
  if (player_y < 0) {
    player_y = 0;
  } else if (player_y >= BOARD_SIZE) {
    player_y = BOARD_SIZE - 1;
  }
}

// Check if the player has reached the goal
int check_win() {
  return player_x == goal_x && player_y == goal_y;
}

// Main game loop
int main() {
  // Initialize the game
  init_board();
  place_player_and_goal();

  // Print the initial board
  print_board();

  // Main game loop
  while (!check_win()) {
    // Get the player's move
    get_move();

    // Update the game board
    board[player_x][player_y] = 'P';
    board[goal_x][goal_y] = 'G';

    // Print the updated board
    print_board();

    // Increment the number of moves
    moves++;
  }

  // Print the final board
  print_board();

  // Congratulate the player
  printf("Congratulations! You reached the goal in %d moves.\n", moves);

  return 0;
}