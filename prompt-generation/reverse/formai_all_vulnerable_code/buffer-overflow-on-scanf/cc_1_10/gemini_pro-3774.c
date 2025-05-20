//GEMINI-pro DATASET v1.0 Category: Game ; Style: all-encompassing
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

// Define the number of moves
int num_moves;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }
}

// Place the player on the game board
void place_player() {
  player_x = 0;
  player_y = 0;
  board[player_x][player_y] = 'P';
}

// Place the goal on the game board
void place_goal() {
  goal_x = BOARD_SIZE - 1;
  goal_y = BOARD_SIZE - 1;
  board[goal_x][goal_y] = 'G';
}

// Move the player
void move_player(char direction) {
  switch (direction) {
    case 'w':
      if (player_x > 0) {
        board[player_x][player_y] = '.';
        player_x--;
        board[player_x][player_y] = 'P';
      }
      break;
    case 'a':
      if (player_y > 0) {
        board[player_x][player_y] = '.';
        player_y--;
        board[player_x][player_y] = 'P';
      }
      break;
    case 's':
      if (player_x < BOARD_SIZE - 1) {
        board[player_x][player_y] = '.';
        player_x++;
        board[player_x][player_y] = 'P';
      }
      break;
    case 'd':
      if (player_y < BOARD_SIZE - 1) {
        board[player_x][player_y] = '.';
        player_y++;
        board[player_x][player_y] = 'P';
      }
      break;
  }
}

// Check if the player has reached the goal
int check_win() {
  return player_x == goal_x && player_y == goal_y;
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

// Main game loop
int main() {
  // Initialize the game
  init_board();
  place_player();
  place_goal();

  // Main game loop
  while (!check_win()) {
    // Print the game board
    print_board();

    // Get the player's input
    char input = get_input();

    // Move the player
    move_player(input);

    // Increment the number of moves
    num_moves++;
  }

  // Print the final game board
  print_board();

  // Print the number of moves
  printf("Number of moves: %d\n", num_moves);

  return 0;
}