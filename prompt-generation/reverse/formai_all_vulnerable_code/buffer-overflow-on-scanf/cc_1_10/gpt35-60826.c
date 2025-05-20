//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[100];
  char c;

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  
  if (fp == NULL) {
    printf("Error: cannot open file '%s'\n", filename);
    return 1;
  }

  int indent_level = 0;
  int indent_spaces = 4;

  printf("<html>\n");

  while ((c = fgetc(fp)) != EOF) {
    if (c == '<') {
      printf("%c", c);
      if (fgetc(fp) == '/') {
        indent_level--;
      } else {
        indent_level++;
      }
      printf("\n");
      for (int i = 0; i < indent_level * indent_spaces; i++) {
        printf(" ");
      }
      fseek(fp, -1, SEEK_CUR); // Rewind file pointer by 1 to print the tag name
    } else if (c == '>') {
      printf("%c\n", c);
    } else {
      printf("%c", c);
      if (c == '\n') {
        for (int i = 0; i < indent_level * indent_spaces; i++) {
          printf(" ");
        }
      }
    }
  }

  printf("</html>\n");

  fclose(fp);
  return 0;
}