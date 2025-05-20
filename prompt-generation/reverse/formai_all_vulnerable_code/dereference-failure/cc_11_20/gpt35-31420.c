//FormAI DATASET v1.0 Category: Syntax parsing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Define the token type
typedef enum {
  TOK_NULL, TOK_INTEGER, TOK_FLOAT, TOK_STRING,
  TOK_OPERATOR, TOK_IDENTIFIER
} token_t;

// Define the token structure
typedef struct {
  token_t type;
  char value[MAX_TOKEN_LENGTH];
} token;

// Define the parse function
void parse(char *input) {
  char *p = input;

  while (*p != '\0') {
    if (isdigit(*p)) {
      // Parse integer
      int n = atoi(p);
      token t = { TOK_INTEGER };
      snprintf(t.value, MAX_TOKEN_LENGTH, "%d", n);
      printf("Token: %s\n", t.value);
      while (isdigit(*p)) { p++; }
    }
    else if (isalpha(*p)) {
      // Parse identifier or keyword
      char buffer[MAX_TOKEN_LENGTH] = {};
      int i = 0;
      while (isalnum(*p)) {
        buffer[i++] = *p++;
      }
      if (strcmp(buffer, "if") == 0 || strcmp(buffer, "while") == 0 || strcmp(buffer, "else") == 0) {
        printf("Token: keyword %s\n", buffer);
      } else {
        token t = { TOK_IDENTIFIER };
        strcpy(t.value, buffer);
        printf("Token: identifier %s\n", t.value);
      }
    }
    else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '=') {
      // Parse operator
      token t = { TOK_OPERATOR };
      t.value[0] = *p;
      t.value[1] = '\0';
      printf("Token: operator %s\n", t.value);
      p++;
    }
    else if (*p == '"') {
      // Parse string literal
      char buffer[MAX_TOKEN_LENGTH] = {};
      int i = 0;
      buffer[i++] = *p++;
      while (*p != '\0' && *p != '"') {
        buffer[i++] = *p++;
      }
      buffer[i++] = *p++;
      token t = { TOK_STRING };
      strcpy(t.value, buffer);
      printf("Token: string %s\n", t.value);
    }
    else if (*p == ' ' || *p == '\t' || *p == '\n') {
      // Ignore whitespace
      p++;
    }
    else {
      printf("Unexpected character: %c\n", *p);
      break;
    }
  }
}

// Define the main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s input\n", argv[0]);
    return 1;
  }
  parse(argv[1]);
  return 0;
}