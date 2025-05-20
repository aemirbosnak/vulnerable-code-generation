//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE 0
#define PLAYER_ONE_MARK 'X'
#define PLAYER_TWO_MARK 'O'

// Functions
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int is_board_full(int board[BOARD_SIZE][BOARD_SIZE]);
int has_won(int board[BOARD_SIZE][BOARD_SIZE], int player);
int mark_board(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player);

int main()
{
  int board[BOARD_SIZE][BOARD_SIZE];
  int player = 1;
  int row, col;

  initialize_board(board);

  printf("Welcome to the Tic Tac Toe game\n");

  while (1)
  {
    // Print Board
    print_board(board);

    // Player Input
    printf("Player %d, enter a row and column to place your %c: ", player, player == 1 ? PLAYER_ONE_MARK : PLAYER_TWO_MARK);
    scanf("%d %d", &row, &col);

    // Check if Valid Move
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) 
    {
      printf("Invalid Move, please try again\n");
      continue;
    }

    if (board[row][col] != EMPTY_SPACE)
    {
      printf("This space is already taken, please try again\n");
      continue;
    }

    // Mark Board
    if (mark_board(board, row, col, player) == 1)
    {
      printf("Player %d wins!!\n", player);
      print_board(board);
      break;
    }

    // Draw Game
    if (is_board_full(board) == 1)
    {
      printf("It's a draw\n");
      break;
    }

    // Switch to other Player
    player = (player == 1 ? 2 : 1);
  }

  return 0;
}

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE])
{
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = EMPTY_SPACE;
    }
  }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
  int i, j;

  printf("\n");
  for (i = 0; i < BOARD_SIZE; i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == EMPTY_SPACE)
        printf("   ");
      else
        printf(" %c ", board[i][j]);

      if (j < BOARD_SIZE - 1)
        printf("|");
    }
    printf("\n");
    if (i < BOARD_SIZE - 1)
      printf("---------------\n");
  }
}

int is_board_full(int board[BOARD_SIZE][BOARD_SIZE])
{
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == EMPTY_SPACE)
        return 0;
    }
  }
  return 1;
}

int has_won(int board[BOARD_SIZE][BOARD_SIZE], int player)
{
  int i;
  // Check Rows
  for (i = 0; i < BOARD_SIZE; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return 1;
  }

  // Check Columns
  for (i = 0; i < BOARD_SIZE; i++)
  {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return 1;
  }

  // Check Diagonals
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    return 1;

  return 0;
}

int mark_board(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player)
{
  board[row][col] = player == 1 ? PLAYER_ONE_MARK : PLAYER_TWO_MARK;

  return has_won(board, player);
}