//FormAI DATASET v1.0 Category: Table Game ; Style: content
#include <stdio.h>
#include <stdbool.h>

// define constants
#define BOARD_SIZE 3
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// declare functions
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
bool check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
void clear_board(char board[BOARD_SIZE][BOARD_SIZE]);

int main() 
{
  // declare variables
  char board[BOARD_SIZE][BOARD_SIZE];
  char current_player = PLAYER_1;
  bool gameover = false;

  // initialize board
  clear_board(board);

  // game loop
  while (!gameover) 
  {
    // print board
    print_board(board);

    // get user input
    int row, col;
    printf("Player %c: Enter row and column (1-3) separated by a space: ", current_player);
    scanf("%d %d", &row, &col);
    row--;
    col--;

    // check if move is valid
    if (board[row][col] != ' ')
    {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // make move
    board[row][col] = current_player;

    // check for win
    if (check_win(board, current_player))
    {
      printf("Player %c wins!\n", current_player);
      gameover = true;
    }

    // switch players
    if (current_player == PLAYER_1)
    {
      current_player = PLAYER_2;
    }
    else 
    {
      current_player = PLAYER_1;
    }
  }

  return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) 
{
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

bool check_win(char board[BOARD_SIZE][BOARD_SIZE], char player) 
{
  // check rows
  for (int row = 0; row < BOARD_SIZE; row++) 
  {
    if (board[row][0] == player && board[row][1] == player && board[row][2] == player) 
    {
      return true;
    }
  }

  // check columns
  for (int col = 0; col < BOARD_SIZE; col++) 
  {
    if (board[0][col] == player && board[1][col] == player && board[2][col] == player) 
    {
      return true;
    }
  }

  // check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
  {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
  {
    return true;
  }

  return false;
}

void clear_board(char board[BOARD_SIZE][BOARD_SIZE]) 
{
  for (int row = 0; row < BOARD_SIZE; row++) 
  {
    for (int col = 0; col < BOARD_SIZE; col++) 
    {
      board[row][col] = ' ';
    }
  }
}