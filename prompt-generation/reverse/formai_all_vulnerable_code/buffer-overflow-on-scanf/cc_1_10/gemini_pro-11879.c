//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 4
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal position
int goal_x, goal_y;

// Define the number of moves
int moves;

// Initialize the game board
void init_board() {
  // Set all cells to empty
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the player in the starting position
  player_x = 0;
  player_y = 0;

  // Place the goal in a random position
  srand(time(NULL));
  goal_x = rand() % BOARD_SIZE;
  goal_y = rand() % BOARD_SIZE;

  // Set the number of moves to 0
  moves = 0;
}

// Draw the game board
void draw_board() {
  // Clear the screen
  system("clear");

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  // Print the number of moves
  printf("Moves: %d\n", moves);
}

// Get the player's input
char get_input() {
  char input;

  // Get the input from the user
  printf("Enter a move (w, a, s, d): ");
  scanf(" %c", &input);

  // Return the input
  return input;
}

// Move the player
void move_player(char input) {
  // Move the player up
  if (input == 'w') {
    if (player_y > 0) {
      player_y--;
      moves++;
    }
  }

  // Move the player left
  else if (input == 'a') {
    if (player_x > 0) {
      player_x--;
      moves++;
    }
  }

  // Move the player down
  else if (input == 's') {
    if (player_y < BOARD_SIZE - 1) {
      player_y++;
      moves++;
    }
  }

  // Move the player right
  else if (input == 'd') {
    if (player_x < BOARD_SIZE - 1) {
      player_x++;
      moves++;
    }
  }
}

// Check if the player has won
int check_win() {
  // Check if the player is on the goal
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

  // Draw the game board
  draw_board();

  // Main game loop
  while (1) {
    // Get the player's input
    char input = get_input();

    // Move the player
    move_player(input);

    // Check if the player has won
    if (check_win()) {
      printf("You win!\n");
      break;
    }

    // Draw the game board
    draw_board();
  }

  return 0;
}