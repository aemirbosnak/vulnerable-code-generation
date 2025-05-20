//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentiment
#define MAX_SENTIMENT_LENGTH 1024

// Define the number of sentiments
#define NUM_SENTIMENTS 5

// Define the sentiment values
const char *sentiments[NUM_SENTIMENTS] = {"positive", "negative", "neutral", "unknown", "error"};

// Define the sentiment scores
const int sentiment_scores[NUM_SENTIMENTS] = {1, -1, 0, 0, 0};

// Function to get the sentiment of a string
int get_sentiment(const char *string) {
  // Check if the string is empty
  if (string == NULL || strlen(string) == 0) {
    return -1;
  }

  // Iterate over the sentiments
  for (int i = 0; i < NUM_SENTIMENTS; i++) {
    // Check if the string contains the sentiment
    if (strstr(string, sentiments[i]) != NULL) {
      // Return the sentiment score
      return sentiment_scores[i];
    }
  }

  // Return an error code
  return -1;
}

// Main function
int main() {
  // Get the input string
  char *string = malloc(MAX_SENTIMENT_LENGTH);
  printf("Enter a string: ");
  scanf("%s", string);

  // Get the sentiment of the string
  int sentiment = get_sentiment(string);

  // Print the sentiment
  printf("The sentiment of the string is: %s\n", sentiments[sentiment]);

  // Free the allocated memory
  free(string);

  return 0;
}