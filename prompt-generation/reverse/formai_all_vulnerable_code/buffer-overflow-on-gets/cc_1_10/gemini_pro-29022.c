//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
  // Initialize the sentiment score
  int score = 0;

  // Create an array of positive words
  char *positive_words[] = {"good", "great", "awesome", "superb", "excellent"};

  // Create an array of negative words
  char *negative_words[] = {"bad", "terrible", "horrible", "awful", "disgusting"};

  // Iterate over the text and check for positive and negative words
  for (int i = 0; i < strlen(text); i++) {
    // Check if the current word is in the positive words array
    for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
      if (strcmp(text + i, positive_words[j]) == 0) {
        // Increment the sentiment score
        score++;
      }
    }

    // Check if the current word is in the negative words array
    for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
      if (strcmp(text + i, negative_words[j]) == 0) {
        // Decrement the sentiment score
        score--;
      }
    }
  }

  // Return the sentiment score
  return score;
}

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text: ");
  gets(text);

  // Perform sentiment analysis on the text
  int score = sentiment_analysis(text);

  // Print the sentiment score
  printf("Sentiment score: %d\n", score);

  return 0;
}