//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
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

  // Place the player at the start position
  board[player_x][player_y] = 'P';

  // Place the goal at the end position
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
char get_input() {
  char input;
  scanf(" %c", &input);
  return input;
}

// Move the player
void move_player(char input) {
  switch (input) {
    case 'w':
      if (player_x > 0) {
        board[player_x][player_y] = '.';
        player_x--;
        board[player_x][player_y] = 'P';
        moves++;
      }
      break;
    case 'a':
      if (player_y > 0) {
        board[player_x][player_y] = '.';
        player_y--;
        board[player_x][player_y] = 'P';
        moves++;
      }
      break;
    case 's':
      if (player_x < BOARD_SIZE - 1) {
        board[player_x][player_y] = '.';
        player_x++;
        board[player_x][player_y] = 'P';
        moves++;
      }
      break;
    case 'd':
      if (player_y < BOARD_SIZE - 1) {
        board[player_x][player_y] = '.';
        player_y++;
        board[player_x][player_y] = 'P';
        moves++;
      }
      break;
  }
}

// Check if the player has won
int check_win() {
  return player_x == goal_x && player_y == goal_y;
}

// Main game loop
int main() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Get the player's input
  char input;

  // While the player has not won
  while (!check_win()) {
    // Get the player's input
    input = get_input();

    // Move the player
    move_player(input);

    // Print the game board
    print_board();
  }

  // Print the number of moves
  printf("You won in %d moves!\n", moves);

  return 0;
}