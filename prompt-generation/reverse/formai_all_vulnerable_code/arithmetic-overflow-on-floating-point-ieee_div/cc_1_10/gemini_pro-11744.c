//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the function prototypes
double avg_time(struct timespec, struct timespec, int);
void *alloc_matrix(int, int);
void benchmark(int, int);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <matrix_size> <iterations>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int matrix_size = atoi(argv[1]);
  int iterations = atoi(argv[2]);

  printf("Performing benchmark with matrix size: %d and iterations: %d\n", 
matrix_size, iterations);

  benchmark(matrix_size, iterations);

  return EXIT_SUCCESS;
}

double avg_time(struct timespec start, struct timespec end, int iterations) {
  double time_elapsed = (end.tv_sec - start.tv_sec) + 
(end.tv_nsec - start.tv_nsec) / 1000000000.0;
  return time_elapsed / iterations;
}

void *alloc_matrix(int rows, int cols) {
  void *matrix = malloc(rows * cols * sizeof(int));
  if (matrix == NULL) {
    fprintf(stderr, "Error allocating memory for matrix.\n");
    exit(EXIT_FAILURE);
  }
  return matrix;
}

void benchmark(int matrix_size, int iterations) {

  double total_time;
  struct timespec start, end;
  int i, j, k;

  // Allocate the matrices
  int *a = alloc_matrix(matrix_size, matrix_size);
  int *b = alloc_matrix(matrix_size, matrix_size);
  int *c = alloc_matrix(matrix_size, matrix_size);

  // Initialize the matrices
  for (i = 0; i < matrix_size; i++) {
    for (j = 0; j < matrix_size; j++) {
      a[i * matrix_size + j] = rand() % 100;
      b[i * matrix_size + j] = rand() % 100;
      c[i * matrix_size + j] = 0;
    }
  }

  // Start the timer
  clock_gettime(CLOCK_MONOTONIC, &start);

  // Perform the matrix multiplication
  for (i = 0; i < iterations; i++) {
    for (i = 0; i < matrix_size; i++) {
      for (j = 0; j < matrix_size; j++) {
        for (k = 0; k < matrix_size; k++) {
          c[i * matrix_size + j] += a[i * matrix_size + k] * 
b[k * matrix_size + j];
        }
      }
    }
  }

  // Stop the timer
  clock_gettime(CLOCK_MONOTONIC, &end);

  // Calculate the average time per iteration
  total_time = avg_time(start, end, iterations);

  // Print the benchmark results
  printf("Average time per iteration: %.9lf seconds\n", total_time);

  // Free the matrices
  free(a);
  free(b);
  free(c);
}