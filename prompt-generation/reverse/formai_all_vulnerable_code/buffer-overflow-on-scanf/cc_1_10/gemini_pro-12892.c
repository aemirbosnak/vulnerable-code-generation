//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game states
#define STATE_PLAYING 0
#define STATE_PLAYER1_WIN 1
#define STATE_PLAYER2_WIN 2
#define STATE_DRAW 3

// Function to initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  printf("  ");
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

// Function to check if the game is over
int check_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == PLAYER1_SYMBOL) {
        return STATE_PLAYER1_WIN;
      } else if (board[i][0] == PLAYER2_SYMBOL) {
        return STATE_PLAYER2_WIN;
      }
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      if (board[0][j] == PLAYER1_SYMBOL) {
        return STATE_PLAYER1_WIN;
      } else if (board[0][j] == PLAYER2_SYMBOL) {
        return STATE_PLAYER2_WIN;
      }
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == PLAYER1_SYMBOL) {
      return STATE_PLAYER1_WIN;
    } else if (board[0][0] == PLAYER2_SYMBOL) {
      return STATE_PLAYER2_WIN;
    }
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == PLAYER1_SYMBOL) {
      return STATE_PLAYER1_WIN;
    } else if (board[0][2] == PLAYER2_SYMBOL) {
      return STATE_PLAYER2_WIN;
    }
  }

  // Check for a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return STATE_DRAW;
  }

  // Game is still playing
  return STATE_PLAYING;
}

// Function to get the player's move
int get_player_move(char player_symbol) {
  int move;
  while (1) {
    printf("Player %c, enter your move (1-9): ", player_symbol);
    scanf("%d", &move);

    if (move >= 1 && move <= 9) {
      int row = (move - 1) / BOARD_SIZE;
      int col = (move - 1) % BOARD_SIZE;

      if (board[row][col] == ' ') {
        return move;
      }
    }

    printf("Invalid move. Please try again.\n");
  }
}

// Main game loop
int main() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Game state
  int game_state = STATE_PLAYING;

  // Player turn
  int player_turn = 1;

  // Main game loop
  while (game_state == STATE_PLAYING) {
    // Get the player's move
    int move = get_player_move(player_turn == 1 ? PLAYER1_SYMBOL : PLAYER2_SYMBOL);

    // Update the game board
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;
    board[row][col] = player_turn == 1 ? PLAYER1_SYMBOL : PLAYER2_SYMBOL;

    // Print the game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();

    // Switch player turn
    player_turn = 3 - player_turn;
  }

  // Print the game result
  switch (game_state) {
    case STATE_PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case STATE_PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case STATE_DRAW:
      printf("Draw!\n");
      break;
  }

  return 0;
}