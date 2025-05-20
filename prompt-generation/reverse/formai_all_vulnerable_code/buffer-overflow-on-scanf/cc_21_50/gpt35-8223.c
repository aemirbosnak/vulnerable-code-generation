//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include <stdio.h>

int main() {
  char board[8][8] = { //the checkers board
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'}
  };

  printf("Welcome to the C Checkers Game!\n");

  while (1) { //the game loop
    int from_row, from_col, to_row, to_col;

    printf("\nEnter the row and column of the checker you want to move:\n");
    scanf("%d %d", &from_row, &from_col);

    printf("Enter the row and column you want to move the checker to:\n");
    scanf("%d %d", &to_row, &to_col);

    if (board[from_row][from_col] == ' ') { //if there's no checker at this position
      printf("\nThere's no checker at this position! Try again.\n");
      continue;
    }

    if (board[to_row][to_col] != ' ') { //if there's already a checker at the position we want to move to
      printf("\nThere's already a checker at this position! Try again.\n");
      continue;
    }

    if (from_row == to_row || from_col == to_col) { //if we're not moving diagonally
      printf("\nYou can only move diagonally! Try again.\n");
      continue;
    }

    char checker_type = board[from_row][from_col]; //save the type of the checker we're moving

    //check if the move is valid
    if (checker_type == 'r') { //if we're moving a red checker
      if (to_row < from_row) { //if we're moving backwards
        printf("\nYou can't move a red checker backwards! Try again.\n");
        continue;
      }

      if (to_row - from_row == 1 && (to_col - from_col == 1 || from_col - to_col == 1)) { //if we're moving one space diagonally
        board[to_row][to_col] = 'r';
        board[from_row][from_col] = ' ';
      }
      else if (to_row - from_row == 2 && (to_col - from_col == 2 || from_col - to_col == 2)) { //if we're moving two spaces diagonally
        int middle_row = (from_row + to_row) / 2;
        int middle_col = (from_col + to_col) / 2;

        if (board[middle_row][middle_col] == 'b') { //if there's a black checker in between
          board[to_row][to_col] = 'r';
          board[from_row][from_col] = ' ';
          board[middle_row][middle_col] = ' ';
        }
        else {
          printf("\nYou can only jump over your opponent's checkers! Try again.\n");
          continue;
        }
      }
      else { //if the move is invalid
        printf("\nInvalid move! Try again.\n");
        continue;
      }

      //check if the red player has won
      int has_won = 1;
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          if (board[i][j] == 'b') {
            has_won = 0;
          }
        }
      }

      if (has_won) {
        printf("\nCongratulations! The red player has won!\n");
        break;
      }
    }
    else if (checker_type == 'b') { //if we're moving a black checker
      if (to_row > from_row) { //if we're moving backwards
        printf("\nYou can't move a black checker backwards! Try again.\n");
        continue;
      }

      if (from_row - to_row == 1 && (to_col - from_col == 1 || from_col - to_col == 1)) { //if we're moving one space diagonally
        board[to_row][to_col] = 'b';
        board[from_row][from_col] = ' ';
      }
      else if (from_row - to_row == 2 && (to_col - from_col == 2 || from_col - to_col == 2)) { //if we're moving two spaces diagonally
        int middle_row = (from_row + to_row) / 2;
        int middle_col = (from_col + to_col) / 2;

        if (board[middle_row][middle_col] == 'r') { //if there's a red checker in between
          board[to_row][to_col] = 'b';
          board[from_row][from_col] = ' ';
          board[middle_row][middle_col] = ' ';
        }
        else {
          printf("\nYou can only jump over your opponent's checkers! Try again.\n");
          continue;
        }
      }
      else { //if the move is invalid
        printf("\nInvalid move! Try again.\n");
        continue;
      }

      //check if the black player has won
      int has_won = 1;
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          if (board[i][j] == 'r') {
            has_won = 0;
          }
        }
      }

      if (has_won) {
        printf("\nCongratulations! The black player has won!\n");
        break;
      }
    }

    //print the updated board
    printf("\n   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
      printf("%d ", i);
      for (int j = 0; j < 8; j++) {
        printf("%c ", board[i][j]);
      }
      printf("%d\n", i);
    }
    printf("   0 1 2 3 4 5 6 7\n");
  }

  return 0;
}