//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
// Error Handling Example Program
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2;

  printf("Enter two integers: ");
  if(scanf("%d %d", &num1, &num2) != 2) {
    fprintf(stderr, "Invalid input. Please enter two integers.\n");
    exit(EXIT_FAILURE);
  }

  if(num2 == 0) {
    fprintf(stderr, "Error: Division by zero.\n");
    exit(EXIT_FAILURE);
  }

  double result = (double)num1 / num2;
  printf("%d / %d = %.2lf\n", num1, num2, result);

  char str[10];
  printf("Enter a string (max 10 characters): ");
  fgets(str, sizeof(str), stdin);

  // Remove newline character from string
  if(str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  // Check if string is within length limit
  if(strlen(str) > 10) {
    fprintf(stderr, "Error: String exceeds maximum length of 10 characters.\n");
    exit(EXIT_FAILURE);
  }

  printf("Entered string: %s\n", str);

  FILE *fp = fopen("file.txt", "r");

  // Check if file opened successfully
  if(fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char c = fgetc(fp);

  while(c != EOF) {
    putchar(c);
    c = fgetc(fp);
  }

  fclose(fp);

  return 0;
}