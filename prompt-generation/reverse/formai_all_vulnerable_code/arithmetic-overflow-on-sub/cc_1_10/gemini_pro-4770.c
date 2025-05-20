//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define SIZE 3

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define IN_PROGRESS 0
#define PLAYER_1_WIN 1
#define PLAYER_2_WIN 2
#define DRAW 3

// Initialize the game board
char board[SIZE][SIZE];

// Initialize the game state
int game_state = IN_PROGRESS;

// Get the player's input
char get_player_input() {
  char input;
  printf("Enter your move (X or O): ");
  scanf(" %c", &input);
  return input;
}

// Check if the game is over
int check_game_over() {
  // Check for a win in rows
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
    }
  }

  // Check for a win in columns
  for (int j = 0; j < SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
    }
  }

  // Check for a win in diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER_1 ? PLAYER_1_WIN : PLAYER_2_WIN;
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == SIZE * SIZE) {
    return DRAW;
  }

  // The game is still in progress
  return IN_PROGRESS;
}

// Print the game board
void print_board() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Main game loop
int main() {
  // Initialize the game board
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Print the welcome message
  printf("Welcome to Tic Tac Toe!\n");

  // Get the players' input
  char player_1_symbol = get_player_input();
  char player_2_symbol = player_1_symbol == PLAYER_1 ? PLAYER_2 : PLAYER_1;

  // Start the game loop
  while (game_state == IN_PROGRESS) {
    // Get the player 1's move
    printf("Player 1's turn: ");
    int row, col;
    scanf(" %d %d", &row, &col);
    board[row - 1][col - 1] = player_1_symbol;

    // Check if the game is over
    game_state = check_game_over();

    // If the game is not over, get the player 2's move
    if (game_state == IN_PROGRESS) {
      printf("Player 2's turn: ");
      scanf(" %d %d", &row, &col);
      board[row - 1][col - 1] = player_2_symbol;

      // Check if the game is over
      game_state = check_game_over();
    }

    // Print the game board
    print_board();
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WIN:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }

  return 0;
}