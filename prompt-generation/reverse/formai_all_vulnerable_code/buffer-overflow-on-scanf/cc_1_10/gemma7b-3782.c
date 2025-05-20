//Gemma-7B DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Variables
  int player_1_wins = 0;
  int player_2_wins = 0;
  int current_player = 1;
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  // Game Loop
  while (player_1_wins == 0 && player_2_wins == 0)
  {
    // Display Board
    system("cls");
    printf("   |---|---|---|\n");
    printf("  | %c | %c | %c | \n", board[0][0], board[0][1], board[0][2]);
    printf("  |---|---|---|\n");
    printf("  | %c | %c | %c | \n", board[1][0], board[1][1], board[1][2]);
    printf("  |---|---|---|\n");
    printf("  | %c | %c | %c | \n", board[2][0], board[2][1], board[2][2]);
    printf("   |---|---|---|\n");

    // Get Move
    int move_x, move_y;
    printf("Enter move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    // Validate Move
    if (board[move_x][move_y] != ' ')
    {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Place Mark
    board[move_x][move_y] = current_player == 1 ? 'X' : 'O';

    // Switch Players
    current_player = (current_player == 1) ? 2 : 1;
  }

  // Game Over
  system("cls");
  printf("   |---|---|---|\n");
  printf("  | %c | %c | %c | \n", board[0][0], board[0][1], board[0][2]);
  printf("  |---|---|---|\n");
  printf("  | %c | %c | %c | \n", board[1][0], board[1][1], board[1][2]);
  printf("  |---|---|---|\n");
  printf("  | %c | %c | %c | \n", board[2][0], board[2][1], board[2][2]);
  printf("   |---|---|---|\n");

  // Winner
  if (player_1_wins)
  {
    printf("Player 1 wins!");
  }
  else if (player_2_wins)
  {
    printf("Player 2 wins!");
  }
  else
  {
    printf("It's a draw!");
  }

  return 0;
}