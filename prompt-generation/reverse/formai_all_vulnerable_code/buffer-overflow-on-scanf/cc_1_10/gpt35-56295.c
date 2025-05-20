//FormAI DATASET v1.0 Category: Table Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 60

void initialize_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE], int current_move);
int is_valid_move(int board[][BOARD_SIZE], int move, int row, int col);
void get_computer_move(int board[][BOARD_SIZE], int *row, int *col);
void get_player_move(int board[][BOARD_SIZE], int *row, int *col);

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  int row, col, move, current_move = 1;

  srand(time(NULL));

  initialize_board(board);

  while (current_move <= MAX_MOVES) {
    print_board(board, current_move);

    if (current_move % 2 == 1) {
      printf("Player's move (move %d)\n", current_move);
      get_player_move(board, &row, &col);

      if (is_valid_move(board, current_move, row, col)) {
        board[row][col] = current_move;
        current_move++;
      } else {
        printf("Invalid move. Try again.\n");
      }
    } else {
      printf("Computer's move (move %d)\n", current_move);
      get_computer_move(board, &row, &col);

      board[row][col] = current_move;
      current_move++;
    }
  }

  print_board(board, current_move);
  printf("No more moves. Game over.\n");

  return 0;
}

void initialize_board(int board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void print_board(int board[][BOARD_SIZE], int current_move) {
  printf("Current board (move %d):\n", current_move);

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("|%3d", board[i][j]);
    }
    printf("|\n");
  }
  printf("+---+---+---+---+---+---+---+---+\n");
}

int is_valid_move(int board[][BOARD_SIZE], int move, int row, int col) {
  if (row < 0 || row > BOARD_SIZE - 1 || col < 0 || col > BOARD_SIZE - 1) {
    return 0;
  }

  if (board[row][col] != 0) {
    return 0;
  }

  if (move % 2 == 1) {
    if ((row + col) % 2 != 0) {
      return 0;
    }
  } else {
    if ((row + col) % 2 == 0) {
      return 0;
    }
  }

  return 1;
}

void get_computer_move(int board[][BOARD_SIZE], int *row, int *col) {
  int valid_move = 0;

  while (!valid_move) {
    *row = rand() % BOARD_SIZE;
    *col = rand() % BOARD_SIZE;

    if (is_valid_move(board, 0, *row, *col)) {
      valid_move = 1;
    }
  }

  printf("Computer moved to row %d, col %d\n", *row, *col);
}

void get_player_move(int board[][BOARD_SIZE], int *row, int *col) {
  printf("Enter row: ");
  scanf("%d", row);

  printf("Enter column: ");
  scanf("%d", col);
}