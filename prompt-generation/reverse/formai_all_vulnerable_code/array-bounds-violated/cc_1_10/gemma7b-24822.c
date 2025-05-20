//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1

int main()
{
  int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                 {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                 {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

  // Player's move
  int move_row, move_col;

  // AI move
  int ai_row, ai_col;

  // Game loop
  while (board[ai_row][ai_col] != EMPTY_SPOT)
  {
    // Get the player's move
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &move_row, &move_col);

    // Validate the move
    if (move_row < 1 || move_row > BOARD_SIZE || move_col < 1 || move_col > BOARD_SIZE)
    {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Place the player's mark on the board
    board[move_row][move_col] = 1;

    // Generate the AI move
    ai_row = rand() % BOARD_SIZE;
    ai_col = rand() % BOARD_SIZE;

    // Place the AI's mark on the board
    board[ai_row][ai_col] = 2;
  }

  // Game over
  printf("Game over! The winner is: ");

  // Check if the player won or the AI won
  if (board[ai_row][ai_col] == 1)
  {
    printf("You won!");
  }
  else
  {
    printf("The AI won!");
  }

  return 0;
}