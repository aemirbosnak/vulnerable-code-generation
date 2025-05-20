//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

// function to calculate factorial
int factorial(int n) {
  int result = 1;
  for(int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// function to calculate fibonacci series
void fibonacci(int n) {
  int first = 0, second = 1, next;
  for(int i = 0; i <= n; i++) {
    if(i <= 1) {
      next = i;
    } else {
      next = first + second;
      first = second;
      second = next;
    }
    printf("%d ", next);
  }
}

// function to find prime numbers
int isPrime(int n) {
  if(n == 2 || n == 3) {
    return 1;
  }
  if(n == 1 || n % 2 == 0) {
    return 0;
  }
  for(int i = 3; i * i <= n; i += 2) {
    if(n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int option, n, result, prime;
  do {
    // display menu
    printf("\n\n");
    printf("***************************************\n");
    printf("*           EDUCATIONAL MENU           *\n");
    printf("***************************************\n");
    printf("* 1. Calculate Factorial               *\n");
    printf("* 2. Generate Fibonacci Series         *\n");
    printf("* 3. Check if a Number is Prime        *\n");
    printf("* 4. Exit                              *\n");
    printf("***************************************\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("\nEnter a number: ");
        scanf("%d", &n);
        result = factorial(n);
        printf("Factorial of %d is %d\n", n, result);
        break;

      case 2:
        printf("\nEnter number of terms: ");
        scanf("%d", &n);
        fibonacci(n);
        break;

      case 3:
        printf("\nEnter a number: ");
        scanf("%d", &n);
        prime = isPrime(n);
        if(prime) {
          printf("%d is a prime number\n", n);
        } else {
          printf("%d is not a prime number\n", n);
        }
        break;

      case 4:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid option! Please enter a valid option.\n");
    }
  } while (option != 4);
  return 0;
}