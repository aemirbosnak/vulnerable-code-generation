//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    int len = strlen(line);
    int i;

    // Remove leading whitespace
    for (i = 0; i < len && isspace(line[i]); i++)
      ;

    // Remove trailing whitespace
    for (i = len - 1; i >= 0 && isspace(line[i]); i--)
      ;

    // Beautify the line
    char *out = malloc(len + 1);
    int out_len = 0;
    int indent = 0;
    for (i = 0; i <= len; i++) {
      char c = line[i];

      if (c == '<') {
        out[out_len++] = c;
        indent++;
      } else if (c == '>') {
        out[out_len++] = c;
        indent--;
      } else if (isspace(c)) {
        if (line[i + 1] != '\0') {
          out[out_len++] = ' ';
        }
      } else {
        out[out_len++] = c;
      }
    }

    // Print the beautified line
    for (i = 0; i < indent; i++) {
      printf("  ");
    }
    printf("%s", out);
    free(out);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}