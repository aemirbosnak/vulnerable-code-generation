//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// The size of the Sudoku board
#define N 9

// The number of squares in a Sudoku board
#define N2 N * N

// The number of boxes in a Sudoku board
#define N3 N / 3

// The Sudoku board
int board[N2];

// The possible values for each square
int possibilities[N2][N];

// The number of possible values for each square
int num_possibilities[N2];

// The number of squares that have been solved
int solved;

// The stack of squares that have been solved
int stack[N2];

// The top of the stack
int stack_top;

// Function to print the Sudoku board
void print_board() {
  for (int i = 0; i < N2; i++) {
    if (i % N == 0) {
      printf("\n");
    }
    printf("%d ", board[i]);
  }
  printf("\n");
}

// Function to check if a square is valid
int is_valid(int square) {
  // Check if the square is in the same row as any other square with the same value
  for (int i = 0; i < N; i++) {
    if (i != square % N && board[i] == board[square]) {
      return 0;
    }
  }

  // Check if the square is in the same column as any other square with the same value
  for (int i = 0; i < N2; i += N) {
    if (i / N != square / N && board[i] == board[square]) {
      return 0;
    }
  }

  // Check if the square is in the same box as any other square with the same value
  int box_row = square / N3;
  int box_col = square % N3;
  for (int i = box_row * N3; i < box_row * N3 + N3; i++) {
    for (int j = box_col * N3; j < box_col * N3 + N3; j++) {
      if (i != square && j != square && board[i] == board[square]) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to solve the Sudoku board
int solve() {
  // If all squares have been solved, the board is solved
  if (solved == N2) {
    return 1;
  }

  // Find the square with the fewest possible values
  int min_possibilities = N;
  int min_square = -1;
  for (int i = 0; i < N2; i++) {
    if (board[i] == 0 && num_possibilities[i] < min_possibilities) {
      min_possibilities = num_possibilities[i];
      min_square = i;
    }
  }

  // If there are no squares with possible values, the board is unsolvable
  if (min_possibilities == N) {
    return 0;
  }

  // Push the square onto the stack
  stack[stack_top++] = min_square;

  // Try each of the possible values for the square
  for (int i = 0; i < N; i++) {
    if (possibilities[min_square][i]) {
      // Set the square to the possible value
      board[min_square] = i + 1;

      // If the square is valid, solve the rest of the board
      if (is_valid(min_square)) {
        if (solve()) {
          return 1;
        }
      }

      // If the square is not valid, reset the square to 0
      board[min_square] = 0;
    }
  }

  // Pop the square off the stack
  stack_top--;

  // Return 0 to indicate that the board is unsolvable
  return 0;
}

// Function to read the Sudoku board from a file
int read_board(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return 0;
  }

  for (int i = 0; i < N2; i++) {
    fscanf(file, "%d", &board[i]);
  }

  fclose(file);

  return 1;
}

// Function to initialize the possible values for each square
void initialize_possibilities() {
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N; j++) {
      possibilities[i][j] = 1;
    }
  }
}

// Function to initialize the number of possible values for each square
void initialize_num_possibilities() {
  for (int i = 0; i < N2; i++) {
    num_possibilities[i] = N;
  }
}

// Function to main
int main(int argc, char *argv[]) {
  // Check if the user specified a filename
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  // Read the Sudoku board from the file
  if (!read_board(argv[1])) {
    printf("Error reading Sudoku board from file\n");
    return 1;
  }

  // Initialize the possible values for each square
  initialize_possibilities();

  // Initialize the number of possible values for each square
  initialize_num_possibilities();

  // Solve the Sudoku board
  if (solve()) {
    printf("The Sudoku board has been solved:\n");
    print_board();
  } else {
    printf("The Sudoku board could not be solved\n");
  }

  return 0;
}