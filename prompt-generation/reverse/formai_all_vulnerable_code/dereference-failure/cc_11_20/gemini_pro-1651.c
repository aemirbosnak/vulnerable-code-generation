//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <xml file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
    char *start = line;
    while (*start != '\0') {
      if (*start == '<') {
        char *end = strchr(start, '>');
        if (end == NULL) {
          fprintf(stderr, "Unterminated tag: %s\n", start);
          return EXIT_FAILURE;
        }
        *end = '\0';
        printf("Tag: %s\n", start + 1);
        start = end + 1;
      } else if (*start == '&') {
        char *end = strchr(start, ';');
        if (end == NULL) {
          fprintf(stderr, "Unterminated entity: %s\n", start);
          return EXIT_FAILURE;
        }
        *end = '\0';
        printf("Entity: %s\n", start + 1);
        start = end + 1;
      } else {
        char *end = strchr(start, '<');
        if (end == NULL) {
          end = strchr(start, '&');
          if (end == NULL) {
            end = line + strlen(line);
          }
        }
        *end = '\0';
        printf("Text: %s\n", start);
        start = end;
      }
    }
  }

  fclose(fp);

  return EXIT_SUCCESS;
}