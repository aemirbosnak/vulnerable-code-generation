//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Token {
    char* type;
    char* value;
  };

  struct Token* parse_token(char* input) {
    struct Token* token = malloc(sizeof(struct Token));
    token->type = "INVALID";
    token->value = "";

    // Check for identifier
    if (isalpha(*input)) {
      token->type = "IDENTIFIER";
      token->value = input;
      return token;
    }

    // Check for number
    if (isdigit(*input)) {
      token->type = "NUMBER";
      token->value = input;
      return token;
    }

    // Check for keyword
    if (strcmp(input, "if") == 0) {
      token->type = "IF";
      token->value = input;
      return token;
    } else if (strcmp(input, "else") == 0) {
      token->type = "ELSE";
      token->value = input;
      return token;
    } else if (strcmp(input, "while") == 0) {
      token->type = "WHILE";
      token->value = input;
      return token;
    } else if (strcmp(input, "for") == 0) {
      token->type = "FOR";
      token->value = input;
      return token;
    } else if (strcmp(input, "return") == 0) {
      token->type = "RETURN";
      token->value = input;
      return token;
    }

    // Check for operator
    if (strcmp(input, "+") == 0 ||
        strcmp(input, "-") == 0 ||
        strcmp(input, "*") == 0 ||
        strcmp(input, "/") == 0) {
      token->type = "OPERATOR";
      token->value = input;
      return token;
    }

    // Check for punctuation
    if (strcmp(input, "{") == 0 ||
        strcmp(input, "}") == 0 ||
        strcmp(input, "(") == 0 ||
        strcmp(input, ")") == 0 ||
        strcmp(input, ";") == 0) {
      token->type = "PUNCTUATION";
      token->value = input;
      return token;
    }

    // Check for string
    if (strcmp(input, "\"") == 0) {
      token->type = "STRING";
      token->value = input;
      return token;
    }

    return token;
  }

  int main() {
    char* input = "if (a > b) { return a + b; }";
    struct Token* token = parse_token(input);
    printf("%s\n", token->type);
    printf("%s\n", token->value);
    return 0;
  }