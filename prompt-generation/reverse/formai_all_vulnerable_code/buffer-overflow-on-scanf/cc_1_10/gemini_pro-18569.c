//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
  // Initialize the sentiment score
  int score = 0;

  // Iterate over the text and update the sentiment score
  for (int i = 0; i < strlen(text); i++) {
    char c = text[i];

    // Positive words
    if (strcmp(&c, "good") == 0) {
      score++;
    } else if (strcmp(&c, "great") == 0) {
      score++;
    } else if (strcmp(&c, "excellent") == 0) {
      score++;
    }

    // Negative words
    else if (strcmp(&c, "bad") == 0) {
      score--;
    } else if (strcmp(&c, "terrible") == 0) {
      score--;
    } else if (strcmp(&c, "awful") == 0) {
      score--;
    }
  }

  // Return the sentiment score
  return score;
}

// Define the main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text: ");
  scanf("%s", text);

  // Perform sentiment analysis on the text
  int score = sentiment_analysis(text);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", score);

  return 0;
}