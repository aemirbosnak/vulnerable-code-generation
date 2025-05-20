//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game state
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER_ONE_WINS 1
#define GAME_STATE_PLAYER_TWO_WINS 2
#define GAME_STATE_DRAW 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player = PLAYER_ONE;

// Define the game state
int game_state = GAME_STATE_IN_PROGRESS;

// Function to initialize the game board
void initialize_board() {
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
}

// Function to get the player's move
void get_move(int *row, int *column) {
  printf("Player %c, please enter your move (row, column): ", current_player);
  scanf("%d %d", row, column);
}

// Function to make a move on the game board
void make_move(int row, int column) {
  board[row][column] = current_player;
}

// Function to check if the game is over
int check_game_over() {
  // Check if there is a winner
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check if there is a winner in row i
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return current_player == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WINS : GAME_STATE_PLAYER_TWO_WINS;
    }

    // Check if there is a winner in column i
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return current_player == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WINS : GAME_STATE_PLAYER_TWO_WINS;
    }
  }

  // Check if there is a winner in the diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return current_player == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WINS : GAME_STATE_PLAYER_TWO_WINS;
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return current_player == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WINS : GAME_STATE_PLAYER_TWO_WINS;
  }

  // Check if the game is a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return GAME_STATE_DRAW;
  }

  // The game is not over
  return GAME_STATE_IN_PROGRESS;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the game board
  print_board();

  // While the game is in progress
  while (game_state == GAME_STATE_IN_PROGRESS) {
    // Get the player's move
    int row, column;
    get_move(&row, &column);

    // Make the move on the game board
    make_move(row, column);

    // Print the game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();
  }

  // Print the game result
  if (game_state == GAME_STATE_PLAYER_ONE_WINS) {
    printf("Player One wins!\n");
  } else if (game_state == GAME_STATE_PLAYER_TWO_WINS) {
    printf("Player Two wins!\n");
  } else if (game_state == GAME_STATE_DRAW) {
    printf("The game is a draw!\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}