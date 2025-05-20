//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

// Struct to represent a cell in the percolation system
typedef struct {
  int state;
} cell_t;

// Struct to represent a percolation system
typedef struct {
  cell_t cells[NUM_ROWS][NUM_COLS];
} percolation_t;

// Function to initialize a percolation system
void init_percolation(percolation_t *perc) {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      perc->cells[i][j].state = 0;
    }
  }
}

// Function to randomly assign states to cells in a percolation system
void random_assign_states(percolation_t *perc) {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      perc->cells[i][j].state = rand() % 2;
    }
  }
}

// Function to print the state of a cell in a percolation system
void print_cell_state(cell_t cell) {
  if (cell.state == 0) {
    printf("X");
  } else {
    printf("O");
  }
}

// Function to print the state of a percolation system
void print_percolation(percolation_t *perc) {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      print_cell_state(perc->cells[i][j]);
    }
    printf("\n");
  }
}

// Function to simulate the percolation process
void percolate(percolation_t *perc) {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      if (perc->cells[i][j].state == 0) {
        perc->cells[i][j].state = 1;
        if (i == 0 || i == NUM_ROWS - 1) {
          // If the cell is in the top or bottom row,
          // it is connected to the top or bottom row
          perc->cells[i - 1][j].state = 1;
          perc->cells[i + 1][j].state = 1;
        }
        if (j == 0 || j == NUM_COLS - 1) {
          // If the cell is in the left or right column,
          // it is connected to the left or right column
          perc->cells[i][j - 1].state = 1;
          perc->cells[i][j + 1].state = 1;
        }
      }
    }
  }
}

// Function to check if the percolation system is percolated
int is_percolated(percolation_t *perc) {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      if (perc->cells[i][j].state == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  percolation_t perc;
  init_percolation(&perc);
  random_assign_states(&perc);
  print_percolation(&perc);
  percolate(&perc);
  print_percolation(&perc);
  printf("Is percolated: %d\n", is_percolated(&perc));
  return 0;
}