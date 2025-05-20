//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_ATTEMPTS 10

typedef struct {
  int value;
  int revealed;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
  int values[] = {1, 1, 2, 2, 3, 3, 4, 4};
  int i, j, k;

  srand(time(NULL));

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
    printf("%d ", i + 1);
  }
  printf("\n");

  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].revealed) {
        printf("%d ", board[i][j].value);
      } else {
        printf("X ");
      }
    }
    printf("\n");
  }
}

int get_input() {
  int input;

  printf("Enter the row and column of the tile you want to reveal (e.g. 1 2): ");
  scanf("%d %d", &input, &input);

  return input;
}

int check_match(int row1, int col1, int row2, int col2) {
  return board[row1][col1].value == board[row2][col2].value;
}

int main() {
  int attempts = 0;
  int matches = 0;
  int input1, input2, input3, input4;

  initialize_board();

  while (attempts < MAX_ATTEMPTS && matches < BOARD_SIZE * BOARD_SIZE / 2) {
    print_board();

    printf("Attempt %d: ", attempts + 1);

    input1 = get_input();
    input2 = get_input();

    if (board[input1 - 1][input2 - 1].revealed) {
      printf("You have already revealed that tile.\n");
      continue;
    }

    board[input1 - 1][input2 - 1].revealed = 1;

    print_board();

    input3 = get_input();
    input4 = get_input();

    if (board[input3 - 1][input4 - 1].revealed) {
      printf("You have already revealed that tile.\n");
      continue;
    }

    board[input3 - 1][input4 - 1].revealed = 1;

    if (check_match(input1 - 1, input2 - 1, input3 - 1, input4 - 1)) {
      printf("Match!\n");
      matches += 2;
    } else {
      printf("No match.\n");
    }

    attempts++;
  }

  if (matches == BOARD_SIZE * BOARD_SIZE / 2) {
    printf("Congratulations! You won in %d attempts.\n", attempts);
  } else {
    printf("Game over! You ran out of attempts.\n");
  }

  return 0;
}