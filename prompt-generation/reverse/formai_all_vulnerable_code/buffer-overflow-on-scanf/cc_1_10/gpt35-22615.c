//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Variables
  FILE *filePointer;
  char fileName[20], operation[5];
  int num1, num2, sum;

  // Get file name and operation from user
  printf("Enter file name (without extension): ");
  scanf("%s", fileName);
  printf("Enter operation (add/sub): ");
  scanf("%s", operation);

  // Construct file name with .txt extension
  strcat(fileName, ".txt");

  // Open file in respective mode
  if (strcmp(operation, "add") == 0) {
    filePointer = fopen(fileName, "w");
  } else if (strcmp(operation, "sub") == 0) {
    filePointer = fopen(fileName, "r");
  } else {
    printf("Invalid operation\n");
    exit(0);
  }

  if (filePointer == NULL) {
    printf("File not found\n");
    exit(0);
  }

  // Addition operation
  if (strcmp(operation, "add") == 0) {
    printf("Enter two numbers to add:\n");
    printf("Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);

    sum = num1 + num2;

    fprintf(filePointer, "%d", sum);

    printf("%d + %d = %d\n", num1, num2, sum);

    printf("Result written to %s\n", fileName);
  }

  // Subtraction operation
  if (strcmp(operation, "sub") == 0) {
    int num, result;

    while (fscanf(filePointer, "%d", &num) == 1) {
      result -= num;
    }

    printf("Result: %d\n", result);
  }

  // Close file
  fclose(filePointer);

  return 0;
}