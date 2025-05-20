//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the number of players
#define NUM_PLAYERS 2

// Define the game piece types
#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

// Define the game state
#define PLAYING 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 3

// Define the game board
int board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
int current_player = PLAYER1;

// Define the game state
int game_state = PLAYING;

// Function to initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        printf(" ");
      } else if (board[i][j] == PLAYER1) {
        printf("X");
      } else if (board[i][j] == PLAYER2) {
        printf("O");
      }
    }
    printf("\n");
  }
}

// Function to check if a move is valid
bool is_valid_move(int x, int y) {
  return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY);
}

// Function to make a move
void make_move(int x, int y) {
  board[x][y] = current_player;
  current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
}

// Function to check if there is a winner
int check_winner() {
  // Check for a horizontal win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return board[i][0];
    }
  }

  // Check for a vertical win
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
      return board[0][j];
    }
  }

  // Check for a diagonal win
  if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return board[0][0];
  }
  if (board[0][4] != EMPTY && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return board[0][4];
  }

  // Check for a draw
  bool draw = true;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        draw = false;
        break;
      }
    }
  }
  if (draw) {
    return DRAW;
  }

  // No winner yet
  return PLAYING;
}

// Function to play the game
void play_game() {
  init_board();

  while (game_state == PLAYING) {
    // Print the game board
    print_board();

    // Get the player's move
    int x, y;
    printf("Player %d, enter your move (row, column): ", current_player);
    scanf("%d %d", &x, &y);

    // Check if the move is valid
    if (!is_valid_move(x, y)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(x, y);

    // Check if there is a winner
    game_state = check_winner();
  }

  // Print the game board
  print_board();

  // Print the game result
  if (game_state == PLAYER1_WIN) {
    printf("Player 1 wins!\n");
  } else if (game_state == PLAYER2_WIN) {
    printf("Player 2 wins!\n");
  } else if (game_state == DRAW) {
    printf("Draw!\n");
  }
}

// Main function
int main() {
  play_game();
  return 0;
}