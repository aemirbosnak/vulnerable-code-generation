//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[3][3]);
int check_win(char board[3][3], char player);
void reset_board(char board[3][3]);

int main()
{
  char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  char player1 = 'X', player2 = 'O';
  char current_player = player1;
  int move, num_moves = 0, winner = 0;

  srand(time(NULL));

  printf("Welcome to Tic Tac Toe!\n");
  print_board(board);

  while (num_moves < 9 && !winner)
  {
    printf("It's %c's turn! Please enter your move: ", current_player);
    scanf("%d", &move);
    fflush(stdin); // Clear buffer after scanf

    // Check if move is valid
    if (move < 1 || move > 9 || board[(move-1)/3][(move-1)%3] == 'X' || board[(move-1)/3][(move-1)%3] == 'O')
    {
      printf("That is not a valid move. Please try again.\n");
      continue;
    }

    // Make the move
    board[(move-1)/3][(move-1)%3] = current_player;
    num_moves++;
    print_board(board);

    // Check if there is a winner
    winner = check_win(board, current_player);

    // Switch players
    if (current_player == player1)
      current_player = player2;
    else
      current_player = player1;

    // If there are no more moves, it is a draw
    if (num_moves == 9 && !winner)
    {
      printf("It's a draw!\n");
      break;
    }
  }

  // Print winner message
  if (winner)
    printf("%c wins!\n", winner);

  // Ask to play again
  char play_again;
  printf("Would you like to play again? (y/n): ");
  scanf(" %c", &play_again);
  if (play_again == 'y' || play_again == 'Y')
  {
    // Reset the board and variables
    reset_board(board);
    current_player = player1;
    num_moves = 0;

    main(); // Call main function again
  }

  return 0;
}

void print_board(char board[3][3])
{
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

int check_win(char board[3][3], char player)
{
  // Check rows
  if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
      (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
      (board[2][0] == player && board[2][1] == player && board[2][2] == player))
    return player;

  // Check columns
  if ((board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
      (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
      (board[0][2] == player && board[1][2] == player && board[2][2] == player))
    return player;

  // Check diagonals
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    return player;

  // If no winner, return 0
  return 0;
}

void reset_board(char board[3][3])
{
  board[0][0] = '1';
  board[0][1] = '2';
  board[0][2] = '3';
  board[1][0] = '4';
  board[1][1] = '5';
  board[1][2] = '6';
  board[2][0] = '7';
  board[2][1] = '8';
  board[2][2] = '9';
}