//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define positive and negative words
char *positive_words[] = {"good", "great", "awesome", "superb", "excellent"};
char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};

// Calculate the sentiment score of a given string
int sentiment_analysis(char *string) {
  int score = 0;
  char *word;

  // Tokenize the string into words
  word = strtok(string, " ");
  while (word != NULL) {
    // Check if the word is positive or negative
    int i;
    for (i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(word, positive_words[i]) == 0) {
        score += 1;
        break;
      }
    }
    for (i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(word, negative_words[i]) == 0) {
        score -= 1;
        break;
      }
    }

    // Get the next word
    word = strtok(NULL, " ");
  }

  return score;
}

int main() {
  // Get the input string from the user
  char string[100];
  printf("Enter a string: ");
  scanf("%s", string);

  // Calculate the sentiment score of the string
  int score = sentiment_analysis(string);

  // Print the sentiment score
  if (score > 0) {
    printf("The string has a positive sentiment score of %d.\n", score);
  } else if (score < 0) {
    printf("The string has a negative sentiment score of %d.\n", score);
  } else {
    printf("The string has a neutral sentiment score of %d.\n", score);
  }

  return 0;
}