//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAGIC_NUMBER 42

int main() {
  // Declare variables to store magic numbers
  int num1 = 24;
  int num2 = 7;
  int sum = 0;
  int product = 0;

  // Print a fun message to welcome the user
  printf("Welcome to the mystical land of arithmetic! \n");

  // Ask the user for the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Ask the user for the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Calculate the sum of the two numbers
  sum = num1 + num2;

  // Print the result of the sum
  printf("The sum of %d and %d is %d\n", num1, num2, sum);

  // Calculate the product of the two numbers
  product = num1 * num2;

  // Print the result of the product
  printf("The product of %d and %d is %d\n", num1, num2, product);

  // Check if the result of the sum is equal to the magic number
  if (sum == MAGIC_NUMBER) {
    printf("You have found the magic number! Congratulations, wizard! \n");
  } else {
    printf("Unfortunately, you have not found the magic number. Better luck next time! \n");
  }

  // Check if the result of the product is a prime number
  if (product > 1 && product % 2 == 0) {
    printf("The product of %d and %d is a prime number! Who knew? \n", num1, num2);
  } else {
    printf("The product of %d and %d is not a prime number. Oh well! \n", num1, num2);
  }

  // Print a fun message to say goodbye
  printf("Farewell, brave adventurer! May the magic of arithmetic be with you always! \n");

  return 0;
}