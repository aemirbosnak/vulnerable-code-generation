//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lexicon of positive and negative words
const char *positive[] = {"good", "great", "excellent", "wonderful", "amazing"};
const char *negative[] = {"bad", "terrible", "awful", "horrible", "disgusting"};

// A function to analyze the sentiment of a given text
int analyzeSentiment(const char *text) {
  // Initialize the sentiment score
  int score = 0;

  // Tokenize the text
  char *token = strtok(text, " ");
  while (token != NULL) {
    // Check if the token is in the lexicon of positive words
    for (int i = 0; i < sizeof(positive) / sizeof(char *); i++) {
      if (strcmp(token, positive[i]) == 0) {
        score++;
        break;
      }
    }

    // Check if the token is in the lexicon of negative words
    for (int i = 0; i < sizeof(negative) / sizeof(char *); i++) {
      if (strcmp(token, negative[i]) == 0) {
        score--;
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the sentiment score
  return score;
}

// A function to demonstrate the sentiment analysis function
int main() {
  // Get the text to analyze from the user
  char text[1024];
  printf("Enter the text to analyze: ");
  gets(text);

  // Analyze the sentiment of the text
  int score = analyzeSentiment(text);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", score);

  return 0;
}