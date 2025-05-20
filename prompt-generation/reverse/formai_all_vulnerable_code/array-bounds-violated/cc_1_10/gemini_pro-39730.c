//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the table size
#define TABLE_WIDTH 8
#define TABLE_HEIGHT 8

// Define the player types
#define PLAYER_ONE 1
#define PLAYER_TWO 2

// Define the game states
#define GAME_IN_PROGRESS 1
#define GAME_OVER_PLAYER_ONE_WINS 2
#define GAME_OVER_PLAYER_TWO_WINS 3
#define GAME_OVER_DRAW 4

// Define the board
char board[TABLE_WIDTH][TABLE_HEIGHT];

// Define the player turns
int current_player = PLAYER_ONE;

// Define the game state
int game_state = GAME_IN_PROGRESS;

// Function to initialize the game
void initialize_game() {
  // Set all the board positions to empty
  for (int i = 0; i < TABLE_WIDTH; i++) {
    for (int j = 0; j < TABLE_HEIGHT; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the current player to player one
  current_player = PLAYER_ONE;

  // Set the game state to in progress
  game_state = GAME_IN_PROGRESS;
}

// Function to print the game board
void print_board() {
  // Print the top of the board
  printf("  ");
  for (int i = 0; i < TABLE_WIDTH; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  // Print the rows of the board
  for (int i = 0; i < TABLE_HEIGHT; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < TABLE_WIDTH; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
int get_player_move() {
  // Get the player's move from the console
  int move;
  printf("Player %d, enter your move (1-%d): ", current_player, TABLE_WIDTH);
  scanf("%d", &move);

  // Return the player's move
  return move - 1;
}

// Function to make a move on the board
void make_move(int move) {
  // Find the first empty row in the column
  int row = TABLE_HEIGHT - 1;
  while (row >= 0 && board[row][move] != ' ') {
    row--;
  }

  // If there is an empty row, place the player's piece in it
  if (row >= 0) {
    board[row][move] = current_player == PLAYER_ONE ? 'X' : 'O';
  }
}

// Function to check if the game is over
int check_game_over() {
  // Check if there is a winner
  for (int i = 0; i < TABLE_WIDTH; i++) {
    // Check for a horizontal win
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return current_player == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WINS : GAME_OVER_PLAYER_TWO_WINS;
    }

    // Check for a vertical win
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return current_player == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WINS : GAME_OVER_PLAYER_TWO_WINS;
    }
  }

  // Check for a diagonal win
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return current_player == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WINS : GAME_OVER_PLAYER_TWO_WINS;
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return current_player == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WINS : GAME_OVER_PLAYER_TWO_WINS;
  }

  // Check if the board is full
  int full = 1;
  for (int i = 0; i < TABLE_WIDTH; i++) {
    for (int j = 0; j < TABLE_HEIGHT; j++) {
      if (board[i][j] == ' ') {
        full = 0;
        break;
      }
    }
  }

  // If the board is full, the game is a draw
  if (full) {
    return GAME_OVER_DRAW;
  }

  // The game is not over yet
  return GAME_IN_PROGRESS;
}

// Function to play the game
void play_game() {
  // Initialize the game
  initialize_game();

  // While the game is in progress
  while (game_state == GAME_IN_PROGRESS) {
    // Print the game board
    print_board();

    // Get the player's move
    int move = get_player_move();

    // Make the move on the board
    make_move(move);

    // Check if the game is over
    game_state = check_game_over();

    // Switch to the other player
    current_player = current_player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
  }

  // Print the final game board
  print_board();

  // Print the game over message
  switch (game_state) {
    case GAME_OVER_PLAYER_ONE_WINS:
      printf("Player one wins!\n");
      break;
    case GAME_OVER_PLAYER_TWO_WINS:
      printf("Player two wins!\n");
      break;
    case GAME_OVER_DRAW:
      printf("Draw!\n");
      break;
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}