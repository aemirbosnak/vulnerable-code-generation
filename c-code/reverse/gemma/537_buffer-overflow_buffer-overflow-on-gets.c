#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char sentence[1000];
  printf("Enter a single-line sentence: ");
  fgets(sentence, 1000, stdin);

  // Convert sentence to lowercase and remove punctuation
  char *word = strtok(sentence, " .,!?:;()[]{}|");
  int word_count = 0;
  int word_frequency[100] = {0};

  // Count occurrences of each word
  while (word) {
    word_frequency[word_count] = 1;
    word = strtok(NULL, " .,!?:;()[]{}|");
    word_count++;
  }

  // Print word frequencies
  printf("Word frequencies:\n");
  for (int i = 0; i < word_count; i++) {
    if (word_frequency[i] > 0) {
      printf("%s: %d\n", word, word_frequency[i]);
    }
  }

  return 0;
}
