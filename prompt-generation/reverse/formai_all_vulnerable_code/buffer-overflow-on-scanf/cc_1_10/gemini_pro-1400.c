//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// Define the sentiment scores for each word
int sentiment_scores[] = {
  [0] = -1,  // "bad"
  [1] = 1,   // "good"
  [2] = -2,  // "terrible"
  [3] = 2,   // "excellent"
  [4] = -3,  // "worst"
  [5] = 3    // "best"
};

// Function to calculate the sentiment score of a sentence
int calculate_sentiment(char *sentence) {
  // Tokenize the sentence into words
  char *words[MAX_SENTENCE_LENGTH];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment score for each word
  int sentiment_score = 0;
  for (int i = 0; i < num_words; i++) {
    int word_score = sentiment_scores[atoi(words[i])];
    sentiment_score += word_score;
  }

  return sentiment_score;
}

// Function to print the sentiment of a sentence
void print_sentiment(char *sentence) {
  int sentiment_score = calculate_sentiment(sentence);
  if (sentiment_score > 0) {
    printf("The sentence \"%s\" is positive.\n", sentence);
  } else if (sentiment_score < 0) {
    printf("The sentence \"%s\" is negative.\n", sentence);
  } else {
    printf("The sentence \"%s\" is neutral.\n", sentence);
  }
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Print the sentiment of the sentence
  print_sentiment(sentence);

  return 0;
}