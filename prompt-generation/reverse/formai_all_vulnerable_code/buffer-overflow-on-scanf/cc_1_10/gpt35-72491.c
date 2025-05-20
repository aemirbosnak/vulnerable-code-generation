//FormAI DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void handleError(int errorCode) {
  switch(errorCode) {
    case 1:
      printf("Error: Division by zero");
      break;
    case 2:
      printf("Error: Invalid input value");
      break;
    case 3:
      printf("Error: File not found");
      break;
    default:
      printf("Unknown error occurred");
      break;
  }
  exit(errorCode);
}

int main() {
  int a, b, result;
  
  printf("Enter value of a: ");
  scanf("%d", &a);
  
  if(a == 0) {
    handleError(2);
  }
  
  printf("Enter value of b: ");
  scanf("%d", &b);
  
  if (b == 0) {
    handleError(1);
  }
  
  result = a / b;
  
  printf("Result of %d / %d is %d", a, b, result);
  
  FILE *file;
  char fileName[50];
  printf("\nEnter name of file to open: ");
  scanf("%s", fileName);
  
  file = fopen(fileName, "r");
  
  if (file == NULL) {
    handleError(3);
  }
  
  printf("\nFile opened successfully");
  
  fclose(file);
  
  return 0;
}