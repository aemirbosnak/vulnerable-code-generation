//GEMINI-pro DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int n) {
  if (n == 2) {
    return 1;
  }
  if (n % 2 == 0 || n <= 1) {
    return 0;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to print all prime numbers up to a given number
void print_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

// Function to check if a number is perfect
int is_perfect(int n) {
  int sum = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;
      if (n / i != i) {
        sum += n / i;
      }
    }
  }
  return sum == n;
}

// Function to print all perfect numbers up to a given number
void print_perfect_numbers(int n) {
  for (int i = 1; i <= n; i++) {
    if (is_perfect(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

// Function to check if a number is amicable
int is_amicable(int a, int b) {
  int sum_a = 0;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      sum_a += i;
      if (a / i != i) {
        sum_a += a / i;
      }
    }
  }
  int sum_b = 0;
  for (int i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      sum_b += i;
      if (b / i != i) {
        sum_b += b / i;
      }
    }
  }
  return sum_a == b && sum_b == a;
}

// Function to print all amicable pairs up to a given number
void print_amicable_pairs(int n) {
  for (int a = 1; a <= n; a++) {
    for (int b = a + 1; b <= n; b++) {
      if (is_amicable(a, b)) {
        printf("(%d, %d) ", a, b);
      }
    }
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Prime numbers up to %d:\n", n);
  print_primes(n);
  printf("Perfect numbers up to %d:\n", n);
  print_perfect_numbers(n);
  printf("Amicable pairs up to %d:\n", n);
  print_amicable_pairs(n);
  return 0;
}