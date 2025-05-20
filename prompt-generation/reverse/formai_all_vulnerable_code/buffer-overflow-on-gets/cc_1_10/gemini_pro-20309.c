//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct {
  char *word;
  int polarity;
} WordPolarity;
 
WordPolarity word_list[] = {
  {"great", 1},
  {"good", 1},
  {"wonderful", 1},
  {"excellent", 1},
  {"amazing", 1},
  {"bad", -1},
  {"terrible", -1},
  {"awful", -1},
  {"horrible", -1}
};
 
int get_word_polarity(char *word) {
  for (int i = 0; i < sizeof(word_list) / sizeof(WordPolarity); i++) {
    if (strcmp(word, word_list[i].word) == 0) {
      return word_list[i].polarity;
    }
  }
  return 0;
}
 
int analyze_sentiment(char *text) {
  char *token = strtok(text, " ");
  int total_polarity = 0;
 
  while (token != NULL) {
    int polarity = get_word_polarity(token);
    total_polarity += polarity;
    token = strtok(NULL, " ");
  }
 
  return total_polarity;
}
 
int main() {
  char text[100];
  printf("Enter text to analyze: ");
  gets(text);
 
  int sentiment = analyze_sentiment(text);
 
  if (sentiment > 0) {
    printf("Positive sentiment\n");
  } else if (sentiment < 0) {
    printf("Negative sentiment\n");
  } else {
    printf("Neutral sentiment\n");
  }
 
  return 0;
}