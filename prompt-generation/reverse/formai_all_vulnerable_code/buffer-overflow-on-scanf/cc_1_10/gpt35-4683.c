//FormAI DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char filename[100];
  char c;
  int words = 0;
  int lines = 0;
  int characters = 0;
  int in_word = 0;
  FILE *fp;

  printf("Enter filename: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }

  while ((c = fgetc(fp)) != EOF) {
    characters++;

    // Check for newline character
    if (c == '\n') {
      lines++;
    }

    // Check for word characters (A-Za-z).
    if (isalpha(c)) {
      if (!in_word) {
        in_word = 1;
        words++;
      }
    } else {
      in_word = 0;
    }
  }

  fclose(fp);

  printf("Words: %d\n", words);
  printf("Lines: %d\n", lines);
  printf("Characters: %d\n", characters);

  return 0;
}