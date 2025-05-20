//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10

// Define the player's starting position
#define PLAYER_START_X 0
#define PLAYER_START_Y 0

// Define the goal's position
#define GOAL_X 9
#define GOAL_Y 9

// Define the wall's position
#define WALL_X 5
#define WALL_Y 5

// Define the player's movement keys
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

// Define the game state
#define STATE_PLAYING 0
#define STATE_WON 1
#define STATE_LOST 2

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;

// Define the goal's position
int goal_x = GOAL_X;
int goal_y = GOAL_Y;

// Define the wall's position
int wall_x = WALL_X;
int wall_y = WALL_Y;

// Define the game state
int game_state = STATE_PLAYING;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the player on the starting position
  board[player_x][player_y] = 'P';

  // Place the goal on the goal position
  board[goal_x][goal_y] = 'G';

  // Place the wall on the wall position
  board[wall_x][wall_y] = 'W';
}

// Draw the game board
void draw_board() {
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

// Move the player in the given direction
void move_player(char direction) {
  switch (direction) {
    case KEY_UP:
      if (player_y > 0 && board[player_x][player_y - 1] != 'W') {
        player_y--;
      }
      break;
    case KEY_DOWN:
      if (player_y < BOARD_SIZE - 1 && board[player_x][player_y + 1] != 'W') {
        player_y++;
      }
      break;
    case KEY_LEFT:
      if (player_x > 0 && board[player_x - 1][player_y] != 'W') {
        player_x--;
      }
      break;
    case KEY_RIGHT:
      if (player_x < BOARD_SIZE - 1 && board[player_x + 1][player_y] != 'W') {
        player_x++;
      }
      break;
  }
}

// Update the game state
void update_game_state() {
  if (player_x == goal_x && player_y == goal_y) {
    game_state = STATE_WON;
  } else if (board[player_x][player_y] == 'W') {
    game_state = STATE_LOST;
  }
}

// Main game loop
int main() {
  // Initialize the game board
  init_board();

  // Draw the game board
  draw_board();

  // Get the player's input
  char input;

  // While the game is still playing
  while (game_state == STATE_PLAYING) {
    // Get the player's input
    input = get_input();

    // Move the player
    move_player(input);

    // Update the game state
    update_game_state();

    // Draw the game board
    draw_board();
  }

  // Print the game over message
  if (game_state == STATE_WON) {
    printf("You won!\n");
  } else if (game_state == STATE_LOST) {
    printf("You lost!\n");
  }

  return 0;
}