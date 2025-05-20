//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    char *p = line;

    while (*p != '\0') {
      if (*p == ' ' || *p == '\t') {
        p++;
        continue;
      }

      if (*p == ';') {
        break;
      }

      if (*p == '(') {
        p++;

        while (*p != '\0' && *p != ')') {
          p++;
        }

        if (*p == ')') {
          p++;
        }
      }

      if (*p == '{') {
        int depth = 1;

        p++;

        while (*p != '\0' && depth > 0) {
          if (*p == '{') {
            depth++;
          } else if (*p == '}') {
            depth--;
          }

          p++;
        }
      }
    }

    printf("%s", line);
  }

  fclose(fp);
  free(line);

  return EXIT_SUCCESS;
}