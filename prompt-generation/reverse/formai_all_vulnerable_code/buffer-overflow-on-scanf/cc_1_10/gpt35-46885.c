//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>

int main(void) {
  printf("Welcome to my C program!\n");
  
  // Asking user for an integer input
  int inputNum;
  printf("Enter an integer number: ");
  scanf("%d", &inputNum);
  
  // Checking if the input number is even or odd
  if(inputNum % 2 == 0) {
    printf("%d is even.\n", inputNum);
  }
  else {
    printf("%d is odd.\n", inputNum);
  }
  
  // Creating a Fibonacci series
  int fibonacciNum1 = 0;
  int fibonacciNum2 = 1;
  int fibonacciResult;
  printf("Here are the first 10 numbers in the Fibonacci series:\n");
  printf("0 1 ");
  for(int i = 2; i < 10; i++) {
    fibonacciResult = fibonacciNum1 + fibonacciNum2;
    printf("%d ", fibonacciResult);
    fibonacciNum1 = fibonacciNum2;
    fibonacciNum2 = fibonacciResult;
  }
  printf("\n");
  
  // Showing the ASCII value of a character
  char inputChar;
  printf("Enter a character: ");
  scanf("%c", &inputChar);
  printf("The ASCII value of %c is %d.\n", inputChar, inputChar);
  
  // Converting Fahrenheit to Celsius
  float fahrenheitTemp, celsiusTemp;
  printf("Enter a temperature in Fahrenheit: ");
  scanf("%f", &fahrenheitTemp);
  celsiusTemp = (fahrenheitTemp - 32) * 5 / 9;
  printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheitTemp, celsiusTemp);
  
  // Calculating the factorial of a number
  int factorialNum;
  printf("Enter a number to calculate its factorial: ");
  scanf("%d", &factorialNum);
  int factorialResult = 1;
  for(int i = 1; i <= factorialNum; i++) {
    factorialResult *= i;
  }
  printf("The factorial of %d is %d.\n", factorialNum, factorialResult);
  
  return 0;
}