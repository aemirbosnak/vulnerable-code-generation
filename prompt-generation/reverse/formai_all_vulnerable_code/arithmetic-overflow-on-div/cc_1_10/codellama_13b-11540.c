//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: portable
// Unique C Math Exercise Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function Declarations
void print_header();
void print_menu();
void print_result(int result);
int calculate_result(int num1, int num2);

// Main Function
int main() {
  // Initialize Variables
  int num1, num2, result;

  // Print Header
  print_header();

  // Print Menu
  print_menu();

  // Take Inputs
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Calculate Result
  result = calculate_result(num1, num2);

  // Print Result
  print_result(result);

  return 0;
}

// Function Definitions
void print_header() {
  printf("-----------------------------------\n");
  printf("   C Math Exercise Program\n");
  printf("-----------------------------------\n");
}

void print_menu() {
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

void print_result(int result) {
  printf("Result: %d\n", result);
}

int calculate_result(int num1, int num2) {
  int result;

  // Calculate Result
  switch (getchar()) {
    case '1':
      result = num1 + num2;
      break;
    case '2':
      result = num1 - num2;
      break;
    case '3':
      result = num1 * num2;
      break;
    case '4':
      result = num1 / num2;
      break;
    case '5':
      result = -1;
      break;
    default:
      printf("Invalid choice!\n");
      result = -1;
  }

  return result;
}