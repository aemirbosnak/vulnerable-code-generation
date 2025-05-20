//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Global variables
int players[4];
int current_player;
int board[3][3];

// Function prototypes
void print_board();
int check_winner();
void get_move(int player);
void make_move(int player, int row, int col);
void play_game();

// Main function
int main() {
  // Initialize the game
  for (int i = 0; i < 4; i++) {
    players[i] = i + 1;
  }
  current_player = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }

  // Play the game
  play_game();

  // Print the winner
  int winner = check_winner();
  if (winner == 0) {
    printf("Tie!\n");
  } else {
    printf("Player %d wins!\n", winner);
  }

  return 0;
}

// Function to print the board
void print_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        printf(" ");
      } else if (board[i][j] == 1) {
        printf("X");
      } else if (board[i][j] == 2) {
        printf("O");
      }
    }
    printf("\n");
  }
}

// Function to check for a winner
int check_winner() {
  // Check for rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
      return board[i][0];
    }
  }

  // Check for columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0) {
      return board[0][j];
    }
  }

  // Check for diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
    return board[0][2];
  }

  // No winner yet
  return 0;
}

// Function to get a move from a player
void get_move(int player) {
  int row, col;
  printf("Player %d's turn:\n", player);
  printf("Enter row (1-3): ");
  scanf("%d", &row);
  printf("Enter column (1-3): ");
  scanf("%d", &col);

  // Check if the move is valid
  while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != 0) {
    printf("Invalid move. Please try again.\n");
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
  }

  // Make the move
  make_move(player, row - 1, col - 1);
}

// Function to make a move
void make_move(int player, int row, int col) {
  board[row][col] = player;
}

// Function to play the game
void play_game() {
  while (check_winner() == 0) {
    // Get a move from the current player
    get_move(players[current_player]);

    // Print the board
    print_board();

    // Switch to the next player
    current_player = (current_player + 1) % 4;
  }
}