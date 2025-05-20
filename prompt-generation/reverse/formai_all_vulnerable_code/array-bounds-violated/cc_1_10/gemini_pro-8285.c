//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <string.h>

// Defines the maximum length of a sentence.
#define MAX_SENTENCE_LENGTH 1024

// Defines the number of sentiment scores.
#define NUM_SENTIMENT_SCORES 3

// Defines the sentiment scores.
const char *SENTIMENT_SCORES[] = {"negative", "neutral", "positive"};

// Recursively performs sentiment analysis on a sentence.
char *sentiment_analysis_recursive(char *sentence, int start, int end) {
  // Check if the sentence is empty.
  if (start >= end) {
    return NULL;
  }

  // Find the midpoint of the sentence.
  int midpoint = (start + end) / 2;

  // Recursively perform sentiment analysis on the left half of the sentence.
  char *left_sentiment = sentiment_analysis_recursive(sentence, start, midpoint);

  // Recursively perform sentiment analysis on the right half of the sentence.
  char *right_sentiment = sentiment_analysis_recursive(sentence, midpoint + 1, end);

  // Combine the sentiment scores of the left and right halves of the sentence.
  char *combined_sentiment;
  if (left_sentiment == NULL && right_sentiment == NULL) {
    combined_sentiment = NULL;
  } else if (left_sentiment == NULL) {
    combined_sentiment = right_sentiment;
  } else if (right_sentiment == NULL) {
    combined_sentiment = left_sentiment;
  } else if (strcmp(left_sentiment, right_sentiment) == 0) {
    combined_sentiment = left_sentiment;
  } else {
    combined_sentiment = "mixed";
  }

  // Return the combined sentiment score.
  return combined_sentiment;
}

// Performs sentiment analysis on a sentence.
char *sentiment_analysis(char *sentence) {
  // Check if the sentence is empty.
  if (sentence == NULL || strlen(sentence) == 0) {
    return NULL;
  }

  // Remove all punctuation from the sentence.
  int i;
  for (i = 0; i < strlen(sentence); i++) {
    if (ispunct(sentence[i])) {
      sentence[i] = ' ';
    }
  }

  // Convert the sentence to lowercase.
  for (i = 0; i < strlen(sentence); i++) {
    sentence[i] = tolower(sentence[i]);
  }

  // Recursively perform sentiment analysis on the sentence.
  char *sentiment = sentiment_analysis_recursive(sentence, 0, strlen(sentence) - 1);

  // Return the sentiment score.
  return sentiment;
}

// Get the sentiment score of a sentence from the user.
char *get_sentiment_score() {
  // Prompt the user to enter a sentence.
  printf("Enter a sentence: ");

  // Read the sentence from the user.
  char sentence[MAX_SENTENCE_LENGTH];
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  // Remove the newline character from the sentence.
  sentence[strlen(sentence) - 1] = '\0';

  // Perform sentiment analysis on the sentence.
  char *sentiment = sentiment_analysis(sentence);

  // Return the sentiment score.
  return sentiment;
}

// Print the sentiment score of a sentence.
void print_sentiment_score(char *sentiment) {
  // Check if the sentiment score is valid.
  if (sentiment == NULL) {
    printf("Invalid sentiment score.\n");
  } else {
    printf("The sentiment score is %s.\n", sentiment);
  }
}

// Main function.
int main() {
  // Get the sentiment score of a sentence from the user.
  char *sentiment = get_sentiment_score();

  // Print the sentiment score of the sentence.
  print_sentiment_score(sentiment);

  return 0;
}