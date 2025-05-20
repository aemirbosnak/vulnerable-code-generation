//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to print the game board.
void print_board(int board[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won.
int check_winner(int board[][COLS]) {
  // Check rows for a winner.
  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
      return board[i][0];
    }
  }

  // Check columns for a winner.
  for (int j = 0; j < COLS; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0) {
      return board[0][j];
    }
  }

  // Check diagonals for a winner.
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
    return board[0][2];
  }

  // No winner yet.
  return 0;
}

// Function to get a valid move from the player.
int get_move(int board[][COLS], int player) {
  int move;

  // Get a move from the player.
  printf("Player %d, enter your move (1-9): ", player);
  scanf("%d", &move);

  // Check if the move is valid.
  while (move < 1 || move > 9 || board[(move - 1) / COLS][(move - 1) % COLS] != 0) {
    printf("Invalid move. Please enter a valid move (1-9): ");
    scanf("%d", &move);
  }

  // Return the move.
  return move;
}

// Function to play the game.
void play_game() {
  // Initialize the game board.
  int board[ROWS][COLS] = {0};

  // Initialize the current player.
  int player = 1;

  // Play the game until there is a winner or a draw.
  while (check_winner(board) == 0) {
    // Get a move from the current player.
    int move = get_move(board, player);

    // Place the player's symbol on the board.
    board[(move - 1) / COLS][(move - 1) % COLS] = player;

    // Print the game board.
    print_board(board);

    // Check if the current player has won.
    int winner = check_winner(board);
    if (winner != 0) {
      printf("Player %d wins!\n", winner);
      break;
    }

    // Switch to the other player.
    player = player % 2 + 1;
  }

  // Check if the game ended in a draw.
  if (check_winner(board) == 0) {
    printf("The game ended in a draw.\n");
  }
}

// Main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Play the game.
  play_game();

  return 0;
}