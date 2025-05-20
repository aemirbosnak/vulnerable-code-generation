//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n <= 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the first n Fibonacci numbers
void printFibonacci(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
}

// Function to visualize the first n Fibonacci numbers using a bar chart
void visualizeFibonacci(int n) {
  // Calculate the maximum Fibonacci number to determine the scale of the bar chart
  int maxFibonacci = fibonacci(n - 1);

  // Create a 2D array to represent the bar chart
  int **barChart = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    barChart[i] = (int *)malloc(maxFibonacci * sizeof(int));
  }

  // Initialize the bar chart with zeros
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < maxFibonacci; j++) {
      barChart[i][j] = 0;
    }
  }

  // Fill the bar chart with asterisks to represent the Fibonacci numbers
  for (int i = 0; i < n; i++) {
    int fibonacciNumber = fibonacci(i);
    for (int j = 0; j < fibonacciNumber; j++) {
      barChart[i][j] = '*';
    }
  }

  // Print the bar chart
  for (int i = 0; i < maxFibonacci; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", barChart[j][i]);
    }
    printf("\n");
  }

  // Free the memory allocated for the bar chart
  for (int i = 0; i < n; i++) {
    free(barChart[i]);
  }
  free(barChart);
}

int main() {
  int n;

  // Get the number of Fibonacci numbers to print from the user
  printf("Enter the number of Fibonacci numbers to print: ");
  scanf("%d", &n);

  // Print the first n Fibonacci numbers
  printf("The first %d Fibonacci numbers are: ", n);
  printFibonacci(n);
  printf("\n");

  // Visualize the first n Fibonacci numbers using a bar chart
  printf("Visual representation of the first %d Fibonacci numbers:\n", n);
  visualizeFibonacci(n);

  return 0;
}