//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Initialize the game state
int current_player = 1; // 1 for player 1, 2 for player 2
int game_over = 0; // 0 for ongoing, 1 for player 1 win, 2 for player 2 win, 3 for draw

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? 1 : 2;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == player1_symbol ? 1 : 2;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? 1 : 2;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1_symbol ? 1 : 2;
  }

  // Check for draw
  int num_empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return 3;
  }

  // No winner yet
  return 0;
}

// Function to get the next player's move
void get_move() {
  int row, col;

  // Get the player's input
  printf("Player %d, enter your move (row, col): ", current_player);
  scanf("%d %d", &row, &col);

  // Validate the input
  while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Please enter a valid move (row, col): ");
    scanf("%d %d", &row, &col);
  }

  // Place the player's symbol on the board
  board[row - 1][col - 1] = current_player == 1 ? player1_symbol : player2_symbol;
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Start the game
  while (!game_over) {
    // Print the game board
    print_board();

    // Get the next player's move
    get_move();

    // Check if the game is over
    game_over = check_win();

    // Switch to the other player
    current_player = current_player == 1 ? 2 : 1;
  }

  // Print the game result
  if (game_over == 1) {
    printf("Player 1 wins!\n");
  } else if (game_over == 2) {
    printf("Player 2 wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}