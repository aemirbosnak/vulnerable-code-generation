//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, fp)) != -1) {
    // Remove leading and trailing whitespace
    char *start = line;
    while (*start == ' ' || *start == '\t') {
      start++;
    }
    char *end = line + read - 1;
    while (end >= start && (*end == ' ' || *end == '\t')) {
      end--;
    }

    // Replace < with &lt; and > with &gt;
    char *ptr = start;
    while (*ptr != '\0') {
      if (*ptr == '<') {
        *ptr = '&';
        ptr++;
        *ptr = 'l';
        ptr++;
        *ptr = 't';
      } else if (*ptr == '>') {
        *ptr = '&';
        ptr++;
        *ptr = 'g';
        ptr++;
        *ptr = 't';
      }
      ptr++;
    }

    // Print the beautified line
    printf("%s\n", start);
  }

  fclose(fp);
  free(line);

  return 0;
}