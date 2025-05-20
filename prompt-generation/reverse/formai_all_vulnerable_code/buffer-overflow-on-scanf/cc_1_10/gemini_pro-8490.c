//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
  // Initialize the sentiment score
  int sentiment = 0;

  // Create an array of positive and negative words
  char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
  char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

  // Iterate over the text and check for positive and negative words
  char *word = strtok(text, " ");
  while (word != NULL) {
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, positive_words[i]) == 0) {
        sentiment++;
      } else if (strcmp(word, negative_words[i]) == 0) {
        sentiment--;
      }
    }
    word = strtok(NULL, " ");
  }

  // Return the sentiment score
  return sentiment;
}

// Get the text from the user
char *get_text() {
  // Allocate memory for the text
  char *text = malloc(100);

  // Get the text from the user
  printf("Enter the text: ");
  scanf("%s", text);

  // Return the text
  return text;
}

// Print the sentiment analysis result
void print_result(int sentiment) {
  // Print the sentiment score
  printf("The sentiment score is: %d\n", sentiment);

  // Print the sentiment analysis result
  if (sentiment > 0) {
    printf("The text is positive.\n");
  } else if (sentiment < 0) {
    printf("The text is negative.\n");
  } else {
    printf("The text is neutral.\n");
  }
}

// Main function
int main() {
  // Get the text from the user
  char *text = get_text();

  // Perform sentiment analysis on the text
  int sentiment = sentiment_analysis(text);

  // Print the sentiment analysis result
  print_result(sentiment);

  // Free the memory allocated for the text
  free(text);

  return 0;
}