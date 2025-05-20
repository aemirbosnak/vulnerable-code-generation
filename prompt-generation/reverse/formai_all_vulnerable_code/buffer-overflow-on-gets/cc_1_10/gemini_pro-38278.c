//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTIMENT_POSITIVE 1
#define SENTIMENT_NEGATIVE -1
#define SENTIMENT_NEUTRAL 0

// A simple dictionary of positive and negative words
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
const char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

// Function to analyze the sentiment of a given text
int analyze_sentiment(const char *text) {
  // Initialize the sentiment to neutral
  int sentiment = SENTIMENT_NEUTRAL;

  // Tokenize the text into individual words
  char *token = strtok((char *)text, " ");

  // Iterate over each word in the text
  while (token != NULL) {
    // Check if the word is in the positive dictionary
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        // If the word is positive, increment the sentiment
        sentiment += SENTIMENT_POSITIVE;
        break;
      }
    }

    // Check if the word is in the negative dictionary
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        // If the word is negative, decrement the sentiment
        sentiment += SENTIMENT_NEGATIVE;
        break;
      }
    }

    // Get the next word in the text
    token = strtok(NULL, " ");
  }

  // Return the sentiment of the text
  return sentiment;
}

// Main function
int main() {
  // Get the text from the user
  char text[1024];
  printf("Enter the text you want to analyze: ");
  gets(text);

  // Analyze the sentiment of the text
  int sentiment = analyze_sentiment(text);

  // Print the sentiment of the text
  if (sentiment == SENTIMENT_POSITIVE) {
    printf("The text is positive.\n");
  } else if (sentiment == SENTIMENT_NEGATIVE) {
    printf("The text is negative.\n");
  } else {
    printf("The text is neutral.\n");
  }

  return 0;
}