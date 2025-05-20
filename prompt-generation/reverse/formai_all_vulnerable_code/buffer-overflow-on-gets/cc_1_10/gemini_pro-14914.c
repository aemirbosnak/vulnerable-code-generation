//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

// Get the sentiment score of a sentence
int get_sentiment_score(char *sentence) {
  int score = 0;

  // Tokenize the sentence
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    // Check if the token is a positive word
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        score++;
        break;
      }
    }

    // Check if the token is a negative word
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        score--;
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  return score;
}

// Print the sentiment of a sentence
void print_sentiment(int score) {
  if (score > 0) {
    printf("The sentence is positive.\n");
  } else if (score < 0) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }
}

int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Get the sentiment score of the sentence
  int score = get_sentiment_score(sentence);

  // Print the sentiment of the sentence
  print_sentiment(score);

  return 0;
}