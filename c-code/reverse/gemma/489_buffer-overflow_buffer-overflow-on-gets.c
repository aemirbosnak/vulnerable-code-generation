#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  int positive_words = 0;
  int negative_words = 0;

  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Convert sentence to lowercase
  char lower_sentence[100];
  strcpy(lower_sentence, sentence);
  lower_sentence[strcspn(lower_sentence, "abcdefghijklmnopqrstuvwxyz")] = '\0';

  // Count positive and negative words
  char* words = lower_sentence;
  while (words) {
    char word[20];
    int i = 0;
    for (; words[i] && words[i] != ' '; i++) {
      word[i] = words[i];
    }
    word[i] = '\0';

    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
      positive_words++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
      negative_words++;
    }

    words = strchr(words, ' ') + 1;
  }

  // Determine sentiment
  int sentiment = 0;
  if (positive_words > negative_words) {
    sentiment = 1;
  } else if (negative_words > positive_words) {
    sentiment = -1;
  } else {
    sentiment = 0;
  }

  // Print sentiment
  switch (sentiment) {
    case 1:
      printf("Sentiment: Positive\n");
      break;
    case -1:
      printf("Sentiment: Negative\n");
      break;
    case 0:
      printf("Sentiment: Neutral\n");
      break;
  }

  return 0;
}
