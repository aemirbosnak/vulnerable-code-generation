//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Define the sentiment dictionary.
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
const char *negative_words[] = {"bad", "terrible", "awful", "horrible", "disgusting"};

// Get the sentiment of a sentence.
int get_sentiment(const char *sentence) {
  int positive_count = 0;
  int negative_count = 0;

  // Tokenize the sentence.
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    // Check if the token is a positive word.
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        positive_count++;
        break;
      }
    }

    // Check if the token is a negative word.
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        negative_count++;
        break;
      }
    }

    // Get the next token.
    token = strtok(NULL, " ");
  }

  // Return the sentiment.
  if (positive_count > negative_count) {
    return 1;
  } else if (negative_count > positive_count) {
    return -1;
  } else {
    return 0;
  }
}

// Main function.
int main() {
  // Get the sentence from the user.
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Get the sentiment of the sentence.
  int sentiment = get_sentiment(sentence);

  // Print the sentiment.
  if (sentiment == 1) {
    printf("The sentence is positive.\n");
  } else if (sentiment == -1) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}