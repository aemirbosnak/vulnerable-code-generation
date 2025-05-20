//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of terms in the Fibonacci sequence
#define MAX_TERMS 100

// Define the golden ratio
#define GOLDEN_RATIO (1 + sqrt(5)) / 2

// Define the Fibonacci sequence
int fibonacci_sequence[MAX_TERMS];

// Initialize the Fibonacci sequence
void initialize_fibonacci_sequence() {
  fibonacci_sequence[0] = 0;
  fibonacci_sequence[1] = 1;
  for (int i = 2; i < MAX_TERMS; i++) {
    fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
  }
}

// Print the Fibonacci sequence
void print_fibonacci_sequence() {
  printf("Fibonacci sequence:\n");
  for (int i = 0; i < MAX_TERMS; i++) {
    printf("%d ", fibonacci_sequence[i]);
  }
  printf("\n");
}

// Calculate the golden ratio
double calculate_golden_ratio() {
  return (double)(fibonacci_sequence[MAX_TERMS - 1]) / (double)(fibonacci_sequence[MAX_TERMS - 2]);
}

// Visualize the Fibonacci sequence
void visualize_fibonacci_sequence() {
  // Get the maximum value in the Fibonacci sequence
  int max_value = fibonacci_sequence[MAX_TERMS - 1];

  // Print the Fibonacci sequence as a histogram
  for (int i = 0; i < MAX_TERMS; i++) {
    // Calculate the height of the bar
    int height = (int)round((double)fibonacci_sequence[i] / (double)max_value * 100);

    // Print the bar
    for (int j = 0; j < height; j++) {
      printf("#");
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the Fibonacci sequence
  initialize_fibonacci_sequence();

  // Print the Fibonacci sequence
  print_fibonacci_sequence();

  // Calculate the golden ratio
  double golden_ratio = calculate_golden_ratio();
  printf("Golden ratio: %.10f\n", golden_ratio);

  // Visualize the Fibonacci sequence
  visualize_fibonacci_sequence();

  return 0;
}