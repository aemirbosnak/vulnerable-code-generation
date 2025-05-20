#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseParentheses(char *source) {
  int length = strlen(source);
  char **stack = (char **)malloc(length * sizeof(char *));
  int stackSize = 0;
  int i = 0;

  for (; i < length; i++) {
    char currentChar = source[i];
    switch (currentChar) {
      case '(':
      case '{':
      case '[':
        stack[stackSize++] = currentChar;
        break;
      case ')':
      case '}':
      case ']':
        if (stackSize == 0) {
          printf("Error: Missing opening parenthesis.\n");
          return;
        }
        if (stack[stackSize - 1] == currentChar) {
          stackSize--;
        } else {
          printf("Error: Mismatched parentheses.\n");
          return;
        }
        break;
    }
  }

  if (stackSize > 0) {
    printf("Error: Missing closing parenthesis.\n");
    return;
  }

  free(stack);
}

int main() {
  char *source = "()(())";
  parseParentheses(source);

  return 0;
}
