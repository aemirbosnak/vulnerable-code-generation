//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

char grid[SIZE][SIZE], player1 = 'X', player2 = 'O', current_player;
int turns_taken = 0;

// Function to initialize the grid with empty spaces
void initialize_grid() {
  for (int i=0; i<SIZE; i++) {
    for (int j=0; j<SIZE; j++) {
      grid[i][j] = ' ';
    }
  }
}

// Function to print the current state of the grid
void print_grid() {
  printf("\nCurrent Grid:\n");
  for (int i=0; i<SIZE; i++) {
    printf("|");
    for (int j=0; j<SIZE; j++) {
      printf(" %c |", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
bool check_win() {
  // Check rows and columns
  for (int i=0; i<SIZE; i++) {
    if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
      return true;
    }
    if(grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
      return true;
    }
  }

  // Check diagonals
  if(grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
    return true;
  }
  if(grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
    return true;
  }

  // No winning combination found
  return false;
}

// Function to place a piece on the grid
void place_piece(int row, int col) {
  grid[row][col] = current_player;
  turns_taken++;
}

// Function to switch the current player
void switch_player() {
  if(current_player == player1) {
    current_player = player2;
  }
  else {
    current_player = player1;
  }
}

// Function for the main game loop
void play_game() {
  int row, col;
  bool valid_move = false;

  // Loop until a player wins or the grid is full
  while(!check_win() && turns_taken < SIZE*SIZE) {
    valid_move = false;

    // Keep asking for a move until a valid one is entered
    while(!valid_move) {
      printf("Player %c's turn. Enter the row and column to place your piece (separated by a space): ", current_player);
      scanf("%d %d", &row, &col);

      if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        // Invalid move, out of bounds
        printf("Invalid move. Row and column must be between 0 and %d.\n", SIZE-1);
      }
      else if(grid[row][col] != ' ') {
        // Invalid move, space already occupied
        printf("Invalid move. That space is already occupied.\n");
      }
      else {
        // Valid move
        valid_move = true;
        place_piece(row, col);
        print_grid();
        switch_player();
      }
    }
  }

  // Game has ended, check who won or if it was a tie
  if(check_win()) {
    printf("\nPlayer %c wins!\n", current_player);
  }
  else {
    printf("\nGame over. It's a tie!\n");
  }
}

// Main function
int main() {
  // Initialize grid and first player
  initialize_grid();
  current_player = player1;
  
  printf("Welcome to Grid Battle!\n");
  printf("Each player takes turns placing their pieces, either X or O, onto a 5x5 grid.\n");
  printf("The objective is to get 3 of your own pieces in a row (horizontally, vertically, or diagonally) before your opponent does.\n");
  printf("Let's begin!\n");

  // Start the game
  print_grid();
  play_game();

  return 0;
}