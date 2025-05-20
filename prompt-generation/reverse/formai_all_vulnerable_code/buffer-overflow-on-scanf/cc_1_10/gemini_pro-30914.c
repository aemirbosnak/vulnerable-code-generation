//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Game constants
#define BOARD_SIZE 5
#define NUM_SYMBOLS 3
#define MAX_MOVES 100

// Game state
char board[BOARD_SIZE][BOARD_SIZE];
int num_moves;

// Function prototypes
void init_game();
void print_board();
int get_move();
int check_win();
void make_move();

// Main function
int main() {
  // Initialize the game
  init_game();

  // Game loop
  while (num_moves < MAX_MOVES && check_win() == 0) {
    // Print the board
    print_board();

    // Get the player's move
    int move = get_move();

    // Make the move
    make_move(move);

    // Increment the number of moves
    num_moves++;
  }

  // Check if the player won
  if (check_win() == 1) {
    printf("You win!\n");
  } else {
    printf("You lose!\n");
  }

  return 0;
}

// Initialize the game
void init_game() {
  // Set the board to empty
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the number of moves to 0
  num_moves = 0;
}

// Print the board
void print_board() {
  // Print the top border
  printf("+---+---+---+---+---+\n");

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("| ");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c | ", board[i][j]);
    }
    printf("\n+---+---+---+---+---+\n");
  }
}

// Get the player's move
int get_move() {
  // Get the player's input
  int move;
  printf("Enter your move (1-9): ");
  scanf("%d", &move);

  // Check if the move is valid
  while (move < 1 || move > 9 || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ') {
    printf("Invalid move. Please enter a valid move (1-9): ");
    scanf("%d", &move);
  }

  // Return the move
  return move;
}

// Check if the player has won
int check_win() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return 1;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
  }

  // No wins yet
  return 0;
}

// Make the player's move
void make_move(int move) {
  // Place the player's symbol on the board
  board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = 'X';
}