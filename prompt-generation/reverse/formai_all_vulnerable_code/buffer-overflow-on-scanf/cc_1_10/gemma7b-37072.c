//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

int main()
{
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int player = 1, turn = 0, winner = 0;

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = 0;
    }
  }

  // Game loop
  while (!winner && turn < 9)
  {
    // Get the player's move
    int move = getMove();

    // Validate the move
    if (!isValidMove(move, board))
    {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

    // Check for winner
    winner = checkWinner(board, player);

    // Increment the turn
    turn++;
  }

  // Print the winner
  if (winner)
  {
    printf("Winner: Player %d.\n", player);
  }
  else
  {
    printf("It's a draw.\n");
  }

  return 0;
}

int getMove()
{
  int move;

  // Get the move from the player
  printf("Enter your move (1-9): ");
  scanf("%d", &move);

  return move;
}

int isValidMove(int move, int board[][BOARD_SIZE])
{
  // Check if the move is within the bounds of the board
  if (move < 1 || move > 9)
  {
    return 0;
  }

  // Check if the move is already taken
  if (board[move / BOARD_SIZE][move % BOARD_SIZE] != 0)
  {
    return 0;
  }

  return 1;
}

int checkWinner(int board[][BOARD_SIZE], int player)
{
  // Check for horizontal win
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
    {
      return 1;
    }
  }

  // Check for vertical win
  for (int j = 0; j < BOARD_SIZE; j++)
  {
    if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
    {
      return 1;
    }
  }

  // Check for diagonal win
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return 1;
  }

  // No winner
  return 0;
}