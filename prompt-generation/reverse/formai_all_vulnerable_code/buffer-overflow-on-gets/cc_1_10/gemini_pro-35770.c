//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of positive and negative words
char *positive[] = {"good", "great", "awesome", "superb", "excellent"};
char *negative[] = {"bad", "terrible", "horrible", "awful", "dreadful"};

// Function to analyze the sentiment of a string
int analyze_sentiment(char *string) {
  // Count the number of positive and negative words in the string
  int positive_count = 0;
  int negative_count = 0;
  char *token = strtok(string, " ");
  while (token != NULL) {
    for (int i = 0; i < 5; i++) {
      if (strcmp(token, positive[i]) == 0) {
        positive_count++;
      } else if (strcmp(token, negative[i]) == 0) {
        negative_count++;
      }
    }
    token = strtok(NULL, " ");
  }

  // Return the sentiment score (positive - negative)
  return positive_count - negative_count;
}

// Main function
int main() {
  // Get the input string from the user
  char string[100];
  printf("Enter a string: ");
  gets(string);

  // Analyze the sentiment of the string
  int sentiment_score = analyze_sentiment(string);

  // Print the sentiment score
  if (sentiment_score > 0) {
    printf("The string has a positive sentiment.\n");
  } else if (sentiment_score < 0) {
    printf("The string has a negative sentiment.\n");
  } else {
    printf("The string has a neutral sentiment.\n");
  }

  return 0;
}