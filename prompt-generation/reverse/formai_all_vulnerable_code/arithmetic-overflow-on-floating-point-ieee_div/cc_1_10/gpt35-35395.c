//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator
  
  int num1 = rand() % 100; // Generate two random numbers from 0 to 99
  int num2 = rand() % 100;
  
  int sum = num1 + num2; // Calculate sum of the two numbers
  int diff = num1 - num2; // Calculate difference of the two numbers
  int prod = num1 * num2; // Calculate product of the two numbers
  float quot = (float) num1 / num2; // Calculate quotient of the two numbers and cast the result to a float
  
  printf("Welcome to Math Exercise Program!\n\n");
  printf("You will be given two random numbers and asked to calculate their sum, difference, product and quotient.\n\n");
  printf("Here are the numbers:\n");
  printf("Number 1: %d\n", num1);
  printf("Number 2: %d\n\n", num2);
  
  printf("Please enter the sum of the two numbers: "); // Get user input for sum
  int userSum;
  scanf("%d", &userSum);
  
  printf("Please enter the difference of the two numbers: "); // Get user input for difference
  int userDiff;
  scanf("%d", &userDiff);
  
  printf("Please enter the product of the two numbers: "); // Get user input for product
  int userProd;
  scanf("%d", &userProd);
  
  printf("Please enter the quotient of the two numbers (rounded to two decimal places): "); // Get user input for quotient
  float userQuot;
  scanf("%f", &userQuot);
  
  printf("\nCalculating results...\n\n");
  
  if(userSum == sum) {
    printf("Correct! The sum of %d and %d is %d.\n", num1, num2, sum);
  } else {
    printf("Incorrect. The correct answer is %d.\n", sum);
  }
  
  if(userDiff == diff) {
    printf("Correct! The difference of %d and %d is %d.\n", num1, num2, diff);
  } else {
    printf("Incorrect. The correct answer is %d.\n", diff);
  }
  
  if(userProd == prod) {
    printf("Correct! The product of %d and %d is %d.\n", num1, num2, prod);
  } else {
    printf("Incorrect. The correct answer is %d.\n", prod);
  }
  
  if((userQuot >= quot - 0.01) && (userQuot <= quot + 0.01)) {
    printf("Correct! The quotient of %d and %d is %.2f.\n", num1, num2, quot);
  } else {
    printf("Incorrect. The correct answer is %.2f.\n", quot);
  }
  
  printf("\nThank you for using Math Exercise Program!\n");
  
  return 0;
}