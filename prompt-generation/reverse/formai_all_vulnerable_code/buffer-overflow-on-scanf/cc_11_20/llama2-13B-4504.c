//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 100
#define MAX_NUMBER_LENGTH 20

int main() {
  char operation[5];
  int number1, number2;
  int result;
  int i, j;

  // Initialize the operation and numbers
  printf("Welcome to the Arithmetic Game!\n");
  printf("Enter the first operation (e.g. '+', '-', '*', '/'): ");
  scanf("%s", operation);
  printf("Enter the first number: ");
  scanf("%d", &number1);
  printf("Enter the second number: ");
  scanf("%d", &number2);

  // Check if the operation is valid
  if (strlen(operation) > 5 || operation[0] == '\0') {
    printf("Invalid operation. Please try again.\n");
    return 1;
  }

  // Perform the operation
  switch (operation[0]) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      result = number1 / number2;
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Display the result
  printf("Result: %d\n", result);

  // Ask the user if they want to continue
  printf("Do you want to continue? (y/n): ");
  scanf("%s", operation);

  // Loop until the user says no
  while (strcmp(operation, "n") != 0) {
    // Generate a new operation and numbers
    printf("Enter the next operation (e.g. '+', '-', '*', '/'): ");
    scanf("%s", operation);
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    // Perform the operation
    switch (operation[0]) {
      case '+':
        result = number1 + number2;
        break;
      case '-':
        result = number1 - number2;
        break;
      case '*':
        result = number1 * number2;
        break;
      case '/':
        result = number1 / number2;
        break;
      default:
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Display the result
    printf("Result: %d\n", result);
  }

  return 0;
}