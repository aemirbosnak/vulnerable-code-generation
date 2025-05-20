#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  gets(sentence);

  char words[1024][20];
  int word_count = 0;

  // Tokenize the sentence into words
  char *word = strtok(sentence, " ");
  while (word) {
    strcpy(words[word_count], word);
    word_count++;
    word = strtok(NULL, " ");
  }

  // Count the frequency of each word
  for (int i = 0; i < word_count; i++) {
    int frequency = 0;
    for (int j = 0; j < word_count; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        frequency++;
      }
    }
    printf("%s: %d\n", words[i], frequency);
  }

  return 0;
}
