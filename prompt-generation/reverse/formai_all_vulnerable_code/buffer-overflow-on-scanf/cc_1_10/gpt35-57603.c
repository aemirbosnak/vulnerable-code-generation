//FormAI DATASET v1.0 Category: Memory Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CHAR_LIMIT 100

// function prototypes
void init_board(char board[ROWS][COLS]);
void display_board(char board[ROWS][COLS]);
void shuffle_board(char board[ROWS][COLS]);
void game_loop(char board[ROWS][COLS], int *score);
void game_over(int score);

int main() {
  char board[ROWS][COLS];
  int score = 0;
  srand(time(NULL)); // seed the random number generator
  init_board(board);
  shuffle_board(board);
  display_board(board);
  game_loop(board, &score);
  game_over(score);
  return 0;
}

void init_board(char board[ROWS][COLS]) {
  // fill the board with random characters
  char characters[CHAR_LIMIT] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int i, j, index = 0;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      board[i][j] = characters[index];
      index = (index + 1) % CHAR_LIMIT;
    }
  }
}

void display_board(char board[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

void shuffle_board(char board[ROWS][COLS]) {
  int i, j, row1, col1, row2, col2;
  char temp;
  for (i = 0; i < ROWS*COLS; i++) {
    // randomly swap two tiles
    row1 = rand() % ROWS;
    col1 = rand() % COLS;
    row2 = rand() % ROWS;
    col2 = rand() % COLS;
    temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
  }
}

void game_loop(char board[ROWS][COLS], int *score) {
  int i, j, row1, col1, row2, col2, valid_move;
  char guess1, guess2;
  do {
    valid_move = 0;
    printf("Enter first tile: ");
    scanf("%d %d", &row1, &col1);
    guess1 = board[row1][col1];
    printf("Enter second tile: ");
    scanf("%d %d", &row2, &col2);
    guess2 = board[row2][col2];
    if (guess1 == guess2) {
      // correct guess
      *score += 10;
      board[row1][col1] = ' ';
      board[row2][col2] = ' ';
      valid_move = 1;
    } else {
      // incorrect guess
      *score -= 5;
      display_board(board);
    }
  } while (!valid_move && *score >= 0);
}

void game_over(int score) {
  if (score >= 0) {
    printf("Congratulations! You won with a score of %d.\n", score);
  } else {
    printf("Game over. You ran out of points.\n");
  }
}