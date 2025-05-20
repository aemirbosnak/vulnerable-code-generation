//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

typedef struct {
  int value;
  int revealed;
} Cell;

Cell grid[SIZE][SIZE];

void init_grid() {
  int values[SIZE * SIZE] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      int index = rand() % (SIZE * SIZE - i * SIZE - j);
      grid[i][j].value = values[index];
      values[index] = values[SIZE * SIZE - i * SIZE - j - 1];
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i][j].revealed = 0;
    }
  }
}

void print_grid() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (grid[i][j].revealed) {
        printf("%d ", grid[i][j].value);
      } else {
        printf("? ");
      }
    }
    printf("\n");
  }
}

int main() {
  init_grid();
  print_grid();

  int first_x, first_y, second_x, second_y;
  while (1) {
    printf("Enter the coordinates of the first cell (x, y): ");
    scanf("%d %d", &first_x, &first_y);
    if (first_x < 0 || first_x >= SIZE || first_y < 0 || first_y >= SIZE) {
      printf("Invalid coordinates\n");
      continue;
    }
    grid[first_x][first_y].revealed = 1;
    print_grid();

    printf("Enter the coordinates of the second cell (x, y): ");
    scanf("%d %d", &second_x, &second_y);
    if (second_x < 0 || second_x >= SIZE || second_y < 0 || second_y >= SIZE) {
      printf("Invalid coordinates\n");
      continue;
    }
    grid[second_x][second_y].revealed = 1;
    print_grid();

    if (grid[first_x][first_y].value == grid[second_x][second_y].value) {
      printf("Match!\n");
    } else {
      printf("No match\n");
      grid[first_x][first_y].revealed = 0;
      grid[second_x][second_y].revealed = 0;
    }

    int revealed_count = 0;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (grid[i][j].revealed) {
          revealed_count++;
        }
      }
    }
    if (revealed_count == SIZE * SIZE) {
      printf("You win!\n");
      break;
    }
  }

  return 0;
}