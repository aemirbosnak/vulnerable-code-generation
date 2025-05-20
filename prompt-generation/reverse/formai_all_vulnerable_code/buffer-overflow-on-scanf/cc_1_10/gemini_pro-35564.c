//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
  ['a'] = 1,
  ['b'] = -1,
  ['c'] = 0,
  ['d'] = 1,
  ['e'] = -1,
  ['f'] = 0,
  ['g'] = 1,
  ['h'] = -1,
  ['i'] = 0,
  ['j'] = 1,
  ['k'] = -1,
  ['l'] = 0,
  ['m'] = 1,
  ['n'] = -1,
  ['o'] = 0,
  ['p'] = 1,
  ['q'] = -1,
  ['r'] = 0,
  ['s'] = 1,
  ['t'] = -1,
  ['u'] = 0,
  ['v'] = 1,
  ['w'] = -1,
  ['x'] = 0,
  ['y'] = 1,
  ['z'] = -1
};

// Calculate the sentiment score for a given string
int calculate_sentiment(char *string) {
  int score = 0;
  for (int i = 0; i < strlen(string); i++) {
    score += sentiment_scores[string[i]];
  }
  return score;
}

// Print the sentiment score for a given string
void print_sentiment(char *string) {
  int score = calculate_sentiment(string);
  printf("The sentiment score for '%s' is %d\n", string, score);
}

// The main function
int main() {
  // Get the input string from the user
  char string[100];
  printf("Enter a string: ");
  scanf("%s", string);

  // Print the sentiment score for the input string
  print_sentiment(string);

  return 0;
}