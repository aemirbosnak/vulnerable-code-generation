//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER_X_WINS 1
#define GAME_STATE_PLAYER_O_WINS 2
#define GAME_STATE_DRAW 3

// Define the game functions
int check_for_win(char player);
int check_for_draw();
void print_board();
void get_player_move(char player);
int check_for_valid_move(int row, int col);
void make_move(char player, int row, int col);

// Main game loop
int main() {
  // Initialize the game board
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      board[row][col] = ' ';
    }
  }

  // Set the initial game state
  int game_state = GAME_STATE_IN_PROGRESS;

  // Get the first player's move
  char player = PLAYER_X;
  get_player_move(player);

  // Loop until the game is over
  while (game_state == GAME_STATE_IN_PROGRESS) {
    // Check for a win
    if (check_for_win(player)) {
      game_state = player == PLAYER_X ? GAME_STATE_PLAYER_X_WINS : GAME_STATE_PLAYER_O_WINS;
    } else {
      // Check for a draw
      if (check_for_draw()) {
        game_state = GAME_STATE_DRAW;
      } else {
        // Get the next player's move
        player = player == PLAYER_X ? PLAYER_O : PLAYER_X;
        get_player_move(player);
      }
    }
  }

  // Print the game board
  print_board();

  // Print the game result
  switch (game_state) {
    case GAME_STATE_PLAYER_X_WINS:
      printf("Player X wins!\n");
      break;
    case GAME_STATE_PLAYER_O_WINS:
      printf("Player O wins!\n");
      break;
    case GAME_STATE_DRAW:
      printf("The game is a draw.\n");
      break;
  }

  return 0;
}

// Check for a win
int check_for_win(char player) {
  // Check for a win in the rows
  for (int row = 0; row < BOARD_SIZE; row++) {
    int count = 0;
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for a win in the columns
  for (int col = 0; col < BOARD_SIZE; col++) {
    int count = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
      if (board[row][col] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for a win in the diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  // No win found
  return 0;
}

// Check for a draw
int check_for_draw() {
  // Check if all cells are filled
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == ' ') {
        return 0;
      }
    }
  }

  // All cells are filled, so it's a draw
  return 1;
}

// Print the game board
void print_board() {
  printf("\n");
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      printf("| %c ", board[row][col]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Get the player's move
void get_player_move(char player) {
  // Get the row and column of the move
  int row, col;
  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &col);

  // Check for a valid move
  while (!check_for_valid_move(row, col)) {
    printf("Invalid move. Try again: ");
    scanf("%d %d", &row, &col);
  }

  // Make the move
  make_move(player, row, col);
}

// Check for a valid move
int check_for_valid_move(int row, int col) {
  // Check if the row and column are within the bounds of the board
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
    return 0;
  }

  // Check if the cell is empty
  if (board[row][col] != ' ') {
    return 0;
  }

  // The move is valid
  return 1;
}

// Make the move
void make_move(char player, int row, int col) {
  // Set the cell to the player's symbol
  board[row][col] = player;
}