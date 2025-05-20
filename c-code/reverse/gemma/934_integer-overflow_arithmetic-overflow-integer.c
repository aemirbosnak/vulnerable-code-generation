#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
  int stack[MAX_SIZE] = {0};
  int top = -1;
  char input[MAX_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case ' ':
        break;
      case '+':
        if (top == MAX_SIZE - 1) {
          printf("Error: stack overflow\n");
          return 1;
        }
        stack[++top] = stack[top] + (int)input[i + 1] - 48;
        break;
      case '-':
        if (top == -1) {
          printf("Error: stack underflow\n");
          return 1;
        }
        stack[++top] = stack[top] - (int)input[i + 1] - 48;
        break;
      case '*':
        if (top == MAX_SIZE - 1) {
          printf("Error: stack overflow\n");
          return 1;
        }
        stack[++top] = (int)input[i + 1] - 48;
        break;
      default:
        printf("Error: invalid input\n");
        return 1;
    }
  }

  printf("The result is: %d\n", stack[top]);

  return 0;
}
