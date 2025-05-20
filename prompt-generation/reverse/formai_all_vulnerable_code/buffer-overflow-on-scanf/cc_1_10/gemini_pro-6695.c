//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the sentiment dictionary
char *sentiment_dictionary[] = {
  "excellent", "good", "bad", "terrible", "neutral"
};

// Define the sentiment scores
int sentiment_scores[] = {
  5, 4, 2, 1, 3
};

// Calculate the sentiment of a given text
int calculate_sentiment(char *text) {
  // Tokenize the text
  char *tokens = strtok(text, " ");

  // Calculate the sentiment score
  int sentiment_score = 0;
  while (tokens != NULL) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(char *); i++) {
      if (strcmp(tokens, sentiment_dictionary[i]) == 0) {
        sentiment_score += sentiment_scores[i];
      }
    }
    tokens = strtok(NULL, " ");
  }

  // Return the sentiment score
  return sentiment_score;
}

// Print the sentiment of a given text
void print_sentiment(char *text) {
  int sentiment_score = calculate_sentiment(text);

  if (sentiment_score >= 4) {
    printf("The sentiment of the text is excellent.\n");
  } else if (sentiment_score >= 3) {
    printf("The sentiment of the text is good.\n");
  } else if (sentiment_score >= 2) {
    printf("The sentiment of the text is neutral.\n");
  } else if (sentiment_score >= 1) {
    printf("The sentiment of the text is bad.\n");
  } else {
    printf("The sentiment of the text is terrible.\n");
  }
}

// Main function
int main() {
  // Get the text from the user
  char text[1024];
  printf("Enter the text: ");
  scanf("%s", text);

  // Calculate and print the sentiment of the text
  print_sentiment(text);

  return 0;
}