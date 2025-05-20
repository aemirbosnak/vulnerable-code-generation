//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

int factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else {
    return base * power(base, exponent - 1);
  }
}

int fibonacci(int num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else {
    return fibonacci(num - 1) + fibonacci(num - 2);
  }
}

int main() {
  int choice, num;
  printf("Greetings human! I am a curious recursive chatbot. How may I assist you?\n");
  do {
    printf("\nChoose an option:\n");
    printf("1. Calculate factorial\n");
    printf("2. Raise to power\n");
    printf("3. Find nth Fibonacci number\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter a non-negative integer: ");
        scanf("%d", &num);
        printf("Factorial of %d is %d", num, factorial(num));
        break;
      case 2:
        printf("Enter the base: ");
        scanf("%d", &num);
        printf("Enter the exponent: ");
        int exponent;
        scanf("%d", &exponent);
        printf("%d raised to the power of %d is %d", num, exponent, power(num, exponent));
        break;
      case 3:
        printf("Enter the value of n in the Fibonacci sequence: ");
        scanf("%d", &num);
        printf("The %dth number in the Fibonacci sequence is %d", num, fibonacci(num));
        break;
      case 4:
        printf("Farewell, human. I enjoyed our chat.\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
    }
  } while (choice != 4);
  
  return 0;
}