//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 20

int main() {
  char input[1000];
  char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
  int token_count = 0;
  int i, j, k;

  printf("Enter input: ");
  scanf("%[^\n]", input);

  char *saveptr;
  char *token = strtok_r(input, " ", &saveptr);
  while (token != NULL && token_count < MAX_TOKENS) {
    strcpy(tokens[token_count], token);
    token_count++;
    token = strtok_r(NULL, " ", &saveptr);
  }

  printf("Tokenized input:\n");
  for (i = 0; i < token_count; i++) {
    printf("%s\n", tokens[i]);
  }

  printf("\nParsing:\n");

  for (i = 0; i < token_count; i++) {
    if (strcmp(tokens[i], "int") == 0) {
      for (j = i + 1; j < token_count; j++) {
        if (tokens[j][strlen(tokens[j]) - 1] == ';') {
          printf("Variable %s declared.\n", tokens[j]);
          break;
        } else if (tokens[j][strlen(tokens[j]) - 1] == ',') {
          printf("Variable %s declared.\n", tokens[j]);
        } else {
          printf("Error: unexpected token %s.\n", tokens[j]);
        }
      }
    } else if (strcmp(tokens[i], "if") == 0) {
      printf("if statement found.\n");
    } else if (strcmp(tokens[i], "else") == 0) {
      printf("else statement found.\n");
    } else if (strcmp(tokens[i], "while") == 0) {
      printf("while loop found.\n");
    } else if (strcmp(tokens[i], "for") == 0) {
      printf("for loop found.\n");
    } else {
      printf("Error: unexpected token %s.\n", tokens[i]);
    }
  }

  return 0;
}