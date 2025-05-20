//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int n;
  int i;
  int j;
  int k;
  long long int fib[100];
  char grid[100][100];

  printf("Welcome to the Fibonacci Sequence Visualizer!\n");
  printf("Enter the number of Fibonacci numbers you want to generate (max 100): ");
  scanf("%d", &n);

  // Calculate the Fibonacci sequence
  fib[0] = 0;
  fib[1] = 1;
  for (i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // Create a grid to represent the Fibonacci sequence
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      grid[i][j] = ' ';
    }
  }

  // Fill in the grid with the Fibonacci numbers
  for (i = 0; i < n; i++) {
    for (j = 0; j < fib[i]; j++) {
      grid[i][j] = '*';
    }
  }

  // Print the grid
  printf("\nThe Fibonacci sequence is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  // Calculate the sum of the Fibonacci numbers
  long long int sum = 0;
  for (i = 0; i < n; i++) {
    sum += fib[i];
  }
  
  k = floor(log10(abs(sum))) + 1;
  if (sum == 0) {
    k = 1;
  }
  if (sum < 0) {
    k++;
  }

  // Print the sum of the Fibonacci numbers
  printf("\nThe sum of the Fibonacci numbers is: %lld\n",  sum);
  printf("\nThe number of digits in the sum is: %d\n",  k);

  return 0;
}