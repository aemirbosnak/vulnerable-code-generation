#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

int main() {
  char sentence[MAX_WORDS];
  int i, word_count = 0, positive_words = 0, negative_words = 0;
  char words[MAX_WORDS][20];

  printf("Enter a sentence: ");
  gets(sentence);

  // Convert sentence to uppercase and split it into words
  for (i = 0; sentence[i] != '\0'; i++) {
    sentence[i] = toupper(sentence[i]);
  }
  char *word = strtok(sentence, " ");
  while (word) {
    strcpy(words[word_count], word);
    word_count++;
    word = strtok(NULL, " ");
  }

  // Count positive and negative words
  for (i = 0; i < word_count; i++) {
    if (strcmp(words[i], "good") == 0 || strcmp(words[i], "happy") == 0 || strcmp(words[i], "excellent") == 0) {
      positive_words++;
    } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "sad") == 0 || strcmp(words[i], "terrible") == 0) {
      negative_words++;
    }
  }

  // Print the sentiment analysis results
  printf("Positive words: %d\n", positive_words);
  printf("Negative words: %d\n", negative_words);

  return 0;
}
