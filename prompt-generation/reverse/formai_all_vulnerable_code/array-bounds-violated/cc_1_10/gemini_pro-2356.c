//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int is_op(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

static int get_prec(char c) {
  switch (c) {
  case '+': case '-':
    return 1;
  case '*': case '/':
    return 2;
  case '^':
    return 3;
  default:
    return -1;
  }
}

static char* infix_to_postfix(const char* infix) {
  char* postfix = malloc(strlen(infix) + 1);
  int len = 0;
  char stack[strlen(infix)];
  int top = -1;

  for (int i = 0; infix[i] != '\0'; i++) {
    char c = infix[i];
    if (c == ' ') continue;
    if (isdigit(c)) {
      postfix[len++] = c;
      continue;
    }
    if (is_op(c)) {
      while (top > -1 && get_prec(stack[top]) >= get_prec(c)) {
        postfix[len++] = stack[top--];
      }
      stack[++top] = c;
      continue;
    }
    if (c == '(') {
      stack[++top] = c;
      continue;
    }
    if (c == ')') {
      while (stack[top] != '(') {
        postfix[len++] = stack[top--];
      }
      top--;
      continue;
    }
  }

  while (top > -1) {
    postfix[len++] = stack[top--];
  }
  postfix[len] = '\0';
  return postfix;
}

static double evaluate_postfix(const char* postfix) {
  double stack[strlen(postfix)];
  int top = -1;
  for (int i = 0; postfix[i] != '\0'; i++) {
    char c = postfix[i];
    if (isdigit(c)) {
      stack[++top] = c - '0';
      continue;
    }
    double op2 = stack[top--];
    double op1 = stack[top--];
    switch (c) {
    case '+':
      stack[++top] = op1 + op2;
      break;
    case '-':
      stack[++top] = op1 - op2;
      break;
    case '*':
      stack[++top] = op1 * op2;
      break;
    case '/':
      stack[++top] = op1 / op2;
      break;
    case '^':
      stack[++top] = pow(op1, op2);
      break;
    }
  }
  return stack[top];
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <infix expression>\n", argv[0]);
    return 1;
  }
  char* postfix = infix_to_postfix(argv[1]);
  printf("Postfix: %s\n", postfix);
  printf("Value: %f\n", evaluate_postfix(postfix));
  free(postfix);
  return 0;
}