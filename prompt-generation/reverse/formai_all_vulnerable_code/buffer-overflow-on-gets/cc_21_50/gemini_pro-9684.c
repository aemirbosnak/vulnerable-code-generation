//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100
#define KEYWORD_COUNT 5
#define DELIMITER_COUNT 7
#define OPERATOR_COUNT 4

typedef enum {
  TOKEN_NONE,
  TOKEN_KEYWORD,
  TOKEN_IDENTIFIER,
  TOKEN_STRING,
  TOKEN_NUMBER,
  TOKEN_DELIMITER,
  TOKEN_OPERATOR
} token_type;

typedef struct {
  token_type type;
  char *value;
} token;

char *keywords[] = {"int", "float", "char", "void", "main"};
char *delimiters[] = {"(", ")", "{", "}", "[", "]", ";"};
char *operators[] = {"+", "-", "*", "/"};

int main() {
  // Get input from the user
  char *input = malloc(10000);
  printf("Enter your C code:\n");
  gets(input);

  // Tokenize the input
  int token_count = 0;
  token tokens[MAX_TOKENS];
  char *ptr = input;
  while (*ptr != '\0') {
    // Skip whitespace
    while (isspace(*ptr)) {
      ptr++;
    }

    // Check for keywords
    for (int i = 0; i < KEYWORD_COUNT; i++) {
      if (strncmp(ptr, keywords[i], strlen(keywords[i])) == 0) {
        tokens[token_count].type = TOKEN_KEYWORD;
        tokens[token_count].value = strdup(keywords[i]);
        ptr += strlen(keywords[i]);
        token_count++;
        break;
      }
    }

    // Check for identifiers
    if (isalpha(*ptr)) {
      char *identifier = malloc(MAX_TOKEN_LENGTH);
      int identifier_length = 0;
      while (isalnum(*ptr)) {
        identifier[identifier_length++] = *ptr++;
      }
      identifier[identifier_length] = '\0';
      tokens[token_count].type = TOKEN_IDENTIFIER;
      tokens[token_count].value = identifier;
      token_count++;
    }

    // Check for strings
    if (*ptr == '"') {
      char *string = malloc(MAX_TOKEN_LENGTH);
      int string_length = 0;
      ptr++;
      while (*ptr != '"' && *ptr != '\0') {
        string[string_length++] = *ptr++;
      }
      string[string_length] = '\0';
      tokens[token_count].type = TOKEN_STRING;
      tokens[token_count].value = string;
      ptr++;
      token_count++;
    }

    // Check for numbers
    if (isdigit(*ptr)) {
      char *number = malloc(MAX_TOKEN_LENGTH);
      int number_length = 0;
      while (isdigit(*ptr)) {
        number[number_length++] = *ptr++;
      }
      number[number_length] = '\0';
      tokens[token_count].type = TOKEN_NUMBER;
      tokens[token_count].value = number;
      token_count++;
    }

    // Check for delimiters
    for (int i = 0; i < DELIMITER_COUNT; i++) {
      if (*ptr == delimiters[i]) {
        tokens[token_count].type = TOKEN_DELIMITER;
        tokens[token_count].value = strdup(delimiters[i]);
        ptr++;
        token_count++;
        break;
      }
    }

    // Check for operators
    for (int i = 0; i < OPERATOR_COUNT; i++) {
      if (*ptr == operators[i]) {
        tokens[token_count].type = TOKEN_OPERATOR;
        tokens[token_count].value = strdup(operators[i]);
        ptr++;
        token_count++;
        break;
      }
    }
  }

  // Print the tokens
  printf("Tokens:\n");
  for (int i = 0; i < token_count; i++) {
    switch (tokens[i].type) {
      case TOKEN_KEYWORD:
        printf("Keyword: %s\n", tokens[i].value);
        break;
      case TOKEN_IDENTIFIER:
        printf("Identifier: %s\n", tokens[i].value);
        break;
      case TOKEN_STRING:
        printf("String: %s\n", tokens[i].value);
        break;
      case TOKEN_NUMBER:
        printf("Number: %s\n", tokens[i].value);
        break;
      case TOKEN_DELIMITER:
        printf("Delimiter: %s\n", tokens[i].value);
        break;
      case TOKEN_OPERATOR:
        printf("Operator: %s\n", tokens[i].value);
        break;
    }
  }

  // Free the memory allocated for the tokens
  for (int i = 0; i < token_count; i++) {
    free(tokens[i].value);
  }
  free(input);

  return 0;
}