//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
  // Initialize the sentiment score
  int score = 0;

  // Create a list of positive and negative words
  char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
  char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

  // Iterate over the text and check for positive and negative words
  char *word;
  while ((word = strtok(text, " ")) != NULL) {
    // Check if the word is in the positive list
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, positive_words[i]) == 0) {
        score++;
      }
    }

    // Check if the word is in the negative list
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, negative_words[i]) == 0) {
        score--;
      }
    }
  }

  // Return the sentiment score
  return score;
}

// Define the main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text: ");
  scanf("%s", text);

  // Perform sentiment analysis on the text
  int score = sentiment_analysis(text);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", score);

  // Determine the sentiment
  if (score > 0) {
    printf("The text is positive.\n");
  } else if (score < 0) {
    printf("The text is negative.\n");
  } else {
    printf("The text is neutral.\n");
  }

  return 0;
}