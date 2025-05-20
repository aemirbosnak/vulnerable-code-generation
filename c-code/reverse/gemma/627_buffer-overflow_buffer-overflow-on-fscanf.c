#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  char action;
  int word_count = 0;

  printf("Enter action (c/r/w/w/c): ");
  scanf("%c", &action);

  switch (action) {
    case 'c':
      printf("Enter file name: ");
      scanf("%s", filename);
      FILE *fp = fopen(filename, "w");
      fclose(fp);
      break;
    case 'r':
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "r");
      word_count = count_words(fp);
      printf("Word count: %d\n", word_count);
      fclose(fp);
      break;
    case 'w':
      printf("Enter file name: ");
      scanf("%s", filename);
      fp = fopen(filename, "w");
      printf("Enter text: ");
      char text[256];
      scanf("%s", text);
      fprintf(fp, "%s", text);
      fclose(fp);
      break;
  }

  return 0;
}

int count_words(FILE *fp) {
  char word[256];
  int word_count = 0;

  while (fscanf(fp, "%s", word) != EOF) {
    word_count++;
  }

  return word_count;
}
