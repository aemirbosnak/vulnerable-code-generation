//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A simple function to measure the time taken by a function
#define BENCHMARK(func)                                   \
  {                                                       \
    clock_t start = clock();                              \
    func();                                              \
    clock_t end = clock();                                \
    printf("Time taken by %s: %lf\n", #func,              \
           (double)(end - start) / CLOCKS_PER_SEC);        \
  }

// A function that does nothing
void doNothing() {}

// A function that performs a simple calculation
void doCalculation() {
  int sum = 0;
  for (int i = 0; i < 1000000; i++) {
    sum += i;
  }
}

// A function that performs a complex calculation
void doComplexCalculation() {
  int sum = 0;
  for (int i = 0; i < 1000000; i++) {
    for (int j = 0; j < 1000000; j++) {
      sum += i * j;
    }
  }
}

// A function that performs a string operation
void doStringOperation() {
  char str[] = "Hello, world!";
  for (int i = 0; i < 100000; i++) {
    str[i] = '\0';
  }
}

int main() {
  // Benchmark the different functions
  BENCHMARK(doNothing);
  BENCHMARK(doCalculation);
  BENCHMARK(doComplexCalculation);
  BENCHMARK(doStringOperation);

  return 0;
}