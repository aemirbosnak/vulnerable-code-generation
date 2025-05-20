//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_handler(int err_num, char* err_msg) {
  char* error = NULL;

  switch (err_num) {
    case 1:
      error = "ERROR: Null pointer\n";
      break;
    case 2:
      error = "ERROR: Invalid input\n";
      break;
    case 3:
      error = "ERROR: File not found\n";
      break;
    case 4:
      error = "ERROR: Permission denied\n";
      break;
    case 5:
      error = "ERROR: Out of memory\n";
      break;
    default:
      error = "ERROR: Unknown error occurred\n";
  }

  printf("%s%s", error, err_msg);

  exit(EXIT_FAILURE);
}

int divide(int a, int b) {
  if (b == 0) {
    error_handler(2, "Division by zero is not allowed\n");
  }

  return a/b;
}

int main() {
  int dividend, divisor, result;
  char* message = "Please enter two integers to divide: ";

  printf("%s", message);
  if (scanf("%d %d", &dividend, &divisor) != 2) {
    error_handler(2, "Invalid input\n");
  }

  result = divide(dividend, divisor);

  printf("Result: %d\n", result);

  return 0;
}