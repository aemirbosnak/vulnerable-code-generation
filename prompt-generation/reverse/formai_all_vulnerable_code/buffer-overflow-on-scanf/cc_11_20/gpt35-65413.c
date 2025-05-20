//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  FILE *file;
  char filename[100];
  char c;

  printf("Enter file name: ");
  scanf("%s", filename);

  file = fopen(filename, "r");

  if (file) {
    while ((c = fgetc(file)) != EOF) {
      if (c == '<') {
        fputc(c, stdout);
        c = fgetc(file);
        if (c != '/') {
          while (isgraph(c)) {
            fputc(c, stdout);
            c = fgetc(file);
          }
          while (c != '>') {
            fputc(c, stdout);
            c = fgetc(file);
          }
        } else {
          while (c != '>') {
            fputc(c, stdout);
            c = fgetc(file);
          }
          fputc(c, stdout);
        }
      } else if (c == '/') {
        fputc(c, stdout);
        if ((c = fgetc(file)) == '>') {
          fputc(c, stdout);
        } else {
          fputc(c, stdout);
          while ((c = fgetc(file)) != '>') {
            fputc(c, stdout);
          }
        }
      } else {
        fputc(c, stdout);
      }
    }
    fclose(file);
  } else {
    printf("Unable to open file\n");
  }

  return 0;
}