//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>

// Function to get the modulo of two numbers
int mod(int a, int b) {
  return a % b;
}

int main() {
  printf("Welcome to the Modulo Calculation Program!\n");
  
  int num1, num2, result;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Ensuring that num1 is positive
  if(num1 < 0) {
    printf("Error: Number must be positive.\n");
    return 1;
  }

  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Ensuring that num2 is positive
  if(num2 < 0) {
    printf("Error: Number must be positive.\n");
    return 1;
  }

  // Getting the modulo
  result = mod(num1, num2);
  printf("%d %% %d = %d\n", num1, num2, result);

  // Checking if the result is even or odd
  if(result % 2 == 0) {
    printf("%d is even.\n", result); 
  } else {
    printf("%d is odd.\n", result);
  }

  // Checking if the result is prime
  int prime = 1;
  for(int i=2; i<=result/2; i++) {
    if(result % i == 0) {
      prime = 0;
      break;
    }
  }

  if(prime == 1) {
    printf("%d is prime.\n", result);
  } else {
    printf("%d is not prime.\n", result);
  }

  printf("Thank you for using the Modulo Calculation Program!\n");
  return 0;
}