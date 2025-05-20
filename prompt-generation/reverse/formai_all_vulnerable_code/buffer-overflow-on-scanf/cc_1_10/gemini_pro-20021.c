//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the table dimensions
#define ROWS 5
#define COLUMNS 5

// Define the player types
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_ONE_WINS 1
#define PLAYER_TWO_WINS 2
#define DRAW 3

// Create the game board
char board[ROWS][COLUMNS];

// Initialize the game state
int game_state = GAME_IN_PROGRESS;

// Get the player's move
int get_move(char player) {
  int row, column;

  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &column);

  // Validate the move
  if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS || board[row][column] != ' ') {
    printf("Invalid move. Please try again.\n");
    return -1;
  }

  return row * COLUMNS + column;
}

// Make the player's move
void make_move(char player, int move) {
  int row = move / COLUMNS;
  int column = move % COLUMNS;

  board[row][column] = player;
}

// Check if the game is over
int check_game_over() {
  // Check for a win in each row
  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return board[i][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check for a win in each column
  for (int i = 0; i < COLUMNS; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
      return board[0][i] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check for a win in each diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return board[0][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
  }

  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return board[0][4] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
  }

  // Check for a draw
  int num_empty_cells = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return DRAW;
  }

  // The game is still in progress
  return GAME_IN_PROGRESS;
}

// Print the game board
void print_board() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Play the game
void play_game() {
  // Initialize the game board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      board[i][j] = ' ';
    }
  }

  // Get the players' names
  char player_one_name[20];
  char player_two_name[20];

  printf("Player One, enter your name: ");
  scanf("%s", player_one_name);

  printf("Player Two, enter your name: ");
  scanf("%s", player_two_name);

  // Start the game loop
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player one's move
    int move = get_move(PLAYER_ONE);

    // Make the move
    make_move(PLAYER_ONE, move);

    // Print the game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();

    // If the game is over, break the loop
    if (game_state != GAME_IN_PROGRESS) {
      break;
    }

    // Get the player two's move
    move = get_move(PLAYER_TWO);

    // Make the move
    make_move(PLAYER_TWO, move);

    // Print the game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_ONE_WINS:
      printf("%s wins!\n", player_one_name);
      break;
    case PLAYER_TWO_WINS:
      printf("%s wins!\n", player_two_name);
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}