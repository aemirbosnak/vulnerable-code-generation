//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef enum {
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  POW,
  SIN,
  COS,
  TAN,
  ASIN,
  ACOS,
  ATAN,
  LOG,
  EXP,
  SQRT,
  CBRT,
  ABS,
  PI,
  E
} Op;

typedef struct {
  char *name;
  Op op;
} Token;

Token tokens[] = {
  {"+", ADD},
  {"-", SUB},
  {"*", MUL},
  {"/", DIV},
  {"%", MOD},
  {"^", POW},
  {"sin", SIN},
  {"cos", COS},
  {"tan", TAN},
  {"asin", ASIN},
  {"acos", ACOS},
  {"atan", ATAN},
  {"log", LOG},
  {"exp", EXP},
  {"sqrt", SQRT},
  {"cbrt", CBRT},
  {"abs", ABS},
  {"pi", PI},
  {"e", E},
  {NULL, 0}
};

char *token_names[] = {
  "ADD",
  "SUB",
  "MUL",
  "DIV",
  "MOD",
  "POW",
  "SIN",
  "COS",
  "TAN",
  "ASIN",
  "ACOS",
  "ATAN",
  "LOG",
  "EXP",
  "SQRT",
  "CBRT",
  "ABS",
  "PI",
  "E"
};

double evaluate(char *expression) {
  char *p = expression;
  double stack[100];
  int top = 0;

  while (*p) {
    if (isdigit(*p)) {
      double value = 0;
      while (isdigit(*p)) {
        value = value * 10 + *p++ - '0';
      }
      stack[top++] = value;
    } else if (isalpha(*p)) {
      char *start = p;
      while (isalnum(*p)) {
        p++;
      }
      int length = p - start;
      int i;
      for (i = 0; i < sizeof(tokens) / sizeof(Token); i++) {
        if (strlen(tokens[i].name) == length &&
            strncmp(tokens[i].name, start, length) == 0) {
          break;
        }
      }
      if (i < sizeof(tokens) / sizeof(Token)) {
        switch (tokens[i].op) {
          case ADD:
            stack[top - 2] = stack[top - 2] + stack[top - 1];
            top--;
            break;
          case SUB:
            stack[top - 2] = stack[top - 2] - stack[top - 1];
            top--;
            break;
          case MUL:
            stack[top - 2] = stack[top - 2] * stack[top - 1];
            top--;
            break;
          case DIV:
            stack[top - 2] = stack[top - 2] / stack[top - 1];
            top--;
            break;
          case MOD:
            stack[top - 2] = fmod(stack[top - 2], stack[top - 1]);
            top--;
            break;
          case POW:
            stack[top - 2] = pow(stack[top - 2], stack[top - 1]);
            top--;
            break;
          case SIN:
            stack[top - 1] = sin(stack[top - 1]);
            break;
          case COS:
            stack[top - 1] = cos(stack[top - 1]);
            break;
          case TAN:
            stack[top - 1] = tan(stack[top - 1]);
            break;
          case ASIN:
            stack[top - 1] = asin(stack[top - 1]);
            break;
          case ACOS:
            stack[top - 1] = acos(stack[top - 1]);
            break;
          case ATAN:
            stack[top - 1] = atan(stack[top - 1]);
            break;
          case LOG:
            stack[top - 1] = log(stack[top - 1]);
            break;
          case EXP:
            stack[top - 1] = exp(stack[top - 1]);
            break;
          case SQRT:
            stack[top - 1] = sqrt(stack[top - 1]);
            break;
          case CBRT:
            stack[top - 1] = cbrt(stack[top - 1]);
            break;
          case ABS:
            stack[top - 1] = fabs(stack[top - 1]);
            break;
          case PI:
            stack[top++] = M_PI;
            break;
          case E:
            stack[top++] = M_E;
            break;
        }
      } else {
        printf("Invalid token: %s\n", start);
        exit(1);
      }
    } else {
      p++;
    }
  }

  if (top != 1) {
    printf("Invalid expression: %s\n", expression);
    exit(1);
  }

  return stack[0];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    exit(1);
  }

  double result = evaluate(argv[1]);

  printf("Result: %f\n", result);

  return 0;
}