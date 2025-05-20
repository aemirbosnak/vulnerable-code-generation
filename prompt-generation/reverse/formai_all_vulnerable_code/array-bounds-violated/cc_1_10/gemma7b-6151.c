//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

  char sentiment_str[1000] = "I am a very happy person. I am feeling good today.";
  int sentiment_score = analyze_sentiment(sentiment_str);

  printf("The sentiment score for the string: %s is %d.\n", sentiment_str, sentiment_score);

  return 0;
}

int analyze_sentiment(char *str) {

  // Secret algorithm to analyze sentiment
  int score = 0;

  // Count the number of positive words
  int num_positive = count_positive_words(str);

  // Count the number of negative words
  int num_negative = count_negative_words(str);

  // Calculate the sentiment score
  score = (num_positive - num_negative) * 100;

  return score;
}

int count_positive_words(char *str) {

  // List of positive words
  char *positive_words[] = {"happy", "good", "joy", "peace", "love"};

  // Iterate over the string and count the number of positive words
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    for (int j = 0; positive_words[j] != NULL; j++) {
      if (strcmp(str + i, positive_words[j]) == 0) {
        count++;
      }
    }
  }

  return count;
}

int count_negative_words(char *str) {

  // List of negative words
  char *negative_words[] = {"sad", "bad", "angry", "hate", "fear"};

  // Iterate over the string and count the number of negative words
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    for (int j = 0; negative_words[j] != NULL; j++) {
      if (strcmp(str + i, negative_words[j]) == 0) {
        count++;
      }
    }
  }

  return count;
}