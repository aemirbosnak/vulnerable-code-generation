//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
  int value;
  int revealed;
} cell;

cell board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
  int values[] = {1, 1, 2, 2, 3, 3, 4, 4};
  int i, j, k;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      k = rand() % 8;
      board[i][j].value = values[k];
      board[i][j].revealed = 0;
    }
  }
}

void print_board() {
  int i, j;

  printf("  ");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n");

  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i + 1);
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].revealed) {
        printf("%2d ", board[i][j].value);
      } else {
        printf("## ");
      }
    }
    printf("\n");
  }
}

int get_input() {
  int input;

  while (1) {
    printf("Enter row and column (e.g. 1 2): ");
    scanf("%d %d", &input, &input);

    if (input >= 1 && input <= BOARD_SIZE) {
      return input - 1;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }
}

int main() {
  int i, j, count = 0, pairs = 0;
  int first_row, first_col, second_row, second_col;

  srand(time(NULL));

  init_board();

  while (pairs < 8) {
    print_board();

    printf("Player %d:\n", count % 2 + 1);

    first_row = get_input();
    first_col = get_input();

    board[first_row][first_col].revealed = 1;

    print_board();

    second_row = get_input();
    second_col = get_input();

    board[second_row][second_col].revealed = 1;

    if (board[first_row][first_col].value == board[second_row][second_col].value) {
      pairs++;
      printf("Match!\n");
    } else {
      printf("No match.\n");
      board[first_row][first_col].revealed = 0;
      board[second_row][second_col].revealed = 0;
    }

    count++;
  }

  print_board();

  printf("Congratulations! You won in %d moves.\n", count);

  return 0;
}