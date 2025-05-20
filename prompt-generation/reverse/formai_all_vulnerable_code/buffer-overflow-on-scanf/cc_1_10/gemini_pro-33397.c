//GEMINI-pro DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game state
typedef enum {
  GAME_STATE_PLAYING,
  GAME_STATE_PLAYER1_WIN,
  GAME_STATE_PLAYER2_WIN,
  GAME_STATE_DRAW
} game_state_t;

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("| %c |", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Check if a player has won
game_state_t check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }

  // Check for draw
  int empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        empty_cells++;
      }
    }
  }
  if (empty_cells == 0) {
    return GAME_STATE_DRAW;
  }

  // No winner yet
  return GAME_STATE_PLAYING;
}

// Get the player's move
void get_move(char player_symbol, int *row, int *col) {
  // Get the player's input
  printf("Player %c, enter your move (row, column): ", player_symbol);
  scanf("%d %d", row, col);

  // Validate the input
  while (*row < 1 || *row > BOARD_SIZE || *col < 1 || *col > BOARD_SIZE || board[*row - 1][*col - 1] != ' ') {
    printf("Invalid move. Please enter a valid move: ");
    scanf("%d %d", row, col);
  }
}

// Play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Initialize the game state
  game_state_t game_state = GAME_STATE_PLAYING;

  // Initialize the current player
  char current_player = PLAYER1_SYMBOL;

  // Loop until the game is over
  while (game_state == GAME_STATE_PLAYING) {
    // Get the player's move
    int row, col;
    get_move(current_player, &row, &col);

    // Update the game board
    board[row - 1][col - 1] = current_player;

    // Print the game board
    print_board();

    // Check if a player has won
    game_state = check_win();

    // Switch the current player
    current_player = current_player == PLAYER1_SYMBOL ? PLAYER2_SYMBOL : PLAYER1_SYMBOL;
  }

  // Print the game result
  switch (game_state) {
    case GAME_STATE_PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case GAME_STATE_PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case GAME_STATE_DRAW:
      printf("Draw!\n");
      break;
  }
}

// Entry point of the program
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}