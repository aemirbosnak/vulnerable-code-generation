//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  int line_number = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    line_number++;

    // Strip leading and trailing whitespace
    char *trimmed_line = strdup(line);
    while (*trimmed_line != '\0' && isspace(*trimmed_line)) {
      trimmed_line++;
    }
    while (strlen(trimmed_line) > 0 && isspace(trimmed_line[strlen(trimmed_line) - 1])) {
      trimmed_line[strlen(trimmed_line) - 1] = '\0';
    }

    // If the line is empty, skip it
    if (strlen(trimmed_line) == 0) {
      free(trimmed_line);
      continue;
    }

    // Beautify the line
    char *beautified_line = malloc(MAX_LINE_LENGTH * 2);
    int beautified_line_length = 0;
    int indent_level = 0;
    for (char *c = trimmed_line; *c != '\0'; c++) {
      switch (*c) {
        case '<':
          if (beautified_line_length > 0) {
            beautified_line[beautified_line_length++] = '\n';
          }
          for (int i = 0; i < indent_level; i++) {
            beautified_line[beautified_line_length++] = '  ';
          }
          beautified_line[beautified_line_length++] = '<';
          indent_level++;
          break;
        case '>':
          indent_level--;
          for (int i = 0; i < indent_level; i++) {
            beautified_line[beautified_line_length++] = '  ';
          }
          beautified_line[beautified_line_length++] = '>';
          break;
        default:
          beautified_line[beautified_line_length++] = *c;
      }
    }
    beautified_line[beautified_line_length] = '\0';

    // Print the beautified line
    printf("%s\n", beautified_line);

    // Free the allocated memory
    free(trimmed_line);
    free(beautified_line);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}