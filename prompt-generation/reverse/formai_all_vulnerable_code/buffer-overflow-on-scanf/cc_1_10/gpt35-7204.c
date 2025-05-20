//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[][4], int size) {
  int i, j;
  printf("\n");
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

void reset_board(char board[][4], int size) {
  int i, j;
  char ch = 'A';
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      board[i][j] = ch++;
      if (ch == 'S') ch++;
    }
  }
}

void shuffle_board(char board[][4], int size) {
  srand(time(NULL));
  int i, j, ii, jj;
  char temp;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      ii = rand() % size;
      jj = rand() % size;
      temp = board[i][j];
      board[i][j] = board[ii][jj];
      board[ii][jj] = temp;
    }
  }
}

int main() {
  char board[4][4];
  int size = 4;
  int row1, col1, row2, col2;
  reset_board(board, size);
  shuffle_board(board, size);
  print_board(board, size);

  while (1) {
    printf("Enter cell 1 (row col): ");
    scanf("%d %d", &row1, &col1);
    printf("\n");

    printf("Enter cell 2 (row col): ");
    scanf("%d %d", &row2, &col2);
    printf("\n");

    if ((row1 < 0 || row1 >= size) || (col1 < 0 || col1 >= size)
        || (row2 < 0 || row2 >= size) || (col2 < 0 || col2 >= size)) {
      printf("Invalid input. Try again.\n");
      continue;
    }

    if (board[row1][col1] == board[row2][col2]) {
      printf("Found a match!\n");
      board[row1][col1] = ' ';
      board[row2][col2] = ' ';
      print_board(board, size);
    } else {
      printf("No match. Try again.\n");
      print_board(board, size);
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 0) {
        printf("Congratulations! You have won the game!\n");
        break;
    }
  }
  return 0;
}