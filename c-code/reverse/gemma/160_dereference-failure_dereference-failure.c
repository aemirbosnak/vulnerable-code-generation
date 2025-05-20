#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp, *fp2;
  char *line, **wordList = NULL, **wordFreq = NULL;
  int wordCount = 0, i, j, maxFreq = 0;

  fp = fopen("text.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  wordList = malloc(sizeof(char *) * 100);
  wordFreq = malloc(sizeof(int) * 100);

  while (getline(fp, line, 100) != -1) {
    char *word = strtok(line, " ");
    while (word) {
      wordList[wordCount] = strdup(word);
      wordFreq[wordCount] = 0;
      wordCount++;
      word = strtok(NULL, " ");
    }
  }

  fclose(fp);

  for (i = 0; i < wordCount; i++) {
    for (j = 0; j < wordCount; j++) {
      if (wordList[i] == wordList[j]) {
        wordFreq[i]++;
      }
    }
  }

  maxFreq = wordFreq[0];
  for (i = 1; i < wordCount; i++) {
    if (wordFreq[i] > maxFreq) {
      maxFreq = wordFreq[i];
    }
  }

  fp2 = fopen("results.txt", "w");
  fprintf(fp2, "Word frequency:\n");
  for (i = 0; i < wordCount; i++) {
    fprintf(fp2, "%s: %d\n", wordList[i], wordFreq[i]);
  }

  fclose(fp2);

  return 0;
}
