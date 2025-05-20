//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3

// Define the game pieces
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER1_WON 1
#define PLAYER2_WON 2
#define TIE 3

// Define the function prototypes
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE]);
int make_move(char board[BOARD_SIZE][BOARD_SIZE], char player);

// Main function
int main() {
  // Initialize the game board
  char board[BOARD_SIZE][BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Initialize the game state
  int game_state = GAME_IN_PROGRESS;

  // Initialize the current player
  char current_player = PLAYER1;

  // Loop until the game is over
  while (game_state == GAME_IN_PROGRESS) {
    // Print the game board
    print_board(board);

    // Get the player's move
    int row, col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &col);

    // Make the move
    game_state = make_move(board, current_player);

    // Switch the current player
    if (current_player == PLAYER1) {
      current_player = PLAYER2;
    } else {
      current_player = PLAYER1;
    }
  }

  // Print the game result
  if (game_state == PLAYER1_WON) {
    printf("Player 1 wins!\n");
  } else if (game_state == PLAYER2_WON) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  return 0;
}

// Function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the game is over
int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
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

  // The game is still in progress
  return GAME_IN_PROGRESS;
}

// function to make a move
int make_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
  // Get the player's move
  int row, col;
  printf("Enter your move (row, column): ");
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
    printf("Invalid move. Try again.\n");
    return GAME_IN_PROGRESS;
  }

  // Make the move
  board[row][col] = player;

  // Check if the game is over
  return check_win(board);
}