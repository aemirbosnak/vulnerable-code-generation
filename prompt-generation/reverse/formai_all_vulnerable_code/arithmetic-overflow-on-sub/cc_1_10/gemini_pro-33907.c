//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

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
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to get the player's input
int get_player_input(char player) {
  int input;
  printf("Player %c, enter your move (1-%d): ", player, BOARD_SIZE);
  scanf("%d", &input);
  return input - 1;
}

// Function to check if the move is valid
int is_valid_move(int row, int col) {
  return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

// Function to make a move
void make_move(int row, int col, char player) {
  board[row][col] = player;
}

// Function to check if the game is over
int is_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
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
    return DRAW;
  }

  // Game is still in progress
  return GAME_IN_PROGRESS;
}

// Function to play the game
void play_game() {
  int game_state = GAME_IN_PROGRESS;
  char current_player = PLAYER_1;

  while (game_state == GAME_IN_PROGRESS) {
    // Print the game board
    print_board();

    // Get the player's input
    int row = get_player_input(current_player);
    int col = get_player_input(current_player);

    // Check if the move is valid
    if (!is_valid_move(row, col)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(row, col, current_player);

    // Check if the game is over
    game_state = is_game_over();

    // Switch the current player
    current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  // Print the final game board
  print_board();

  // Announce the winner
  switch (game_state) {
    case PLAYER_1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WINS:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}