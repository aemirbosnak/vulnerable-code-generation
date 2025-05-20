//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define SIZE 5
char board[SIZE][SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal position
int goal_x, goal_y;

// Define the number of moves
int moves = 0;

// Initialize the game board
void init_board() {
  // Fill the board with empty spaces
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the player in the center of the board
  player_x = SIZE / 2;
  player_y = SIZE / 2;

  // Place the goal in a random location on the board
  srand(time(NULL));
  goal_x = rand() % SIZE;
  goal_y = rand() % SIZE;
}

// Print the game board
void print_board() {
  // Print the top border
  printf("+-+-+-+-+-+\n");

  // Print each row of the board
  for (int i = 0; i < SIZE; i++) {
    printf("|");
    for (int j = 0; j < SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n+-+-+-+-+-+\n");
  }
}

// Get the player's input
void get_input() {
  char input;

  // Get the player's input
  printf("Enter a move (w, a, s, d): ");
  scanf(" %c", &input);

  // Move the player based on the input
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
  // Check if the player is on the goal
  return player_x == goal_x && player_y == goal_y;
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

    // Check if the player has moved off the board
    if (player_x < 0 || player_x >= SIZE || player_y < 0 || player_y >= SIZE) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Update the game board
    board[player_y][player_x] = 'P';

    // Print the game board
    print_board();
  }

  // Print the winning message
  printf("Congratulations! You won in %d moves.\n", moves);

  return 0;
}