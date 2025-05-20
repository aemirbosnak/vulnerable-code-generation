//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>

// Define a structure to hold the sentiment scores
typedef struct {
  int positive;
  int negative;
} SentimentScores;

// Define a function to calculate the sentiment scores of a string
SentimentScores calculate_sentiment(char *string) {
  // Initialize the sentiment scores
  SentimentScores scores = {0, 0};

  // Loop through the string and update the sentiment scores
  for (int i = 0; i < strlen(string); i++) {
    char c = string[i];
    if (c >= 'A' && c <= 'Z') {
      c += 32;
    }
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        scores.positive++;
        break;
      case 'b':
      case 'c':
      case 'd':
      case 'f':
      case 'g':
        scores.negative++;
        break;
    }
  }

  // Return the sentiment scores
  return scores;
}

// Define a function to print the sentiment scores
void print_sentiment(SentimentScores scores) {
  // Print the positive sentiment score
  printf("Positive sentiment: %d\n", scores.positive);

  // Print the negative sentiment score
  printf("Negative sentiment: %d\n", scores.negative);
}

// Define a function to get the sentiment of a string from the user
char *get_sentiment(char *string) {
  // Prompt the user to enter a string
  printf("Enter a string: ");

  // Read the string from the user
  scanf("%s", string);

  // Return the string
  return string;
}

// Define the main function
int main() {
  // Declare a variable to store the string
  char string[100];

  // Get the sentiment of the string from the user
  char *input = get_sentiment(string);

  // Calculate the sentiment scores of the string
  SentimentScores scores = calculate_sentiment(input);

  // Print the sentiment scores
  print_sentiment(scores);

  // Return 0 to indicate that the program ran successfully
  return 0;
}