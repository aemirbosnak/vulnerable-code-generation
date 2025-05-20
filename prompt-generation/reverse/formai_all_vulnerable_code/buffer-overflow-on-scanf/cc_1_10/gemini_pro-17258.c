//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

typedef struct {
  int value;
  int revealed;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];
int num_revealed;

void init_board() {
  int i, j;
  int values[NUM_PAIRS];
  for (i = 0; i < NUM_PAIRS; i++) {
    values[i] = i;
  }
  for (i = 0; i < NUM_PAIRS; i++) {
    int r1 = rand() % NUM_PAIRS;
    int r2 = rand() % NUM_PAIRS;
    int tmp = values[r1];
    values[r1] = values[r2];
    values[r2] = tmp;
  }
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board[i][j].value = values[i * BOARD_SIZE + j];
      board[i][j].revealed = 0;
    }
  }
  num_revealed = 0;
}

void print_board() {
  int i, j;
  printf("  ");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%2d", i);
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].revealed) {
        printf(" %2d", board[i][j].value);
      } else {
        printf("  .");
      }
    }
    printf("\n");
  }
}

int get_tile(int x, int y) {
  if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
    return -1;
  }
  return board[x][y].value;
}

int reveal_tile(int x, int y) {
  if (board[x][y].revealed) {
    return 0;
  }
  board[x][y].revealed = 1;
  num_revealed++;
  return board[x][y].value;
}

int check_for_match(int x1, int y1, int x2, int y2) {
  if (get_tile(x1, y1) == get_tile(x2, y2)) {
    return 1;
  }
  return 0;
}

int game_over() {
  return num_revealed == BOARD_SIZE * BOARD_SIZE;
}

int main() {
  int x1, y1, x2, y2;
  int matched;
  srand(time(NULL));
  init_board();
  print_board();
  while (!game_over()) {
    printf("Enter the coordinates of the first tile (x, y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second tile (x, y): ");
    scanf("%d %d", &x2, &y2);
    reveal_tile(x1, y1);
    reveal_tile(x2, y2);
    print_board();
    matched = check_for_match(x1, y1, x2, y2);
    if (matched) {
      printf("Match!\n");
    } else {
      printf("No match.\n");
    }
  }
  printf("Game over!\n");
  return 0;
}