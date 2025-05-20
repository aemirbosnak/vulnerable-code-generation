//FormAI DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>

int main() {
  int num1, num2, sum;

  printf("Hello! I am an invasive chatbot. Please enter two integer numbers to add:\n");
  
  scanf("%d%d", &num1, &num2);
  
  sum = num1 + num2;
  
  printf("The sum of %d and %d is %d\n", num1, num2, sum);

  if (sum % 2 == 0) {
    printf("The sum is an even number!\n");
  }
  else {
    printf("The sum is an odd number!\n");
  }

  if (num1 > num2) {
    printf("%d is greater than %d\n", num1, num2);
  }
  else if (num2 > num1) {
    printf("%d is greater than %d\n", num2, num1);
  }
  else {
    printf("The two numbers are equal!\n");
  }

  printf("The factorial of %d is ", num1);
  
  int factorial = 1;
  
  for (int i = num1; i > 0; i--) {
    factorial *= i;
  }

  printf("%d\n", factorial);

  printf("The prime factors of %d are: ", num2);
  
  int i = 2;
  
  while (num2 > 1) {
    if (num2 % i == 0) {
      printf("%d ", i);
      num2 /= i;
    }
    else {
      i++;
    }
  }

  printf("\n");

  if (num1 % 3 == 0 && num1 % 5 == 0) {
    printf("%d is divisible by both 3 and 5!\n", num1);
  }
  else if (num1 % 3 == 0) {
    printf("%d is divisible by 3!\n", num1);
  }
  else if (num1 % 5 == 0) {
    printf("%d is divisible by 5!\n", num1);
  }
  else {
    printf("%d is not divisible by either 3 or 5!\n", num1);
  }

  printf("Thanks for using me! Goodbye!\n");

  return 0;
}