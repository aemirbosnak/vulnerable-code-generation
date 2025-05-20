//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE '-'

// Define the tic tac toe board
char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

// Define the winning conditions
int winning_conditions(char player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  // If all else fails, it's a draw
  return 0;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  int game_loop = 1;
  char current_player = PLAYER_X;

  // Place the first move randomly
  int move_row = rand() % BOARD_SIZE;
  int move_col = rand() % BOARD_SIZE;
  board[move_row][move_col] = current_player;

  // Loop until someone wins or it's a draw
  while (game_loop) {
    // Get the player's move
    int move_row_p = 0;
    int move_col_p = 0;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &move_row_p, &move_col_p);

    // Validate the move
    if (board[move_row_p][move_col_p] != EMPTY_SPACE) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board[move_row_p][move_col_p] = current_player;

    // Check if the player has won or it's a draw
    int winner = winning_conditions(current_player);
    if (winner) {
      printf("Congratulations, %c, you won!\n", current_player);
      game_loop = 0;
    } else if (board[0][0] == EMPTY_SPACE && board[0][1] == EMPTY_SPACE && board[0][2] == EMPTY_SPACE &&
        board[1][0] == EMPTY_SPACE && board[1][1] == EMPTY_SPACE && board[1][2] == EMPTY_SPACE &&
        board[2][0] == EMPTY_SPACE && board[2][1] == EMPTY_SPACE && board[2][2] == EMPTY_SPACE) {
      printf("It's a draw!\n");
      game_loop = 0;
    }

    // Switch to the next player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  return 0;
}