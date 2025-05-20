//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: genius
#include <stdio.h>
#include <string.h>

// Define the maximum length of a sentiment string
#define MAX_SENTIMENT_LENGTH 100

// Define the number of sentiment categories
#define NUM_SENTIMENT_CATEGORIES 5

// Define the sentiment categories
char *sentiment_categories[NUM_SENTIMENT_CATEGORIES] = {"Very negative", "Negative", "Neutral", "Positive", "Very positive"};

// Define the sentiment scores
int sentiment_scores[NUM_SENTIMENT_CATEGORIES] = {-2, -1, 0, 1, 2};

// Get the sentiment score of a string
int get_sentiment_score(char *string) {
  // Calculate the total sentiment score of the string
  int total_score = 0;
  for (int i = 0; i < strlen(string); i++) {
    // Get the sentiment score of the current character
    int score = 0;
    if (string[i] >= 'a' && string[i] <= 'z') {
      score = string[i] - 'a';
    } else if (string[i] >= 'A' && string[i] <= 'Z') {
      score = string[i] - 'A';
    }

    // Add the sentiment score of the current character to the total score
    total_score += score;
  }

  // Return the total sentiment score of the string
  return total_score;
}

// Get the sentiment category of a string
char *get_sentiment_category(char *string) {
  // Get the sentiment score of the string
  int score = get_sentiment_score(string);

  // Return the sentiment category of the string
  if (score < sentiment_scores[0]) {
    return sentiment_categories[0];
  } else if (score < sentiment_scores[1]) {
    return sentiment_categories[1];
  } else if (score < sentiment_scores[2]) {
    return sentiment_categories[2];
  } else if (score < sentiment_scores[3]) {
    return sentiment_categories[3];
  } else {
    return sentiment_categories[4];
  }
}

// Print the sentiment analysis of a string
void print_sentiment_analysis(char *string) {
  // Get the sentiment score of the string
  int score = get_sentiment_score(string);

  // Get the sentiment category of the string
  char *category = get_sentiment_category(string);

  // Print the sentiment analysis of the string
  printf("Sentiment analysis of \"%s\":\n", string);
  printf(" - Sentiment score: %d\n", score);
  printf(" - Sentiment category: %s\n", category);
}

int main() {
  // Get the input string from the user
  char string[MAX_SENTIMENT_LENGTH];
  printf("Enter a string: ");
  scanf("%s", string);

  // Print the sentiment analysis of the string
  print_sentiment_analysis(string);

  return 0;
}