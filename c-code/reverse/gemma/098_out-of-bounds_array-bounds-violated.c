#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main() {
  char filename[256];
  FILE *fp;
  char word[MAX_WORD_LENGTH];
  int word_count = 0;
  int word_length = 0;
  int i;

  printf("Enter filename: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    word_length = strlen(word);
    if (word_length > MAX_WORD_LENGTH) {
      word_length = MAX_WORD_LENGTH;
    }
    word[word_length] = '\0';
    word_count++;
  }

  fclose(fp);

  printf("Word frequency:\n");
  for (i = 0; i < word_count; i++) {
    printf("%s: %d\n", word[i], 1);
  }

  return 0;
}
