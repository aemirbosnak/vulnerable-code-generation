//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return 1;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    perror("fopen");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
    char *p = line;

    // Remove leading whitespace
    while (*p && isspace(*p)) {
      p++;
    }

    // Remove trailing whitespace
    char *end = p + strlen(p) - 1;
    while (end >= p && isspace(*end)) {
      end--;
    }

    // Remove empty lines
    if (p == end) {
      continue;
    }

    // Convert tabs to spaces
    char *q = p;
    while (*q) {
      if (*q == '\t') {
        *q = ' ';
      }
      q++;
    }

    // Beautify HTML tags
    char *tag = p;
    while (*tag) {
      if (*tag == '<') {
        // Find the end of the tag
        char *end_tag = strchr(tag, '>');
        if (end_tag == NULL) {
          break;
        }

        // Beautify the tag
        char *attr = strchr(tag, ' ');
        if (attr == NULL) {
          attr = end_tag;
        }

        printf("%s\n", tag);
        printf("%s", attr);
        printf("%s\n\n", end_tag);

        // Advance to the next character after the tag
        tag = end_tag + 1;
      } else {
        // Print the character
        printf("%c", *tag);

        // Advance to the next character
        tag++;
      }
    }
  }

  fclose(input);
  return 0;
}