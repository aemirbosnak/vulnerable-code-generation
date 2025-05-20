//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 9
#define MAX_THREADS 9

// A global variable to store the solution
int solution[N][N];

// A mutex to protect the global variable
pthread_mutex_t solution_mutex = PTHREAD_MUTEX_INITIALIZER;

// A struct to store the parameters for each thread
typedef struct {
  int row;
  int col;
} thread_params;

// A function to check if a number is safe to place at a given position in the grid
bool is_safe(int grid[N][N], int row, int col, int num) {
  // Check the row
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  // Check the column
  for (int j = 0; j < N; j++) {
    if (grid[j][col] == num) {
      return false;
    }
  }

  // Check the box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
    for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
      if (grid[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

// A function to solve the Sudoku using a backtracking algorithm
void* solve_sudoku(void *args) {
  // Get the parameters for this thread
  thread_params *params = (thread_params *)args;
  int row = params->row;
  int col = params->col;
  free(params);

  // If the current cell is already filled, we can skip it
  if (solution[row][col] != 0) {
    return NULL;
  }

  // Try all possible numbers for this cell
  for (int num = 1; num <= N; num++) {
    // If the number is safe to place, we place it and move on to the next cell
    if (is_safe(solution, row, col, num)) {
      pthread_mutex_lock(&solution_mutex);
      solution[row][col] = num;
      pthread_mutex_unlock(&solution_mutex);

      // Recursively solve the rest of the grid
      int *result = solve_sudoku(NULL);
      if (result != NULL) {
        return result;
      }

      // If the recursive call failed, we backtrack and try the next number
      pthread_mutex_lock(&solution_mutex);
      solution[row][col] = 0;
      pthread_mutex_unlock(&solution_mutex);
    }
  }

  // If we have tried all possible numbers and none of them worked, we return NULL to indicate failure
  return NULL;
}

// A function to print the solution grid
void print_solution() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", solution[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Get the input Sudoku grid from the user
  int grid[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Create a thread for each cell in the grid
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      thread_params *params = malloc(sizeof(thread_params));
      params->row = i;
      params->col = j;
      pthread_create(&threads[i * N + j], NULL, solve_sudoku, (void *)params);
    }
  }

  // Wait for all threads to finish
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the solution grid
  print_solution();

  return 0;
}