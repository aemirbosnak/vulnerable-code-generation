//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
// Cyberpunk Bingo Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define MAX_BINGO 25

typedef struct {
  int row;
  int col;
  int value;
} Cell;

void print_board(Cell board[NUM_ROWS][NUM_COLS]) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%d ", board[i][j].value);
    }
    printf("\n");
  }
}

void generate_random_board(Cell board[NUM_ROWS][NUM_COLS]) {
  srand(time(NULL));
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      board[i][j].value = rand() % MAX_BINGO + 1;
    }
  }
}

void draw_card(Cell board[NUM_ROWS][NUM_COLS], int card[NUM_ROWS][NUM_COLS]) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      card[i][j] = board[i][j].value;
    }
  }
}

void check_bingo(int card[NUM_ROWS][NUM_COLS]) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (card[i][j] == 0) {
        printf("You have bingo!\n");
        return;
      }
    }
  }
}

int main() {
  Cell board[NUM_ROWS][NUM_COLS];
  generate_random_board(board);

  int card[NUM_ROWS][NUM_COLS];
  draw_card(board, card);

  print_board(board);
  print_board(card);

  check_bingo(card);

  return 0;
}