//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
// Tic Tac Toe AI in a brave style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int board[3][3]; // Game board
int player; // Player turn (1 or 2)
int winner; // Game winner (1 or 2 or 0 for draw)

// Initialize game board
void init_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
}

// Print game board
void print_board() {
  printf(" 1 | 2 | 3 \n");
  printf(" ---------\n");
  printf(" 4 | 5 | 6 \n");
  printf(" ---------\n");
  printf(" 7 | 8 | 9 \n");
}

// Check if game is over
int check_game_over() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }
  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i];
    }
  }
  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }
  // Check for draw
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }
  return -1;
}

// Make a move
void make_move(int player) {
  int row, col;
  do {
    printf("Player %d, enter row and column (1-3): ", player);
    scanf("%d %d", &row, &col);
    row--;
    col--;
  } while (board[row][col] != 0);
  board[row][col] = player;
}

// AI move
void make_ai_move() {
  int row, col;
  do {
    row = rand() % 3;
    col = rand() % 3;
  } while (board[row][col] != 0);
  board[row][col] = 2;
}

// Game loop
void game_loop() {
  while (1) {
    // Print game board
    print_board();
    // Make move
    make_move(player);
    // Check game over
    winner = check_game_over();
    if (winner == 1 || winner == 2) {
      break;
    }
    // Make AI move
    make_ai_move();
    // Check game over
    winner = check_game_over();
    if (winner == 1 || winner == 2) {
      break;
    }
    // Switch player
    player = 3 - player;
  }
}

// Main function
int main() {
  // Initialize game
  init_board();
  player = 1;
  winner = 0;
  // Game loop
  game_loop();
  // Print game result
  print_board();
  if (winner == 1) {
    printf("Player 1 wins!");
  } else if (winner == 2) {
    printf("AI wins!");
  } else {
    printf("Draw!");
  }
  return 0;
}