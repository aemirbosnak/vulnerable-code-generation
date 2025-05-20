//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
#include<stdio.h>

// Function to take input from the user and return it
int input()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  return num;
}

// Function to find the sum of two numbers
int sum(int a, int b)
{
  return a + b;
}

// Function to find the difference of two numbers
int difference(int a, int b)
{
  return a - b;
}

// Function to find the product of two numbers
int product(int a, int b)
{
  return a * b;
}

// Function to divide two numbers and return the quotient
float quotient(int a, int b)
{
  float result;
  
  if(b == 0)
  {
    printf("Error: Division by zero!");
    result = 0;
  }
  else
  {
    result = (float) a / b;
  }
  
  return result;
}

// Function to find the remainder of two numbers
int remainder(int a, int b)
{
  return a % b;
}

// Main function
int main()
{
  int num1, num2, choice;
  float result;
  
  printf("Welcome to the Arithmetic operations program!\n");
  
  // Get input from the user
  num1 = input();
  num2 = input();
  
  printf("Please select an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Remainder\n");
  printf("Enter your choice (1-5): ");
  scanf("%d", &choice);
  
  switch(choice)
  {
    case 1:
      result = sum(num1, num2);
      printf("The sum of %d and %d is %f", num1, num2, result);
      break;
    
    case 2:
      result = difference(num1, num2);
      printf("The difference of %d and %d is %f", num1, num2, result);
      break;
    
    case 3:
      result = product(num1, num2);
      printf("The product of %d and %d is %f", num1, num2, result);
      break;
    
    case 4:
      result = quotient(num1, num2);
      printf("The quotient of %d and %d is %f", num1, num2, result);
      break;
    
    case 5:
      result = remainder(num1, num2);
      printf("The remainder of %d and %d is %f", num1, num2, result);
      break;
    
    default:
      printf("Error: Invalid choice!");
  }
  
  return 0;
}