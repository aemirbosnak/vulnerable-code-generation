//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

void word_frequency_counter(char **words, int word_count) {
  int i, j, word_index, frequency[MAX_WORDS] = {0};
  for (i = 0; i < word_count; i++) {
    word_index = hash_word(words[i]);
    frequency[word_index]++;
  }
  for (j = 0; j < MAX_WORDS; j++) {
    if (frequency[j] > 0) {
      printf("%s: %d\n", words[j], frequency[j]);
    }
  }
}

int hash_word(char *word) {
  int hash = 0;
  for (int i = 0; i < strlen(word); i++) {
    hash = hash * 33 + word[i];
  }
  return hash;
}

int main() {
  char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
  int word_count = 0;

  // Get the text from the user
  printf("Enter text: ");
  char text[1000];
  scanf("%[^\n]", text);

  // Split the text into words
  char *word = strtok(text, " ");
  while (word) {
    words[word_count++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the word frequency
  word_frequency_counter(words, word_count);

  // Free the memory
  free(words);

  return 0;
}