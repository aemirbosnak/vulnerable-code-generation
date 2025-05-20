//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Board size
#define BOARD_SIZE 3

// Player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_X_WIN 2
#define GAME_STATE_O_WIN 3

// Board
char board[BOARD_SIZE][BOARD_SIZE];

// Current player
char current_player = PLAYER_X;

// Game state
int game_state = GAME_STATE_PLAYING;

// Function to print the board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a move is valid
int is_valid_move(int row, int col) {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

// Function to make a move
void make_move(int row, int col) {
  board[row][col] = current_player;
}

// Function to check if a player has won
int has_won(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  // No winner yet
  return 0;
}

// Function to check if the game is a draw
int is_draw() {
  // Check if all cells are filled
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }

  // Game is a draw
  return 1;
}

// Function to get the AI's move
int get_ai_move(int *row, int *col) {
  // Generate a random move until a valid one is found
  while (1) {
    *row = rand() % BOARD_SIZE;
    *col = rand() % BOARD_SIZE;
    if (is_valid_move(*row, *col)) {
      return 1;
    }
  }
}

// Function to play the game
void play_game() {
  // Print the initial board
  print_board();

  // Game loop
  while (game_state == GAME_STATE_PLAYING) {
    // Get the player's move
    int row, col;
    if (current_player == PLAYER_X) {
      printf("Enter your move (row, col): ");
      scanf("%d %d", &row, &col);
    } else {
      get_ai_move(&row, &col);
    }

    // Check if the move is valid
    if (!is_valid_move(row, col)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(row, col);

    // Print the board
    print_board();

    // Check if the game is over
    if (has_won(current_player)) {
      if (current_player == PLAYER_X) {
        printf("Player X wins!\n");
      } else {
        printf("Player O wins!\n");
      }
      game_state = current_player == PLAYER_X ? GAME_STATE_X_WIN : GAME_STATE_O_WIN;
    } else if (is_draw()) {
      printf("Game is a draw.\n");
      game_state = GAME_STATE_DRAW;
    }

    // Switch players
    current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
  }
}

// Main function
int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Play the game
  play_game();

  return 0;
}