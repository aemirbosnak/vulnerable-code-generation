//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of sentiments
#define NUM_SENTIMENTS 3

// Define the sentiment labels
char *sentiment_labels[] = {"positive", "neutral", "negative"};

// Define the sentiment scores
int sentiment_scores[] = {1, 0, -1};

// Define the word list
char *words[] = {"good", "bad", "great", "terrible", "excellent", "awful", "amazing", "horrible"};

// Define the word scores
int word_scores[] = {1, -1, 1, -1, 1, -1, 1, -1};

// Define the function to calculate the sentiment of a text
int calculate_sentiment(char *text) {
  // Initialize the sentiment score
  int sentiment_score = 0;

  // Tokenize the text
  char *token = strtok(text, " ");

  // Iterate over the tokens
  while (token) {
    // Convert the token to lowercase
    for (int i = 0; i < strlen(token); i++) {
      token[i] = tolower(token[i]);
    }

    // Find the index of the token in the word list
    int index = -1;
    for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
      if (strcmp(token, words[i]) == 0) {
        index = i;
        break;
      }
    }

    // If the token is in the word list, add the corresponding score to the sentiment score
    if (index != -1) {
      sentiment_score += word_scores[index];
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the sentiment score
  return sentiment_score;
}

// Define the main function
int main() {
  // Get the text from the user
  char text[1024];
  printf("Enter the text: ");
  gets(text);

  // Calculate the sentiment of the text
  int sentiment_score = calculate_sentiment(text);

  // Find the sentiment label
  char *sentiment_label = NULL;
  for (int i = 0; i < NUM_SENTIMENTS; i++) {
    if (sentiment_score == sentiment_scores[i]) {
      sentiment_label = sentiment_labels[i];
      break;
    }
  }

  // Print the sentiment label
  printf("The sentiment of the text is: %s\n", sentiment_label);

  return 0;
}