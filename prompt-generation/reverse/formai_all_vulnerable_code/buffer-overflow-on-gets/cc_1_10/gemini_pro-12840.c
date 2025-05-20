//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

// Function to calculate the sentiment of a sentence
int calculate_sentiment(char *sentence) {
  // Initialize the sentiment score
  int sentiment_score = 0;

  // Create an array of positive words
  char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
  int num_positive_words = sizeof(positive_words) / sizeof(char *);

  // Create an array of negative words
  char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};
  int num_negative_words = sizeof(negative_words) / sizeof(char *);

  // Tokenize the sentence
  char *tokens[MAX_SENTENCE_LENGTH];
  int num_tokens = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Iterate over the tokens and calculate the sentiment score
  for (int i = 0; i < num_tokens; i++) {
    // Check if the token is a positive word
    for (int j = 0; j < num_positive_words; j++) {
      if (strcmp(tokens[i], positive_words[j]) == 0) {
        sentiment_score++;
        break;
      }
    }

    // Check if the token is a negative word
    for (int j = 0; j < num_negative_words; j++) {
      if (strcmp(tokens[i], negative_words[j]) == 0) {
        sentiment_score--;
        break;
      }
    }
  }

  // Return the sentiment score
  return sentiment_score;
}

// Main function
int main() {
  // Get the input sentence from the user
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  gets(sentence);

  // Calculate the sentiment of the sentence
  int sentiment_score = calculate_sentiment(sentence);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", sentiment_score);

  return 0;
}