//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  FILE *file_in = fopen("input.html", "r");
  FILE *file_out = fopen("output.html", "w");
  char c;
  int indent = 0;
  int new_line = 1;

  if (!file_in) {
    fprintf(stderr, "Could not open input file.\n");
    exit(1);
  }
  if (!file_out) {
    fprintf(stderr, "Could not open output file.\n");
    exit(1);
  }

  while ((c = fgetc(file_in)) != EOF) {
    switch(c) {
      case '<':
        fputc(c, file_out);
        if (new_line) {
          indent++;
          fprintf(file_out, "\n");
          for (int i = 0; i < indent; i++) {
            fprintf(file_out, "  ");
          }
          new_line = 0;
        }
        break;
      case '>':
        fputc(c, file_out);
        new_line = 1;
        break;
      case '\n':
      case ' ':
      case '\t':
        break;
      default:
        fputc(c, file_out);
        if (new_line) {
          fprintf(file_out, "\n");
          for (int i = 0; i < indent; i++) {
            fprintf(file_out, "  ");
          }
          new_line = 0;
        }
        break;
    }
  }

  fclose(file_in);
  fclose(file_out);
  return 0;
}