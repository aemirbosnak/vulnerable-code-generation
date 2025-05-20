//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define TIE 3

// Define the function prototypes
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_for_winner(char board[BOARD_SIZE][BOARD_SIZE]);
void get_player_move(char board[BOARD_SIZE][BOARD_SIZE], int player);

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the game board
  char board[BOARD_SIZE][BOARD_SIZE];
  initialize_board(board);

  // Print the game board
  print_board(board);

  // Game loop
  int game_state = GAME_IN_PROGRESS;
  int player = PLAYER_1;
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player's move
    get_player_move(board, player);

    // Check for a winner
    game_state = check_for_winner(board);

    // Print the game board
    print_board(board);

    // Switch to the other player
    player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WINS:
      printf("Player 2 wins!\n");
      break;
    case TIE:
      printf("Tie!\n");
      break;
  }

  return 0;
}

// Initialize the game board
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Check for a winner
int check_for_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Check for a winner in rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return (board[i][0] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for a winner in columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return (board[0][i] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for a winner in diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return (board[0][0] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return (board[0][2] == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
  }

  // Check for a tie
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return TIE;
  }

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Get the player's move
void get_player_move(char board[BOARD_SIZE][BOARD_SIZE], int player) {
  int row, col;

  do {
    printf("Player %c, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);
  } while (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ');

  // Place the player's symbol on the board
  board[row - 1][col - 1] = player;
}