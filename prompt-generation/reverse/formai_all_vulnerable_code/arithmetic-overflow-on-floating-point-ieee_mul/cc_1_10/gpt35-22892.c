//FormAI DATASET v1.0 Category: Calculator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Hello there, I am a calculator program!\n");
  printf("What would you like to do?\n");
  printf("1. Add two numbers\n");
  printf("2. Subtract two numbers\n");
  printf("3. Multiply two numbers\n");
  printf("4. Divide two numbers\n");
  int choice;
  scanf("%d", &choice); 
  
  if (choice == 1) {
    printf("You chose to add two numbers!\n");
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);
    double result = num1 + num2;
    printf("The result of %lf + %lf is: %lf\n", num1, num2, result);
  }
  else if (choice == 2) {
    printf("You chose to subtract two numbers!\n");
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);
    double result = num1 - num2;
    printf("The result of %lf - %lf is: %lf\n", num1, num2, result);
  }
  else if (choice == 3) {
    printf("You chose to multiply two numbers!\n");
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);
    double result = num1 * num2;
    printf("The result of %lf * %lf is: %lf\n", num1, num2, result);
  }
  else if (choice == 4) {
    printf("You chose to divide two numbers!!\n");
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);
    while(num2 == 0) {
      printf("Division by zero is not allowed. Please enter another number: ");
      scanf("%lf", &num2);
    }
    double result = num1 / num2;
    printf("The result of %lf / %lf is: %lf\n", num1, num2, result);
  }
  else {
    printf("Invalid choice. Please try again.\n");
  }
  printf("Thanks for using me!");
  return 0;
}