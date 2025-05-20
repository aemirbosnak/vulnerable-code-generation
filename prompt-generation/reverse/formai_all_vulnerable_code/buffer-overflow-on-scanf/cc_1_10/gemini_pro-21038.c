//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define BOARD_SIZE 8

// Define the player types
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER_1_WINS 1
#define GAME_STATE_PLAYER_2_WINS 2
#define GAME_STATE_DRAW 3

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player;

// Initialize the board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the board
void print_board() {
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's move
int get_move(char player) {
  int move;

  printf("Player %c, enter your move: ", player);
  scanf("%d", &move);

  return move;
}

// Make the player's move
void make_move(int move) {
  int row = (move - 1) / BOARD_SIZE;
  int col = (move - 1) % BOARD_SIZE;

  board[row][col] = current_player;
}

// Check if the game is over
int check_game_over() {
  // Check if there are any empty squares
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return GAME_STATE_IN_PROGRESS;
      }
    }
  }

  // Check if there is a winner
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
      return board[i][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
    }

    // Check columns
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
      return board[0][i] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
    return board[0][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
  }

  if (board[0][3] != ' ' && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
    return board[0][3] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
  }

  // The game is a draw
  return GAME_STATE_DRAW;
}

// Play the game
void play_game() {
  // Initialize the game
  init_board();

  // Set the current player
  current_player = PLAYER_1;

  // Play the game until it is over
  while (check_game_over() == GAME_STATE_IN_PROGRESS) {
    // Get the player's move
    int move = get_move(current_player);

    // Make the player's move
    make_move(move);

    // Print the board
    print_board();

    // Switch the current player
    current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  // Print the game over message
  switch (check_game_over()) {
    case GAME_STATE_PLAYER_1_WINS:
      printf("Player 1 wins!\n");
      break;
    case GAME_STATE_PLAYER_2_WINS:
      printf("Player 2 wins!\n");
      break;
    case GAME_STATE_DRAW:
      printf("The game is a draw.\n");
      break;
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}