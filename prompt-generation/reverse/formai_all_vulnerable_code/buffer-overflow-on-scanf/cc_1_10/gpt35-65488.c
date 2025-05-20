//FormAI DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  FILE *fptr;
  char filename[100], c;

  printf("Enter the name of the file to be beautified: ");
  scanf("%s", filename);

  fptr = fopen(filename, "r");

  if (fptr == NULL) {
    printf("Unable to open file.\n");
    exit(1);
  }

  printf("/* Beautified Code */\n\n");

  int indent_level = 0;
  int braces_needed = 0;

  while ((c = fgetc(fptr)) != EOF) {
    if (c == '{') {
      printf("{\n");
      indent_level++;
      braces_needed = 1;
    } else if (c == '}') {
      indent_level--;
      for (int i = 0; i < indent_level; i++) {
        printf("\t");
      }
      printf("}\n");
    } else if (c == ';') {
      printf(";\n");
      braces_needed = 0;
    } else {
      if (braces_needed) {
        for (int i = 0; i < indent_level; i++) {
          printf("\t");
        }
        braces_needed = 0;
      }
      putchar(c);
    }
  }

  fclose(fptr);
  return 0;
}