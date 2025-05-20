//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Constants for colors
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_WHITE "\033[0;37m"
#define COLOR_RESET "\033[0m"

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to print the Fibonacci sequence in a colorful way
void print_fibonacci(int n) {
  for (int i = 0; i < n; i++) {
    // Choose a random color for each Fibonacci number
    int color = rand() % 7;
    switch (color) {
      case 0:
        printf(COLOR_RED "%d " COLOR_RESET, fibonacci(i));
        break;
      case 1:
        printf(COLOR_GREEN "%d " COLOR_RESET, fibonacci(i));
        break;
      case 2:
        printf(COLOR_YELLOW "%d " COLOR_RESET, fibonacci(i));
        break;
      case 3:
        printf(COLOR_BLUE "%d " COLOR_RESET, fibonacci(i));
        break;
      case 4:
        printf(COLOR_MAGENTA "%d " COLOR_RESET, fibonacci(i));
        break;
      case 5:
        printf(COLOR_CYAN "%d " COLOR_RESET, fibonacci(i));
        break;
      case 6:
        printf(COLOR_WHITE "%d " COLOR_RESET, fibonacci(i));
        break;
    }
  }
  printf("\n");
}

int main() {
  // Get the number of Fibonacci numbers to print from the user
  int n;
  printf("How many Fibonacci numbers do you want to see? ");
  scanf("%d", &n);

  // Print the Fibonacci sequence
  print_fibonacci(n);

  return 0;
}