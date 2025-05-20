//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player types
#define PLAYER_HUMAN 1
#define PLAYER_COMPUTER 2

// Define the game states
#define GAME_STATE_PLAYING 1
#define GAME_STATE_OVER 2

// Define the winning conditions
#define WIN_CONDITION_ROW 5
#define WIN_CONDITION_COLUMN 5
#define WIN_CONDITION_DIAGONAL 5

// Define the player names
char player_names[2][20];

// Declare the game variables
int game_state;
int current_player;
int num_moves;

// Function to initialize the game
void initialize_game() {
  // Clear the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the game state to playing
  game_state = GAME_STATE_PLAYING;

  // Set the current player to human
  current_player = PLAYER_HUMAN;

  // Set the number of moves to 0
  num_moves = 0;
}

// Function to get the player name
void get_player_name(int player) {
  printf("Enter the name of player %d: ", player);
  scanf("%s", player_names[player - 1]);
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

// Function to check if a move is valid
int is_valid_move(int row, int column) {
  // Check if the row and column are within the bounds of the board
  if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) {
    return 0;
  }

  // Check if the space is already occupied
  if (board[row][column] != ' ') {
    return 0;
  }

  // The move is valid
  return 1;
}

// Function to make a move
void make_move(int row, int column, char player) {
  // Set the space to the player's symbol
  board[row][column] = player;

  // Increment the number of moves
  num_moves++;
}

// Function to check if a player has won
int has_won(char player) {
  // Check for a win in a row
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player) {
        count++;
      } else {
        count = 0;
      }
      if (count >= WIN_CONDITION_ROW) {
        return 1;
      }
    }
  }

  // Check for a win in a column
  for (int j = 0; j < BOARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][j] == player) {
        count++;
      } else {
        count = 0;
      }
      if (count >= WIN_CONDITION_COLUMN) {
        return 1;
      }
    }
  }

  // Check for a win in a diagonal
  // Top-left to bottom-right diagonal
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == player) {
      count++;
    } else {
      count = 0;
    }
    if (count >= WIN_CONDITION_DIAGONAL) {
      return 1;
    }
  }

  // Top-right to bottom-left diagonal
  count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - 1 - i] == player) {
      count++;
    } else {
      count = 0;
    }
    if (count >= WIN_CONDITION_DIAGONAL) {
      return 1;
    }
  }

  // No winner yet
  return 0;
}

// Function to get a move from the human player
void get_human_move(int *row, int *column) {
  printf("Enter your move (row, column): ");
  scanf("%d %d", row, column);
}

// Function to get a move from the computer player
void get_computer_move(int *row, int *column) {
  // Generate a random move
  srand(time(NULL));
  *row = rand() % BOARD_SIZE;
  *column = rand() % BOARD_SIZE;

  // Check if the move is valid
  while (!is_valid_move(*row, *column)) {
    *row = rand() % BOARD_SIZE;
    *column = rand() % BOARD_SIZE;
  }
}

// Function to play the game
void play_game() {
  while (game_state == GAME_STATE_PLAYING) {
    // Print the game board
    print_board();

    // Get the move from the current player
    int row, column;
    if (current_player == PLAYER_HUMAN) {
      get_human_move(&row, &column);
    } else {
      get_computer_move(&row, &column);
    }

    // Make the move
    make_move(row, column, current_player == PLAYER_HUMAN ? 'X' : 'O');

    // Check if the player has won
    if (has_won(current_player == PLAYER_HUMAN ? 'X' : 'O')) {
      // The player has won
      game_state = GAME_STATE_OVER;
    } else {
      // The game is still going on
      current_player = current_player == PLAYER_HUMAN ? PLAYER_COMPUTER : PLAYER_HUMAN;
    }
  }
}

// Function to declare the winner
void declare_winner() {
  if (current_player == PLAYER_HUMAN) {
    printf("%s wins!\n", player_names[0]);
  } else {
    printf("%s wins!\n", player_names[1]);
  }
}

// Function to main
int main() {
  // Get the player names
  get_player_name(1);
  get_player_name(2);

  // Initialize the game
  initialize_game();

  // Play the game
  play_game();

  // Declare the winner
  declare_winner();

  return 0;
}