//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input_file)) {
    // Remove leading and trailing whitespace
    char *trimmed_line = strdup(line);
    while (*trimmed_line == ' ' || *trimmed_line == '\t') {
      trimmed_line++;
    }
    int len = strlen(trimmed_line);
    while (len > 0 && (trimmed_line[len - 1] == ' ' || trimmed_line[len - 1] == '\t')) {
      len--;
    }
    trimmed_line[len] = '\0';

    // Indent the line
    char indented_line[MAX_LINE_LENGTH];
    int indent_level = 0;
    for (int i = 0; i < len; i++) {
      if (trimmed_line[i] == '<') {
        indent_level++;
      } else if (trimmed_line[i] == '>') {
        indent_level--;
      }
      indented_line[i] = ' ';
    }
    for (int i = 0; i < indent_level; i++) {
      indented_line[i] = '\t';
    }
    strcat(indented_line, trimmed_line);

    // Print the indented line
    printf("%s\n", indented_line);

    free(trimmed_line);
  }

  fclose(input_file);

  return EXIT_SUCCESS;
}