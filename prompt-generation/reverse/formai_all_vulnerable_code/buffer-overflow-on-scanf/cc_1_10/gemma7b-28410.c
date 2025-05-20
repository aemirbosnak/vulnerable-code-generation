//Gemma-7B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

int main() {
  char cmd[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(cmd, MAX_CMD_LEN, stdin);

  // Validate the command
  if (strcmp(cmd, "exit") == 0) {
    printf("Exiting...\n");
    exit(0);
  } else if (strcmp(cmd, "help") == 0) {
    printf("Available commands:\n");
    printf("  exit: Exit the program\n");
    printf("  help: Display this help message\n");
    printf("  add: Add two numbers\n");
    printf("  sub: Subtract two numbers\n");
  } else if (strcmp(cmd, "add") == 0) {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result = num1 + num2;
    printf("The result is: %d\n", result);
  } else if (strcmp(cmd, "sub") == 0) {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result = num1 - num2;
    printf("The result is: %d\n", result);
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}