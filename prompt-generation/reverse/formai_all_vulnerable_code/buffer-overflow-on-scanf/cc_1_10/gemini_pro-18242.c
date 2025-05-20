//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a sentiment dictionary
const char *positive_words[] = {"good", "great", "awesome", "excellent", "superb"};
const char *negative_words[] = {"bad", "terrible", "awful", "dreadful", "horrible"};

// Calculate the sentiment of a given message
int calculate_sentiment(char *message) {
  int sentiment_score = 0;

  // Tokenize the message and check each word against the sentiment dictionary
  char *token = strtok(message, " ");
  while (token != NULL) {
    for (int i = 0; i < 5; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        sentiment_score++;
        break;
      } else if (strcmp(token, negative_words[i]) == 0) {
        sentiment_score--;
        break;
      }
    }
    token = strtok(NULL, " ");
  }

  return sentiment_score;
}

// Print the sentiment of a given message
void print_sentiment(char *message) {
  int sentiment_score = calculate_sentiment(message);

  if (sentiment_score > 0) {
    printf("Sentiment: Positive\n");
  } else if (sentiment_score < 0) {
    printf("Sentiment: Negative\n");
  } else {
    printf("Sentiment: Neutral\n");
  }
}

// Main function
int main() {
  // Get the message from the user
  char message[100];
  printf("Enter a message: ");
  scanf("%s", message);

  // Print the sentiment of the message
  print_sentiment(message);

  return 0;
}