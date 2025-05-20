//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>

// function to calculate sentiment score using mathematical approach
float calculate_sentiment_score(char* review) {
  float sentiment_score = 0.0;
  int pos_count = 0;
  int neg_count = 0;
  int word_count = 0;

  char word[50];
  for (int i=0; i<strlen(review); i++) {
    int j = 0;
    while (review[i] != ' ' && review[i] != '\0') {
      word[j] = review[i];
      i++;
      j++;
    }
    word[j] = '\0';
    word_count++;

    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
      pos_count++;
      sentiment_score += 1.0;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0) {
      neg_count++;
      sentiment_score -= 1.0;
    }
  }

  float pos_freq = (float) pos_count / (float) word_count;
  float neg_freq = (float) neg_count / (float) word_count;
  float ratio = pos_freq / neg_freq;
  float sentiment_index = sentiment_score / (float) word_count;

  if (ratio > 2) {
    sentiment_index += 1.0;
  } else if (ratio < 0.5) {
    sentiment_index -= 1.0;
  }

  return sentiment_index;
}

int main() {
  char review[1000];
  printf("Enter your review: ");
  fgets(review, 1000, stdin);
  float sentiment_score = calculate_sentiment_score(review);
  printf("Sentiment score for the review is: %f", sentiment_score);
  return 0;
}