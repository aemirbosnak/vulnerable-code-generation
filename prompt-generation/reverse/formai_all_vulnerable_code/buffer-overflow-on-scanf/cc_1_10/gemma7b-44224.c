//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

char history[MAX_HISTORY][1024];

void save_history(char *expr) {
  int i = 0;
  for (i = 0; i < MAX_HISTORY; i++) {
    if (history[i][0] == '\0') {
      strcpy(history[i], expr);
      return;
    }
  }
  printf("History is full!\n");
}

char *get_history(int index) {
  return history[index];
}

int main() {
  char expr[1024];
  int i = 0;
  char **operators = {"+-*/%", "()"};
  char operator;

  printf("Enter an expression: ");
  scanf("%s", expr);

  save_history(expr);

  operator = expr[0];
  expr[0] = '\0';

  switch (operator) {
    case '+':
      printf("Result: %d\n", atoi(expr) + atoi(get_history(i - 1)));
      break;
    case '-':
      printf("Result: %d\n", atoi(expr) - atoi(get_history(i - 1)));
      break;
    case '*':
      printf("Result: %d\n", atoi(expr) * atoi(get_history(i - 1)));
      break;
    case '/':
      printf("Result: %d\n", atoi(expr) / atoi(get_history(i - 1)));
      break;
    case '(':
      i++;
      save_history(expr);
      printf("Enter an expression: ");
      scanf("%s", expr);
      save_history(expr);
      operator = expr[0];
      expr[0] = '\0';
      break;
    default:
      printf("Invalid operator.\n");
  }

  return 0;
}