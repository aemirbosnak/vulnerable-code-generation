//Falcon-180B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

char *trim_whitespace(char *str) {
  char *end;

  // Trim leading space
  while (isspace(*str)) str++;

  if (*str == 0) {
    // All spaces
    str = (char *) malloc(sizeof(char));
    *str = '\0';
  } else {
    // Copy the string
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
    str = strdup(str);
  }

  return str;
}

void tokenize(char *line, char **tokens) {
  char *token = strtok(line, " ");
  int i = 0;

  while (token!= NULL) {
    tokens[i++] = trim_whitespace(token);
    token = strtok(NULL, " ");
  }

  tokens[i] = NULL;
}

int main(int argc, char *argv[]) {
  FILE *file;
  char line[MAX_LINE_SIZE];
  char **tokens;
  int num_tokens;

  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }

  while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
    num_tokens = 0;
    tokens = (char **) malloc(sizeof(char *) * MAX_WORD_SIZE);

    tokenize(line, tokens);

    for (int i = 0; tokens[i]!= NULL; i++) {
      printf("%s ", tokens[i]);
    }

    printf("\n");

    for (int i = 0; tokens[i]!= NULL; i++) {
      free(tokens[i]);
    }

    free(tokens);
  }

  fclose(file);

  return 0;
}