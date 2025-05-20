//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

enum token_type {
  TOK_PLUS,
  TOK_MINUS,
  TOK_MUL,
  TOK_DIV,
  TOK_LPAREN,
  TOK_RPAREN,
  TOK_NUMBER,
  TOK_END
};

struct token {
  enum token_type type;
  union {
    int value;
  } data;
};

int get_token(char *expr, int *index, struct token *tok) {
  while (isspace(expr[*index])) {
    (*index)++;
  }

  switch (expr[*index]) {
  case '+':
    tok->type = TOK_PLUS;
    (*index)++;
    break;
  case '-':
    tok->type = TOK_MINUS;
    (*index)++;
    break;
  case '*':
    tok->type = TOK_MUL;
    (*index)++;
    break;
  case '/':
    tok->type = TOK_DIV;
    (*index)++;
    break;
  case '(':
    tok->type = TOK_LPAREN;
    (*index)++;
    break;
  case ')':
    tok->type = TOK_RPAREN;
    (*index)++;
    break;
  case '\0':
    tok->type = TOK_END;
    break;
  default:
    if (isdigit(expr[*index])) {
      tok->type = TOK_NUMBER;
      tok->data.value = atoi(&expr[*index]);
      while (isdigit(expr[*index])) {
        (*index)++;
      }
    } else {
      fprintf(stderr, "Unknown token '%c'\n", expr[*index]);
      return -1;
    }
    break;
  }

  return 0;
}

int parse_expr(char *expr, int *index, int *result);

int parse_primary(char *expr, int *index, int *result) {
  struct token tok;
  int ret;

  ret = get_token(expr, index, &tok);
  if (ret != 0) {
    return ret;
  }

  switch (tok.type) {
  case TOK_NUMBER:
    *result = tok.data.value;
    break;
  case TOK_LPAREN:
    ret = parse_expr(expr, index, result);
    if (ret != 0) {
      return ret;
    }

    ret = get_token(expr, index, &tok);
    if (ret != 0) {
      return ret;
    }

    if (tok.type != TOK_RPAREN) {
      fprintf(stderr, "Mismatched parentheses\n");
      return -1;
    }

    break;
  default:
    fprintf(stderr, "Expected primary expression, got token of type %d\n", tok.type);
    return -1;
  }

  return 0;
}

int parse_term(char *expr, int *index, int *result) {
  int ret;
  int rhs;

  ret = parse_primary(expr, index, result);
  if (ret != 0) {
    return ret;
  }

  while (1) {
    struct token tok;
    int old_index = *index;

    ret = get_token(expr, index, &tok);
    if (ret != 0) {
      return ret;
    }

    switch (tok.type) {
    case TOK_MUL:
      ret = parse_primary(expr, index, &rhs);
      if (ret != 0) {
        return ret;
      }

      *result *= rhs;
      break;
    case TOK_DIV:
      ret = parse_primary(expr, index, &rhs);
      if (ret != 0) {
        return ret;
      }

      if (rhs == 0) {
        fprintf(stderr, "Division by zero\n");
        return -1;
      }

      *result /= rhs;
      break;
    default:
      *index = old_index; /* rewind */
      return 0;
    }
  }
}

int parse_expr(char *expr, int *index, int *result) {
  int ret;
  int rhs;

  ret = parse_term(expr, index, result);
  if (ret != 0) {
    return ret;
  }

  while (1) {
    struct token tok;
    int old_index = *index;

    ret = get_token(expr, index, &tok);
    if (ret != 0) {
      return ret;
    }

    switch (tok.type) {
    case TOK_PLUS:
      ret = parse_term(expr, index, &rhs);
      if (ret != 0) {
        return ret;
      }

      *result += rhs;
      break;
    case TOK_MINUS:
      ret = parse_term(expr, index, &rhs);
      if (ret != 0) {
        return ret;
      }

      *result -= rhs;
      break;
    default:
      *index = old_index; /* rewind */
      return 0;
    }
  }
}

int main() {
  char expr[MAX_EXPR_LEN];
  int result;
  int index = 0;
  int ret;

  printf("Enter expression: ");
  fgets(expr, MAX_EXPR_LEN, stdin);
  expr[strlen(expr) - 1] = '\0'; /* remove newline */

  ret = parse_expr(expr, &index, &result);
  if (ret != 0) {
    return EXIT_FAILURE;
  }

  printf("Result: %d\n", result);

  return EXIT_SUCCESS;
}