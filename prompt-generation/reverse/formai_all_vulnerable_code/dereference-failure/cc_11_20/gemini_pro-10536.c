//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  FILE *input_file, *output_file;
  char line[MAX_LINE_LENGTH];
  int line_number = 0;
  int indent_level = 0;
  int in_tag = 0;
  int in_string = 0;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
    return EXIT_FAILURE;
  }

  input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
    line_number++;

    if (in_string) {
      if (strchr(line, '"') != NULL) {
        in_string = 0;
      }
    } else if (in_tag) {
      if (strchr(line, '>') != NULL) {
        in_tag = 0;
        indent_level--;
      }
    } else {
      if (strchr(line, '<') != NULL) {
        in_tag = 1;
        indent_level++;
      } else if (strchr(line, '"') != NULL) {
        in_string = 1;
      }
    }

    for (int i = 0; i < indent_level; i++) {
      fprintf(output_file, "  ");
    }

    fprintf(output_file, "%s", line);
  }

  fclose(input_file);
  fclose(output_file);

  return EXIT_SUCCESS;
}