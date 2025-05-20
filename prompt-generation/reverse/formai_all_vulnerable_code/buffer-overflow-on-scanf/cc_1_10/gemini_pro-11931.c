//GEMINI-pro DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_ONE_WINS 1
#define PLAYER_TWO_WINS 2
#define DRAW 3

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game state
int game_state = GAME_IN_PROGRESS;

// Initialize the player turn
int player_turn = PLAYER_ONE;

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
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

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Function to get the player's move
void get_player_move() {
  int row, column;

  // Get the player's row and column input
  printf("Enter the row and column of your move (0-2): ");
  scanf("%d %d", &row, &column);

  // Check if the move is valid
  while (row < 0 || row > 2 || column < 0 || column > 2 || board[row][column] != ' ') {
    printf("Invalid move. Please enter a valid row and column: ");
    scanf("%d %d", &row, &column);
  }

  // Place the player's symbol on the board
  board[row][column] = player_turn;

  // Switch the player turn
  player_turn = player_turn == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
}

// Function to play the game
void play_game() {
  // Print the initial game board
  print_board();

  // Loop until the game is over
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player's move
    get_player_move();

    // Check if the player has won
    game_state = check_win();

    // Print the updated game board
    print_board();
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_ONE_WINS:
      printf("Player One wins!\n");
      break;
    case PLAYER_TWO_WINS:
      printf("Player Two wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }
}

// Function to start the game
void start_game() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Initialize the game state
  game_state = GAME_IN_PROGRESS;

  // Initialize the player turn
  player_turn = PLAYER_ONE;

  // Play the game
  play_game();
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Start the game
  start_game();

  return 0;
}