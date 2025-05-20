//FormAI DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>

int main() {
  printf("Oh my gosh! I can't believe I'm playing checkers!\n");
  printf("This is SO exciting!\n");
  printf("Let's get started!\n");

  char board[8][8] = {
    {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
    {' ', 'R', ' ', 'R', ' ', 'R', ' ', 'R'},
    {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
    {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
    {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'}
  };

  int i, j;
  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  int move_from_x, move_from_y, move_to_x, move_to_y;

  printf("Enter the coordinates of the piece you want to move (x,y): ");
  scanf("%d,%d", &move_from_x, &move_from_y);

  printf("Enter the coordinates of the space you want to move to (x,y): ");
  scanf("%d,%d", &move_to_x, &move_to_y);

  board[move_to_x][move_to_y] = board[move_from_x][move_from_y];
  board[move_from_x][move_from_y] = ' ';

  printf("\n");

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("WOW! This is so much fun! Let's keep playing!\n");

  return 0;
}