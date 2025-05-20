//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
int board[BOARD_SIZE][BOARD_SIZE];

// Define the player tokens
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_OVER 0
#define PLAYING 1

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
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a move is valid
int is_valid_move(int x, int y) {
  return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == ' ');
}

// Function to make a move
void make_move(int player, int x, int y) {
  if (is_valid_move(x, y)) {
    board[x][y] = player;
  }
}

// Function to check if the game is over
int is_game_over() {
  // Check for a win in any row
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return 1;
    }
  }

  // Check for a win in any column
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
      return 1;
    }
  }

  // Check for a win in either diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return 1;
  }
  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return 1;
  }

  // Check for a tie
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == BOARD_SIZE * BOARD_SIZE) {
    return 2;
  }

  // Otherwise, the game is still playing
  return 0;
}

// Function to get the next player's move
void get_next_move(int player) {
  int x, y;
  do {
    printf("Player %c, enter your move (row, column): ", player);
    scanf("%d %d", &x, &y);
  } while (!is_valid_move(x, y));

  make_move(player, x, y);
}

// Main game loop
int main() {
  // Initialize the game board
  init_board();

  // Set the initial game state
  int state = PLAYING;

  // Main game loop
  while (state == PLAYING) {
    // Print the game board
    print_board();

    // Get the next player's move
    if (rand() % 2 == 0) {
      get_next_move(PLAYER_1);
    } else {
      get_next_move(PLAYER_2);
    }

    // Check if the game is over
    state = is_game_over();
  }

  // Print the final game board
  print_board();

  // Print the game result
  if (state == 1) {
    printf("Player %c wins!\n", board[0][0]);
  } else if (state == 2) {
    printf("Tie game!\n");
  }

  return 0;
}