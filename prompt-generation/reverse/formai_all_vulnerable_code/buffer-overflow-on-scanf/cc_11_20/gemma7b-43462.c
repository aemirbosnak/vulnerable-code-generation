//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include <stdio.h>

#define MAX_TOKENS 10

typedef struct Token {
  char type;
  char value[MAX_TOKENS];
} Token;

int main() {
  Token tokens[MAX_TOKENS];
  int token_count = 0;
  char input[1024];

  printf("Enter C syntax: ");
  scanf("%s", input);

  while (input[token_count] != '\0') {
    switch (input[token_count]) {
      case '(':
      case ')':
      case '{':
      case '}':
      case ';':
      case ',':
      case ':':
      case '"':
      case '*':
        tokens[token_count].type = input[token_count];
        tokens[token_count].value[0] = input[token_count];
        token_count++;
        break;
      default:
        tokens[token_count].type = 'V';
        int i = 0;
        for (; input[token_count] != ' ' && input[token_count] != '\0'; token_count++) {
          tokens[token_count].value[i] = input[token_count];
          i++;
        }
        tokens[token_count].value[i] = '\0';
        token_count++;
    }
  }

  for (int i = 0; i < token_count; i++) {
    printf("Token type: %c, value: %s\n", tokens[i].type, tokens[i].value);
  }

  return 0;
}