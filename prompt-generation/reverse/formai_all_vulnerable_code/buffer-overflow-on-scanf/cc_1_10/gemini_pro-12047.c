//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int is_valid_move(int row, int col) {
  return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

void make_move(int row, int col, char player) {
  board[row][col] = player;
}

int check_winner() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i];
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  return ' ';
}

void print_board() {
  printf("  0 1 2\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int minimax(int depth, char player) {
  // Check if the game is over
  int winner = check_winner();
  if (winner != ' ') {
    if (winner == 'X') {
      return -10;
    } else if (winner == 'O') {
      return 10;
    } else {
      return 0;
    }
  }

  // Find the best move for the current player
  int best_score = -1000;
  int best_row = -1;
  int best_col = -1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (is_valid_move(i, j)) {
        // Make the move
        make_move(i, j, player);

        // Recursively call minimax to find the best move for the other player
        int score = minimax(depth + 1, (player == 'X' ? 'O' : 'X'));

        // Undo the move
        make_move(i, j, ' ');

        // Update the best move if the current move is better
        if (depth == 0) {
          printf("Evaluating move at (%d, %d)\n", i, j);
          printf("Score: %d\n", score);
        }
        if (score > best_score) {
          best_score = score;
          best_row = i;
          best_col = j;
        }
      }
    }
  }

  // Return the best score
  return best_score;
}

int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Play the game
  char player = 'X';
  while (check_winner() == ' ') {
    // Get the player's move
    int row, col;
    printf("Player %c's turn:\n", player);
    printf("Enter row and column (0-2 0-2): ");
    scanf("%d %d", &row, &col);

    // Make the move
    if (is_valid_move(row, col)) {
      make_move(row, col, player);
    } else {
      printf("Invalid move. Try again.\n");
    }

    // Print the board
    print_board();

    // Check if the game is over
    int winner = check_winner();
    if (winner != ' ') {
      if (winner == 'X') {
        printf("Player X wins!\n");
      } else if (winner == 'O') {
        printf("Player O wins!\n");
      } else {
        printf("Tie!\n");
      }
    }

    // Switch to the other player
    player = (player == 'X' ? 'O' : 'X');
  }

  return 0;
}