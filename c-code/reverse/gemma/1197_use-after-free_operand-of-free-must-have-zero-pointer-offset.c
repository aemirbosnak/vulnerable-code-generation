#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parseParenthesis(char *str) {
  int i = 0;
  char *stack = NULL;
  int stackSize = 0;

  for (i = 0; str[i] != '\0'; i++) {
    switch (str[i]) {
      case '(':
      case '{':
      case '[':
        stack = realloc(stack, (stackSize + 1) * sizeof(char));
        stack[stackSize++] = str[i];
        break;
      case ')':
      case '}':
      case ']':
        if (stackSize == 0) {
          printf("Error: Missing opening parenthesis.\n");
          return;
        }
        if (stack[stackSize - 1] == str[i]) {
          stackSize--;
        } else {
          printf("Error: Mismatched parenthesis.\n");
          return;
        }
        break;
    }
  }

  if (stackSize > 0) {
    printf("Error: Missing closing parenthesis.\n");
  }

  free(stack);
}

int main() {
  char *str = "(())";
  parseParenthesis(str);

  return 0;
}
