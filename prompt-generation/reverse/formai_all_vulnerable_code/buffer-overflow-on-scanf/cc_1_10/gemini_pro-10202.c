//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to store the sentiment analysis result
typedef struct {
  int positive;
  int negative;
  int neutral;
} SentimentResult;

// Define a function to perform sentiment analysis on a given string
SentimentResult analyze_sentiment(char *text) {
  // Initialize the sentiment result
  SentimentResult result = {0, 0, 0};

  // Convert the text to lowercase
  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]);
  }

  // Split the text into words
  char *words[100];
  int num_words = 0;
  char *p = strtok(text, " ");
  while (p != NULL) {
    words[num_words] = p;
    num_words++;
    p = strtok(NULL, " ");
  }

  // Iterate over the words and count the number of positive, negative, and neutral words
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0 || strcmp(words[i], "awesome") == 0) {
      result.positive++;
    } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 || strcmp(words[i], "horrible") == 0) {
      result.negative++;
    } else {
      result.neutral++;
    }
  }

  // Return the sentiment result
  return result;
}

// Define a main function to test the sentiment analysis function
int main() {
  // Get the input text from the user
  char text[100];
  printf("Enter the text you want to analyze: ");
  scanf("%s", text);

  // Perform sentiment analysis on the input text
  SentimentResult result = analyze_sentiment(text);

  // Print the sentiment result
  printf("Sentiment analysis result:\n");
  printf("Positive: %d\n", result.positive);
  printf("Negative: %d\n", result.negative);
  printf("Neutral: %d\n", result.neutral);

  // Return 0 to indicate successful execution
  return 0;
}