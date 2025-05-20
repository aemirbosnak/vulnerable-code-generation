#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp, *fpw;
  char *buffer, *word;
  int word_count = 0, frequency[1000] = {0}, i, j;

  fp = fopen("text.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  buffer = malloc(1000);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return 1;
  }

  word = malloc(20);
  if (word == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    free(buffer);
    return 1;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    word_count++;
    frequency[word_count] = 1;
  }

  fclose(fp);

  for (i = 1; i <= word_count; i++) {
    for (j = i; frequency[j] > frequency[i]; j--) {
      int temp = frequency[j];
      frequency[j] = frequency[i];
      frequency[i] = temp;
    }
  }

  fpw = fopen("results.txt", "w");
  if (fpw == NULL) {
    perror("Error opening file");
    free(buffer);
    free(word);
    return 1;
  }

  fprintf(fpw, "Word frequencies:\n");
  for (i = 1; i <= word_count; i++) {
    fprintf(fpw, "%s: %d\n", word[i], frequency[i]);
  }

  fclose(fpw);

  free(buffer);
  free(word);

  return 0;
}
