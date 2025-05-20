//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void errorHandler(int errorCode);
void successHandler();
void divide(int a, int b);

int main() {
  int a, b;
  printf("Enter numerator: ");
  scanf("%d", &a);

  printf("Enter denominator: ");
  scanf("%d", &b);

  if (b == 0) {
    errorHandler(0);
  } else {
    divide(a, b);
  }

  return 0;
}

void errorHandler(int errorCode) {
  switch (errorCode) {
    case 0:
      printf("Error: Division by zero is not allowed!");
      break;
    case 1:
      printf("Error: Memory allocation failed!");
      break;
    default:
      printf("Unknown error!");
      break;
  }
  exit(errorCode);
}

void successHandler() {
  printf("Division successful!");
}

void divide(int a, int b) {
  int* result = malloc(sizeof(int));

  if (result == NULL) {
    errorHandler(1);
  }

  *result = a / b;

  printf("%d / %d = %d\n", a, b, *result);

  successHandler();

  free(result);
}