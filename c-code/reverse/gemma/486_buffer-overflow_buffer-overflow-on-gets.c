#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  gets(sentence);

  int positive_words_count = 0;
  char* positive_words[] = {"happy", "joy", "good", "excellent", "wonderful"};
  for (int i = 0; i < 5; i++) {
    if (strstr(sentence, positive_words[i]) != NULL) {
      positive_words_count++;
    }
  }

  int negative_words_count = 0;
  char* negative_words[] = {"sad", "angry", "bad", "terrible", "awful"};
  for (int i = 0; i < 5; i++) {
    if (strstr(sentence, negative_words[i]) != NULL) {
      negative_words_count++;
    }
  }

  if (positive_words_count > negative_words_count) {
    printf("Sentiment: Positive\n");
  } else if (negative_words_count > positive_words_count) {
    printf("Sentiment: Negative\n");
  } else {
    printf("Sentiment: Neutral\n");
  }

  return 0;
}
