//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
/*
 * Scientific Calculator Implementation
 * ----------------------------------
 *
 * This program implements a simple scientific calculator
 * with basic arithmetic and trigonometric operations.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <math.h>

// Define the constants
#define PI 3.14159
#define EULER 2.71828

// Define the variables
int choice;
double num1, num2, result;

// Define the functions
void menu();
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double sin(double);
double cos(double);
double tan(double);

int main() {
  // Display the menu
  menu();

  // Get the user's choice
  scanf("%d", &choice);

  // Perform the operation based on the user's choice
  switch (choice) {
    case 1:
      result = add(num1, num2);
      break;
    case 2:
      result = subtract(num1, num2);
      break;
    case 3:
      result = multiply(num1, num2);
      break;
    case 4:
      result = divide(num1, num2);
      break;
    case 5:
      result = sin(num1);
      break;
    case 6:
      result = cos(num1);
      break;
    case 7:
      result = tan(num1);
      break;
    default:
      printf("Invalid choice!\n");
      return 1;
  }

  // Display the result
  printf("Result: %lf\n", result);

  return 0;
}

void menu() {
  printf("Scientific Calculator\n");
  printf("--------------------\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Sin\n");
  printf("6. Cos\n");
  printf("7. Tan\n");
  printf("8. Exit\n");
  printf("Enter your choice: ");
}

double add(double num1, double num2) {
  return num1 + num2;
}

double subtract(double num1, double num2) {
  return num1 - num2;
}

double multiply(double num1, double num2) {
  return num1 * num2;
}

double divide(double num1, double num2) {
  return num1 / num2;
}

double sin(double num) {
  return sin(num);
}

double cos(double num) {
  return cos(num);
}

double tan(double num) {
  return tan(num);
}