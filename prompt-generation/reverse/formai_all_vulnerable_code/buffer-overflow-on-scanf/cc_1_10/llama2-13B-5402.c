//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOD 1000003

// Function to compute Fibonacci sequence
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  int a = 1, b = 1, res = 0;
  for (int i = 2; i <= n; i++) {
    res = (a + b) % MOD;
    a = b;
    b = res;
  }
  return res;
}

// Function to compute factorial
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  int res = n * factorial(n-1);
  return res % MOD;
}

// Function to compute binomial coefficient
int binomial(int n, int k) {
  if (n == 0 || k == 0) {
    return 1;
  }
  int res = 0;
  for (int i = 0; i < k; i++) {
    res = (res * (n - i)) % MOD;
  }
  return res;
}

int main() {
  int n, k, sum = 0;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Enter a number: ");
  scanf("%d", &k);

  // Compute Fibonacci sequence
  for (int i = 0; i <= n; i++) {
    sum = (sum + fibonacci(i)) % MOD;
  }

  // Compute factorial
  for (int i = 0; i <= n; i++) {
    sum = (sum + factorial(i)) % MOD;
  }

  // Compute binomial coefficient
  for (int i = 0; i < k; i++) {
    sum = (sum + binomial(n, i)) % MOD;
  }

  printf("Result: %d\n", sum);
  return 0;
}