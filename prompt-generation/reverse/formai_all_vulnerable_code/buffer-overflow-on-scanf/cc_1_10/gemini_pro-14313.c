//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct stack {
  double items[MAX_STACK_SIZE];
  int top;
} stack;

void push(stack *s, double item) {
  if (s->top == MAX_STACK_SIZE - 1) {
    printf("Error: stack overflow\n");
    exit(1);
  }
  s->items[++s->top] = item;
}

double pop(stack *s) {
  if (s->top == -1) {
    printf("Error: stack underflow\n");
    exit(1);
  }
  return s->items[s->top--];
}

int main() {
  stack s;
  s.top = -1;

  char input[100];
  while (1) {
    printf("Enter a command: ");
    scanf("%s", input);

    if (strcmp(input, "push") == 0) {
      double number;
      printf("Enter a number: ");
      scanf("%lf", &number);
      push(&s, number);
    } else if (strcmp(input, "pop") == 0) {
      printf("Popped: %lf\n", pop(&s));
    } else if (strcmp(input, "+") == 0) {
      double a = pop(&s);
      double b = pop(&s);
      push(&s, a + b);
    } else if (strcmp(input, "-") == 0) {
      double a = pop(&s);
      double b = pop(&s);
      push(&s, b - a);
    } else if (strcmp(input, "*") == 0) {
      double a = pop(&s);
      double b = pop(&s);
      push(&s, a * b);
    } else if (strcmp(input, "/") == 0) {
      double a = pop(&s);
      double b = pop(&s);
      push(&s, b / a);
    } else if (strcmp(input, "^") == 0) {
      double a = pop(&s);
      double b = pop(&s);
      push(&s, pow(b, a));
    } else if (strcmp(input, "sin") == 0) {
      double a = pop(&s);
      push(&s, sin(a));
    } else if (strcmp(input, "cos") == 0) {
      double a = pop(&s);
      push(&s, cos(a));
    } else if (strcmp(input, "tan") == 0) {
      double a = pop(&s);
      push(&s, tan(a));
    } else if (strcmp(input, "exit") == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}