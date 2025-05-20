//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_LENGTH 1024
#define STACK_SIZE 1024

// Function prototypes
int is_operator(char c);
int precedence(char c);
void infix_to_postfix(char *infix, char *postfix);
double evaluate_postfix(char *postfix);

// Main function
int main() {
  char infix[MAX_EXPR_LENGTH], postfix[MAX_EXPR_LENGTH];

  // Get the infix expression from the user
  printf("Enter an infix expression: ");
  fgets(infix, MAX_EXPR_LENGTH, stdin);

  // Convert the infix expression to postfix
  infix_to_postfix(infix, postfix);

  // Evaluate the postfix expression
  double result = evaluate_postfix(postfix);

  // Print the result
  printf("The result is: %f\n", result);

  return 0;
}

// Function to check if a character is an operator
int is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to get the precedence of an operator
int precedence(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}

// Function to convert an infix expression to postfix
void infix_to_postfix(char *infix, char *postfix) {
  int stack[STACK_SIZE];
  int top = -1;
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    if (infix[i] == '(') {
      stack[++top] = '(';
    } else if (infix[i] == ')') {
      while (stack[top] != '(') {
        postfix[j++] = stack[top--];
      }
      top--;
    } else if (is_operator(infix[i])) {
      while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
        postfix[j++] = stack[top--];
      }
      stack[++top] = infix[i];
    } else {
      postfix[j++] = infix[i];
    }
    i++;
  }

  while (top != -1) {
    postfix[j++] = stack[top--];
  }

  postfix[j] = '\0';
}

// Function to evaluate a postfix expression
double evaluate_postfix(char *postfix) {
  double stack[STACK_SIZE];
  int top = -1;
  int i = 0;

  while (postfix[i] != '\0') {
    if (is_operator(postfix[i])) {
      double op2 = stack[top--];
      double op1 = stack[top--];
      switch (postfix[i]) {
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
    } else {
      stack[++top] = atof(&postfix[i]);
      while (postfix[i] != ' ' && postfix[i] != '\0') {
        i++;
      }
      i--;
    }
    i++;
  }

  return stack[top];
}