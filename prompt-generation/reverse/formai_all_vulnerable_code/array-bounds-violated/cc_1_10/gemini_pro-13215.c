//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare and initialize variables
  int n, i, j, k, l;
  int fib[100];
  fib[0] = 0;
  fib[1] = 1;

  // Get the number of Fibonacci numbers to generate
  printf("How many Fibonacci numbers would thou like to generate, fair maiden?\n");
  scanf("%d", &n);

  // Generate the Fibonacci numbers
  for (i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // Print the Fibonacci numbers in a medieval style
  printf("Hark! The Fibonacci Sequence, in all its glory:\n");
  for (j = 0; j < n; j++) {
    if (fib[j] < 10) {
      printf("  %d", fib[j]);
    } else if (fib[j] < 100) {
      printf(" %d", fib[j]);
    } else {
      printf("%d", fib[j]);
    }
  }

  printf("\n");

  // Calculate the sum of the Fibonacci numbers
  int sum = 0;
  for (k = 0; k < n; k++) {
    sum += fib[k];
  }

  // Print the sum of the Fibonacci numbers
  printf("The sum of the first %d Fibonacci numbers is %d.\n", n, sum);

  // Print a newline for formatting
  printf("\n");

  // Calculate the average of the Fibonacci numbers
  float avg = (float)sum / n;

  // Print the average of the Fibonacci numbers
  printf("The average of the first %d Fibonacci numbers is %.2f.\n", n, avg);

  // Print a newline for formatting
  printf("\n");

  // Calculate the median of the Fibonacci numbers
  int median;
  if (n % 2 == 0) {
    median = (fib[n / 2] + fib[n / 2 - 1]) / 2;
  } else {
    median = fib[n / 2];
  }

  // Print the median of the Fibonacci numbers
  printf("The median of the first %d Fibonacci numbers is %d.\n", n, median);

  // Print a newline for formatting
  printf("\n");

  // Calculate the mode of the Fibonacci numbers
  int mode = fib[0];
  int count = 1;
  int maxCount = 1;
  for (l = 1; l < n; l++) {
    if (fib[l] == fib[l - 1]) {
      count++;
    } else {
      if (count > maxCount) {
        maxCount = count;
        mode = fib[l - 1];
      }
      count = 1;
    }
  }

  // Print the mode of the Fibonacci numbers
  printf("The mode of the first %d Fibonacci numbers is %d.\n", n, mode);

  return 0;
}