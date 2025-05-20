//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The size of the board
#define SIZE 10

// The number of mines
#define MINES 10

// The player's state
#define PLAYING 0
#define WON 1
#define LOST 2

// The board
char board[SIZE][SIZE];

// The player's guess
int guess_x, guess_y;

// The player's state
int state = PLAYING;

// Initialize the board
void init_board() {
  // Set all cells to empty
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the mines
  srand(time(NULL));
  for (int i = 0; i < MINES; i++) {
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    board[x][y] = '*';
  }
}

// Print the board
void print_board() {
  // Print the top border
  printf("   ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Print the board
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's guess
void get_guess() {
  printf("Enter your guess (x, y): ");
  scanf(" %d %d", &guess_x, &guess_y);
}

// Check if the player's guess is valid
int is_valid_guess() {
  return guess_x >= 0 && guess_x < SIZE && guess_y >= 0 && guess_y < SIZE;
}

// Check if the player's guess is a mine
int is_mine() {
  return board[guess_x][guess_y] == '*';
}

// Check if the player has won
int has_won() {
  // Count the number of cells that have been revealed
  int revealed = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != ' ') {
        revealed++;
      }
    }
  }

  // Return true if all cells have been revealed
  return revealed == SIZE * SIZE - MINES;
}

// Play the game
void play_game() {
  // Initialize the board
  init_board();

  // Print the board
  print_board();

  // Get the player's guess
  get_guess();

  // Check if the player's guess is valid
  while (!is_valid_guess()) {
    printf("Invalid guess. Try again: ");
    get_guess();
  }

  // Check if the player's guess is a mine
  if (is_mine()) {
    // The player has lost
    state = LOST;
  } else {
    // The player has not lost
    // Reveal the cell
    board[guess_x][guess_y] = 'O';

    // Check if the player has won
    if (has_won()) {
      // The player has won
      state = WON;
    } else {
      // The player has not won
      // Print the board
      print_board();

      // Get the player's guess
      get_guess();
    }
  }
}

// Print the game over message
void print_game_over() {
  if (state == WON) {
    printf("You win!\n");
  } else if (state == LOST) {
    printf("You lose!\n");
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  // Print the game over message
  print_game_over();

  return 0;
}