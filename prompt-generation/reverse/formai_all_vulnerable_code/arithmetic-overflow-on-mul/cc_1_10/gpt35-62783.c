//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>

// A function that adds two numbers and returns the result
int add(int a, int b) {
  return a + b;
}

// A function that multiples two numbers and returns the result
int multiply(int a, int b) {
  return a * b;
}

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // The user can choose to add or multiply the two numbers
  char operation;
  printf("Do you want to add or multiply the two numbers? (a/m): ");
  scanf(" %c", &operation);
  
  int result;
  if (operation == 'a') {
    result = add(num1, num2);
  } else if (operation == 'm') {
    result = multiply(num1, num2);
  } else {
    printf("Invalid operation entered.\n");
    return 1;
  }

  // The program outputs the result, but only if it's a prime number
  printf("The result is: %d\n", result);
  int isPrime = 1;
  for (int i = 2; i <= result / 2; i++) {
    if (result % i == 0) {
      isPrime = 0;
      break;
    }
  }
  
  if (isPrime) {
    printf("Congratulations! You got a prime number!\n");
  } else {
    printf("Sorry, the result is not a prime number.\n");
  }

  return 0;
}