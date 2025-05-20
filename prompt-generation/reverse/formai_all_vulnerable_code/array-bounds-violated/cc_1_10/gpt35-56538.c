//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 1
#define AI 2
#define EMPTY 0

#define ROW 3
#define COL 3

// Function to print the game board
void print_board(int board[ROW][COL])
{
  printf("\n__________________________________________________\n\n");
  for (int i = 0; i < ROW; i++)
  {
    printf("|");
    for (int j = 0; j < COL; j++)
    {
      if (board[i][j] == PLAYER)
        printf(" X ");
      else if (board[i][j] == AI)
        printf(" O ");
      else
        printf("   ");
      printf("|");
    }
    printf("\n__________________________________________________\n\n");
  }
}

// Function that checks if there is a winner
int check_winner(int board[ROW][COL], int user)
{
  for (int i = 0; i < ROW; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return user;
  }

  for (int i = 0; i < COL; i++)
  {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return user;
  }

  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return user;

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return user;

  return EMPTY;
}

// AI move generator
void ai_move(int board[ROW][COL])
{
  int move_generated = 0;

  while (!move_generated)
  {
    int row = rand() % ROW;
    int col = rand() % COL;

    if (board[row][col] == EMPTY)
    {
      board[row][col] = AI;
      move_generated = 1;
    }
  }
}

int main()
{
  int board[ROW][COL] = {EMPTY};

  srand(time(0));

  int turn = PLAYER;

  while (1)
  {
    if (turn == PLAYER)
    {
      int row, col;

      printf("\nEnter the row and column coordinates: ");
      scanf("%d %d", &row, &col);

      if (board[row][col] != EMPTY)
        printf("Invalid move, please try again.\n");
      else
      {
        board[row][col] = PLAYER;
        turn = AI;

        print_board(board);

        int winner = check_winner(board, PLAYER);

        if (winner == PLAYER)
        {
          printf("\nYou win!\n");
          break;
        }
        else if (winner == AI)
        {
          printf("\nI win!\n");
          break;
        }
      }
    }
    else
    {
      printf("\nMy turn...\n");

      ai_move(board);
      turn = PLAYER;

      print_board(board);

      int winner = check_winner(board, AI);

      if (winner == PLAYER)
      {
        printf("\nYou win!\n");
        break;
      }
      else if (winner == AI)
      {
        printf("\nI win!\n");
        break;
      }
    }
  }

  return 0;
}