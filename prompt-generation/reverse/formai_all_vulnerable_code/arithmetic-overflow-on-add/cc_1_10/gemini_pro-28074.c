//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to generate.
#define MAX_FIB 100

// Define the colors used for the Fibonacci sequence.
#define COLOR_0 "\x1b[31m" // Red
#define COLOR_1 "\x1b[32m" // Green
#define COLOR_2 "\x1b[33m" // Yellow
#define COLOR_3 "\x1b[34m" // Blue
#define COLOR_4 "\x1b[35m" // Magenta
#define COLOR_5 "\x1b[36m" // Cyan
#define COLOR_6 "\x1b[37m" // White
#define COLOR_RESET "\x1b[0m" // Reset color

// Define the main function.
int main() {
  // Declare the Fibonacci sequence.
  int fib[MAX_FIB];

  // Initialize the first two Fibonacci numbers.
  fib[0] = 0;
  fib[1] = 1;

  // Generate the remaining Fibonacci numbers.
  for (int i = 2; i < MAX_FIB; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // Print the Fibonacci sequence.
  for (int i = 0; i < MAX_FIB; i++) {
    // Choose a color for the Fibonacci number.
    char *color;
    switch (i % 6) {
      case 0:
        color = COLOR_0;
        break;
      case 1:
        color = COLOR_1;
        break;
      case 2:
        color = COLOR_2;
        break;
      case 3:
        color = COLOR_3;
        break;
      case 4:
        color = COLOR_4;
        break;
      case 5:
        color = COLOR_5;
        break;
      default:
        color = COLOR_6;
        break;
    }

    // Print the Fibonacci number.
    printf("%s%d%s ", color, fib[i], COLOR_RESET);
  }

  // Print a newline.
  printf("\n");

  return 0;
}