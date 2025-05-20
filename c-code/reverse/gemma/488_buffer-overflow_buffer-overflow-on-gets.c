#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  gets(sentence);

  int positive_words = 0;
  int negative_words = 0;

  for (int i = 0; sentence[i] != '\0'; i++) {
    char word[20];
    int word_length = 0;

    while (sentence[i] != ' ' && sentence[i] != '\0') {
      word[word_length] = sentence[i];
      word_length++;
      i++;
    }

    word[word_length] = '\0';

    if (strcmp(word, "good") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "excellent") == 0) {
      positive_words++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "sad") == 0 || strcmp(word, "terrible") == 0) {
      negative_words++;
    }
  }

  printf("Positive words: %d\n", positive_words);
  printf("Negative words: %d\n", negative_words);

  return 0;
}
