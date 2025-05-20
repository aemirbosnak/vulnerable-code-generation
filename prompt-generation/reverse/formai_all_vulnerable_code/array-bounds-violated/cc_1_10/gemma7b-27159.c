//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 10

typedef struct SentimentWord {
  char word[MAX_SENTIMENT_WORDS];
  int sentiment;
} SentimentWord;

SentimentWord sentimentWords[] = {
  {"brave", 1},
  {"noble", 1},
  {"strong", 1},
  {"good", 1},
  {"fair", 0},
  {"average", 0},
  {"weak", -1},
  {"base", -1},
  {"evil", -1},
  {"foolish", -1}
};

int analyzeSentiment(char *sentence) {
  int i = 0;
  int sentiment = 0;
  char word[MAX_SENTIMENT_WORDS];

  for (i = 0; sentence[i] != '\0'; i++) {
    word[i] = sentence[i];
  }

  for (i = 0; sentimentWords[i].word[0] != '\0'; i++) {
    if (strcmp(word, sentimentWords[i].word) == 0) {
      sentiment += sentimentWords[i].sentiment;
    }
  }

  return sentiment;
}

int main() {
  char sentence[] = "The brave knight fought bravely against the evil dragon.";
  int sentiment = analyzeSentiment(sentence);

  if (sentiment > 0) {
    printf("The sentence is positive.\n");
  } else if (sentiment < 0) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}