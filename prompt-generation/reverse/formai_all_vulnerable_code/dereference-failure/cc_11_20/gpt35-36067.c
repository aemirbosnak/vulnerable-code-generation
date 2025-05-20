//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10000
#define INDENTATION_WIDTH 4

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Please specify an HTML file to beautify.\n");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Cannot open file %s\n", argv[1]);
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  int indentation_level = 0;

  printf("<!DOCTYPE html>\n");
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    char *trimmed_line = strdup(line);
    char *p = trimmed_line;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
      p++;
    }
    int indentation = (int) (p - trimmed_line);

    if (strlen(trimmed_line) > 0) {
      if (trimmed_line[0] == '<' && trimmed_line[strlen(trimmed_line) - 2] != '/') {  // opening tag
        for (int i = 0; i < indentation_level * INDENTATION_WIDTH; i++) {
          printf(" ");
        }
        printf("%s", trimmed_line);
        indentation_level++;
      } else if (trimmed_line[0] == '<' && trimmed_line[strlen(trimmed_line) - 2] == '/') {  // self-closing tag
        for (int i = 0; i < indentation_level * INDENTATION_WIDTH; i++) {
          printf(" ");
        }
        printf("%s", trimmed_line);
      } else if (strlen(trimmed_line) > 1 && trimmed_line[0] == '<' && trimmed_line[1] == '/') {  // closing tag
        indentation_level--;
        for (int i = 0; i < indentation_level * INDENTATION_WIDTH; i++) {
          printf(" ");
        }
        printf("%s", trimmed_line);
      } else {  // text or attribute
        for (int i = 0; i < indentation_level * INDENTATION_WIDTH; i++) {
          printf(" ");
        }
        printf("%s", trimmed_line);
      }
    }

    free(trimmed_line);
  }

  fclose(file);

  return 0;
}