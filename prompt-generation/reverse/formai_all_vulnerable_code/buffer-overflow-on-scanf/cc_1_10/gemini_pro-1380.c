//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal's position
int goal_x, goal_y;

// Define the number of moves the player has made
int moves;

// Define the game state
enum GameState { PLAYING, WON, LOST };
enum GameState state;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }

  // Place the player at the starting position
  player_x = 0;
  player_y = 0;

  // Place the goal at a random position
  srand(time(NULL));
  goal_x = rand() % BOARD_SIZE;
  goal_y = rand() % BOARD_SIZE;

  // Set the number of moves to 0
  moves = 0;

  // Set the game state to PLAYING
  state = PLAYING;
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

  printf("Enter a direction (w/a/s/d): ");
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

// Update the game state
void update_state() {
  // Check if the player has won
  if (player_x == goal_x && player_y == goal_y) {
    state = WON;
  }

  // Check if the player has lost
  if (player_x < 0 || player_x >= BOARD_SIZE || player_y < 0 || player_y >= BOARD_SIZE) {
    state = LOST;
  }
}

// Play the game
void play_game() {
  while (state == PLAYING) {
    // Print the game board
    print_board();

    // Get the player's input
    get_input();

    // Update the game state
    update_state();

    // Increment the number of moves
    moves++;
  }
}

// Print the game over message
void print_game_over() {
  if (state == WON) {
    printf("You won! It took you %d moves.\n", moves);
  } else if (state == LOST) {
    printf("You lost! Try again.\n");
  }
}

int main() {
  // Initialize the game board
  init_board();

  // Play the game
  play_game();

  // Print the game over message
  print_game_over();

  return 0;
}