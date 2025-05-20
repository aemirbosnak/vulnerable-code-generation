#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void parseParenthesis(char *source) {
  int i = 0;
  char stack[MAX_BUFFER_SIZE] = "";
  int stackSize = 0;

  for (i = 0; source[i] != '\0'; i++) {
    switch (source[i]) {
      case '(':
      case '[':
      case '{':
        stack[stackSize++] = source[i];
        break;
      case ')':
      case ']':
      case '}':
        if (stackSize == 0) {
          printf("Error: Missing opening parenthesis.\n");
          return;
        }
        if (stack[stackSize - 1] == source[i]) {
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
    return;
  }

  printf("Balanced parenthesis:\n");
  for (i = 0; i < stackSize; i++) {
    printf("%c ", stack[i]);
  }
  printf("\n");
}

int main() {
  char source[] = "()(())";
  parseParenthesis(source);

  return 0;
}
