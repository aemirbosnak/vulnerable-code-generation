//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

typedef struct {
  int row;
  int col;
  int val;
} Cell;

typedef struct {
  Cell cells[N * N];
  int num_cells;
} Board;

void print_board(Board *board) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board->cells[i * N + j].val);
    }
    printf("\n");
  }
}

int is_safe(Board *board, int row, int col, int val) {
  // Check row
  for (int i = 0; i < N; i++) {
    if (board->cells[row * N + i].val == val) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < N; i++) {
    if (board->cells[i * N + col].val == val) {
      return 0;
    }
  }

  // Check subgrid
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (board->cells[i * N + j].val == val) {
        return 0;
      }
    }
  }

  return 1;
}

int solve_sudoku(Board *board, int index) {
  // If we have filled all the cells, we have solved the puzzle
  if (index == board->num_cells) {
    return 1;
  }

  // Get the current cell
  Cell *cell = &board->cells[index];

  // If the cell is already filled, move on to the next cell
  if (cell->val != 0) {
    return solve_sudoku(board, index + 1);
  }

  // Try all possible values for the cell
  for (int i = 1; i <= N; i++) {
    // If the value is safe to place in the cell, place it and move on to the next cell
    if (is_safe(board, cell->row, cell->col, i)) {
      cell->val = i;
      if (solve_sudoku(board, index + 1)) {
        return 1;
      }
      // If the value did not lead to a solution, reset the cell to 0 and try the next value
      cell->val = 0;
    }
  }

  // If no value led to a solution, return 0 to indicate that the puzzle is unsolvable
  return 0;
}

int main() {
  Board board;

  // Read the input puzzle from the user
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d ", &board.cells[i * N + j].val);
      if (board.cells[i * N + j].val != 0) {
        board.num_cells++;
      }
    }
  }

  // Solve the puzzle
  if (solve_sudoku(&board, 0)) {
    // Print the solved puzzle
    print_board(&board);
  } else {
    printf("The puzzle is unsolvable.\n");
  }

  return 0;
}