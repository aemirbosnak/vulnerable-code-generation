//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A Sudoku puzzle is a 9x9 grid of cells, each containing a digit from 1 to 9.
// The goal of the puzzle is to fill in the grid so that each row, column, and 3x3
// subgrid contains each digit exactly once.

// A Sudoku board is represented as a 9x9 array of integers, where 0 represents an
// empty cell.
int board[9][9];

// A stack is used to keep track of the cells that have been visited during the
// search for a solution.
struct stack {
  int row;
  int col;
  struct stack *next;
};

// Create a new stack.
struct stack *create_stack() {
  struct stack *stack = malloc(sizeof(struct stack));
  stack->row = -1;
  stack->col = -1;
  stack->next = NULL;
  return stack;
}

// Push a cell onto the stack.
void push(struct stack **stack, int row, int col) {
  struct stack *new_cell = malloc(sizeof(struct stack));
  new_cell->row = row;
  new_cell->col = col;
  new_cell->next = *stack;
  *stack = new_cell;
}

// Pop a cell from the stack.
void pop(struct stack **stack) {
  if (*stack == NULL) {
    return;
  }
  struct stack *temp = *stack;
  *stack = (*stack)->next;
  free(temp);
}

// Check if a cell is safe to fill in.
int is_safe(int row, int col, int num) {
  // Check if the number is already present in the row.
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      return 0;
    }
  }

  // Check if the number is already present in the column.
  for (int j = 0; j < 9; j++) {
    if (board[j][col] == num) {
      return 0;
    }
  }

  // Check if the number is already present in the 3x3 subgrid.
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }

  // If the number is not present in the row, column, or subgrid, then it is safe
  // to fill in.
  return 1;
}

// Solve the Sudoku puzzle using a backtracking algorithm.
int solve_sudoku() {
  // Create a stack to keep track of the cells that have been visited.
  struct stack *stack = create_stack();

  // Find the first empty cell.
  int row = -1;
  int col = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        row = i;
        col = j;
        break;
      }
    }
  }

  // If there are no empty cells, then the puzzle has been solved.
  if (row == -1) {
    return 1;
  }

  // Try all possible numbers for the empty cell.
  for (int num = 1; num <= 9; num++) {
    // Check if the number is safe to fill in.
    if (is_safe(row, col, num)) {
      // Fill in the number.
      board[row][col] = num;

      // Push the cell onto the stack.
      push(&stack, row, col);

      // Solve the rest of the puzzle.
      if (solve_sudoku()) {
        return 1;
      }

      // If the rest of the puzzle could not be solved, then pop the cell from the
      // stack and try the next number.
      pop(&stack);
      board[row][col] = 0;
    }
  }

  // If none of the numbers are safe to fill in, then the puzzle cannot be solved.
  return 0;
}

// Print the Sudoku board.
void print_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Read a Sudoku puzzle from a file.
int read_puzzle(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return 0;
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      fscanf(file, "%d ", &board[i][j]);
    }
  }

  fclose(file);
  return 1;
}

// Main function.
int main() {
  // Read the puzzle from a file.
  if (!read_puzzle("puzzle.txt")) {
    printf("Error reading puzzle from file.\n");
    return 1;
  }

  // Solve the puzzle.
  if (!solve_sudoku()) {
    printf("Puzzle could not be solved.\n");
    return 1;
  }

  // Print the solved puzzle.
  printf("Solved puzzle:\n");
  print_board();

  return 0;
}