//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define a struct to hold the sentiment analysis results
typedef struct {
  int positive;
  int negative;
  int neutral;
} sentiment_result_t;

// Define a function to perform sentiment analysis on a given string
sentiment_result_t analyze_sentiment(char *str) {
  // Initialize the sentiment result struct
  sentiment_result_t result = {0, 0, 0};

  // Create an array of positive and negative words
  char *positive_words[] = {"good", "great", "awesome", "excellent", "superb"};
  char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

  // Iterate over the string and count the occurrences of positive and negative words
  for (int i = 0; i < strlen(str); i++) {
    for (int j = 0; j < 5; j++) {
      if (strcmp(str + i, positive_words[j]) == 0) {
        result.positive++;
      } else if (strcmp(str + i, negative_words[j]) == 0) {
        result.negative++;
      }
    }
  }

  // Determine the overall sentiment of the string
  if (result.positive > result.negative) {
    result.neutral = 1;
  } else if (result.negative > result.positive) {
    result.neutral = -1;
  }

  // Return the sentiment result struct
  return result;
}

// Define a function to print the sentiment analysis results
void print_sentiment_results(sentiment_result_t result) {
  // Print the number of positive, negative, and neutral words
  printf("Positive: %d\n", result.positive);
  printf("Negative: %d\n", result.negative);
  printf("Neutral: %d\n", result.neutral);

  // Print the overall sentiment of the string
  if (result.neutral == 1) {
    printf("Overall sentiment: Positive\n");
  } else if (result.neutral == -1) {
    printf("Overall sentiment: Negative\n");
  } else {
    printf("Overall sentiment: Neutral\n");
  }
}

// Define the main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string to analyze: ");
  gets(str);

  // Perform sentiment analysis on the input string
  sentiment_result_t result = analyze_sentiment(str);

  // Print the sentiment analysis results
  print_sentiment_results(result);

  // Return 0 to indicate successful execution
  return 0;
}