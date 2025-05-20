//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

// Define the sentiment analysis function.
int sentiment_analysis(char *text) {
  // Define a dictionary of positive and negative words.
  char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
  char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};

  // Initialize the positive and negative word counts.
  int positive_count = 0;
  int negative_count = 0;

  // Tokenize the text and count the number of positive and negative words.
  char *token = strtok(text, " ");
  while (token != NULL) {
    int i;
    bool is_positive = false;
    bool is_negative = false;

    // Check if the token is in the list of positive words.
    for (i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        is_positive = true;
        positive_count++;
        break;
      }
    }

    // Check if the token is in the list of negative words.
    for (i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        is_negative = true;
        negative_count++;
        break;
      }
    }

    // If the token is not in either list, ignore it.
    if (!is_positive && !is_negative) {
      continue;
    }

    // Get the next token.
    token = strtok(NULL, " ");
  }

  // Return the sentiment score.
  return positive_count - negative_count;
}

// Define the main function.
int main() {
  // Get the input text from the user.
  char text[1000];
  printf("Enter the text you want to analyze: ");
  scanf("%s", text);

  // Perform sentiment analysis on the text.
  int sentiment_score = sentiment_analysis(text);

  // Print the sentiment score.
  printf("The sentiment score is: %d\n", sentiment_score);

  // Return 0 to indicate successful execution.
  return 0;
}