//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two numbers
double add(double num1, double num2) {
   return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
   return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
   return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
   if(num2 == 0) {
      printf("Error! Cannot divide by zero\n");
      return 0;
   }
   return num1 / num2;
}

// Function to get power of a number
double power(double num1, int num2) {
   return pow(num1, num2);
}

int main() {
   char operator;
   double num1, num2;

   printf("Enter an operator (+, -, *, /): ");
   scanf("%c", &operator);

   printf("Enter two numbers: ");
   scanf("%lf %lf",&num1, &num2);

   switch(operator) {
      case '+':
         printf("Result: %lf\n", add(num1, num2));
         break;
      case '-':
         printf("Result: %lf\n", subtract(num1, num2));
         break;
      case '*':
         printf("Result: %lf\n", multiply(num1, num2));
         break;
      case '/':
         printf("Result: %lf\n", divide(num1, num2));
         break;
      default:
         printf("Error! Invalid operator");
   }

   return 0;
}