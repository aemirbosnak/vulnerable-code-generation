#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  char text[1024];
  int word_count = 0;

  printf("Enter filename: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s", filename);
    return 1;
  }

  printf("Enter text: ");
  scanf("%s", text);

  fprintf(file, "%s", text);
  fclose(file);

  word_count = count_words(text);
  printf("Number of words in file: %d", word_count);

  return 0;
}

int count_words(char *text) {
  int word_count = 0;
  char *word = strtok(text, " ");

  while (word) {
    word_count++;
    word = strtok(NULL, " ");
  }

  return word_count;
}
