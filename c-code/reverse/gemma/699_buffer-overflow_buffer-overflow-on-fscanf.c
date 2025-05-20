#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char *line = NULL;
  size_t linecap = 0;
  int wordCount = 0;
  int uniqueWordCount = 0;
  char **wordList = NULL;

  fp = fopen("log.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  while (getline(&line, &linecap, fp) != -1) {
    char *word = strtok(line, " ");
    while (word) {
      int i = 0;
      for (i = 0; wordList[i] && strcmp(wordList[i], word) != 0; i++) {}
      if (wordList[i] == NULL) {
        wordList = realloc(wordList, (uniqueWordCount + 1) * sizeof(char *));
        wordList[uniqueWordCount++] = strdup(word);
      }
      word = strtok(NULL, " ");
    }
  }

  fclose(fp);

  printf("Word count: %d\n", wordCount);
  printf("Unique word count: %d\n", uniqueWordCount);

  return 0;
}
