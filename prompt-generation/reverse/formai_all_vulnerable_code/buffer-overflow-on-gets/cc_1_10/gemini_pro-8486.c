//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a sentiment dictionary
typedef struct {
  char *word;
  int sentiment;
} Sentiment;

// Create a sentiment dictionary
Sentiment sentiment_dictionary[] = {
  {"good", 1},
  {"bad", -1},
  {"excellent", 2},
  {"terrible", -2},
  {"great", 1},
  {"awful", -1},
  {"amazing", 2},
  {"horrible", -2},
  {"superb", 2},
  {"dreadful", -2},
  {"wonderful", 2},
  {"terrible", -2},
  {"fantastic", 2},
  {"awful", -2}
};

// Calculate the sentiment of a text
int calculate_sentiment(char *text) {
  // Tokenize the text
  char *tokens[100];
  int num_tokens = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment of each token
  int sentiment = 0;
  for (int i = 0; i < num_tokens; i++) {
    int token_sentiment = 0;
    for (int j = 0; j < sizeof(sentiment_dictionary) / sizeof(Sentiment); j++) {
      if (strcmp(tokens[i], sentiment_dictionary[j].word) == 0) {
        token_sentiment = sentiment_dictionary[j].sentiment;
        break;
      }
    }

    sentiment += token_sentiment;
  }

  // Return the sentiment of the text
  return sentiment;
}

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter a text: ");
  gets(text);

  // Calculate the sentiment of the text
  int sentiment = calculate_sentiment(text);

  // Print the sentiment of the text
  if (sentiment > 0) {
    printf("The text is positive.\n");
  } else if (sentiment < 0) {
    printf("The text is negative.\n");
  } else {
    printf("The text is neutral.\n");
  }

  return 0;
}