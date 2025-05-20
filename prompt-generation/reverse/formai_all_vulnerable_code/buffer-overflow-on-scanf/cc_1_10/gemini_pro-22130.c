//GEMINI-pro DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x = 0;
int player_y = 0;

// Define the goal position
int goal_x = BOARD_SIZE - 1;
int goal_y = BOARD_SIZE - 1;

// Define the number of moves
int moves = 0;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }

  // Set the player's position
  board[player_x][player_y] = 'P';

  // Set the goal position
  board[goal_x][goal_y] = 'G';
}

// Print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's input
void get_input() {
  char input;
  scanf(" %c", &input);

  switch (input) {
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
}

// Check if the player has won
int check_win() {
  if (player_x == goal_x && player_y == goal_y) {
    return 1;
  } else {
    return 0;
  }
}

// Main game loop
int main() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Main game loop
  while (!check_win()) {
    // Get the player's input
    get_input();

    // Update the player's position
    board[player_x][player_y] = 'P';

    // Print the game board
    print_board();

    // Increment the number of moves
    moves++;
  }

  // Print the game over message
  printf("You win! You took %d moves.\n", moves);

  return 0;
}