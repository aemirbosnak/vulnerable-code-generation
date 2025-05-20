//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the cyberpunk-themed colors
#define COLOR_ERROR "\x1b[31m"
#define COLOR_SUCCESS "\x1b[32m"
#define COLOR_WARNING "\x1b[33m"
#define COLOR_INFO "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

// Define the cyberpunk-themed ASCII art
#define ASCII_ART "\n                                                            _ _            \n                                                           | | |          \n ._____________________________________        ,-------------. \n | .____________________________________|       /             \\ \n | | _______________  ____  ___  __________,--.  |               | \n | | |_______________||__  ||__||_______________||__|--------------'\n | | ____              |___||___|              |_____               \n | | |___|            ___  ___ ___            ___ ___             \n | |___________________||__||__||___|_________||__||__|____________\n |___________________________________________________________________| \n |___________________________________________________________________|\n \\___________________________________________________________________/ \n  \\__________________________________________________________________/  \n"

// Define the main function
int main() {
  // Print the cyberpunk-themed ASCII art
  printf(ASCII_ART);

  // Initialize the variables
  char operation;
  double num1, num2;
  double result;

  // Prompt the user to enter the operation and the numbers
  printf(COLOR_INFO "\nEnter the operation (+, -, *, /): " COLOR_RESET);
  scanf(" %c", &operation);
  printf(COLOR_INFO "Enter the first number: " COLOR_RESET);
  scanf(" %lf", &num1);
  printf(COLOR_INFO "Enter the second number: " COLOR_RESET);
  scanf(" %lf", &num2);

  // Perform the operation
  switch (operation) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf(COLOR_ERROR "Error: Division by zero" COLOR_RESET);
        return EXIT_FAILURE;
      }
      result = num1 / num2;
      break;
    default:
      printf(COLOR_ERROR "Error: Invalid operation" COLOR_RESET);
      return EXIT_FAILURE;
  }

  // Print the result
  printf(COLOR_SUCCESS "Result: %lf" COLOR_RESET, result);

  return EXIT_SUCCESS;
}