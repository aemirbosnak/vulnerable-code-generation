#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("words.txt", "r");
  int numWords = 0;
  char** words = NULL;
  char word[20];

  fscanf(file, "%d", &numWords);
  words = malloc(numWords * sizeof(char*));

  for (int i = 0; i < numWords; i++) {
    fscanf(file, "%s", word);
    words[i] = strdup(word);
  }

  int wordFreq[numWords];
  for (int i = 0; i < numWords; i++) {
    wordFreq[i] = 1;
    for (int j = 0; j < numWords; j++) {
      if (words[i] == words[j]) {
        wordFreq[i]++;
      }
    }
  }

  printf("Word frequencies:\n");
  for (int i = 0; i < numWords; i++) {
    printf("%s: %d\n", words[i], wordFreq[i]);
  }

  fclose(file);
  free(words);

  return 0;
}
