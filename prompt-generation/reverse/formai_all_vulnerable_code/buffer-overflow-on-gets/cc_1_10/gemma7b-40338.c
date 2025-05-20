//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char sentiment[1000];
  printf("Enter a sentence: ");
  gets(sentiment);

  // Sentiment analysis
  int sentiment_score = sentiment_analysis(sentiment);

  // Display sentiment score
  if (sentiment_score > 0) {
    printf("Your sentence is positive.\n");
  } else if (sentiment_score < 0) {
    printf("Your sentence is negative.\n");
  } else {
    printf("Your sentence is neutral.\n");
  }

  return 0;
}

int sentiment_analysis(char *sentence) {
  // Count the number of positive and negative words in the sentence
  int num_positive = count_positive_words(sentence);
  int num_negative = count_negative_words(sentence);

  // Calculate the sentiment score
  int sentiment_score = (num_positive - num_negative) / 2;

  return sentiment_score;
}

int count_positive_words(char *sentence) {
  // Create an array of positive words
  char *positive_words[] = {"happy", "joy", "love", "good", "excellent", "wonderful"};

  // Iterate over the sentence and count the number of positive words
  int num_positive = 0;
  for (int i = 0; i < strlen(sentence); i++) {
    for (int j = 0; j < 6; j++) {
      if (strcmp(sentence[i], positive_words[j]) == 0) {
        num_positive++;
      }
    }
  }

  return num_positive;
}

int count_negative_words(char *sentence) {
  // Create an array of negative words
  char *negative_words[] = {"sad", "angry", "hate", "terrible", "awful", "bad"};

  // Iterate over the sentence and count the number of negative words
  int num_negative = 0;
  for (int i = 0; i < strlen(sentence); i++) {
    for (int j = 0; j < 6; j++) {
      if (strcmp(sentence[i], negative_words[j]) == 0) {
        num_negative++;
      }
    }
  }

  return num_negative;
}