//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

  #define MAX_LENGTH 100

  // Function to calculate the sentiment score of a given sentence
  int calculate_sentiment_score(char *sentence) {
    int score = 0;
    int i;
    char word[MAX_LENGTH];

    // Split the sentence into individual words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
      // Check if the word is a positive word
      if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0) {
        score += 3;
      }
      // Check if the word is a negative word
      else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "horrible") == 0) {
        score -= 3;
      }
      // Check if the word is a neutral word
      else if (strcmp(token, "neutral") == 0) {
        score += 1;
      }
      // Move on to the next word
      token = strtok(NULL, " ");
    }

    return score;
  }

  // Function to print the sentiment score of a given sentence
  void print_sentiment_score(char *sentence) {
    int score = calculate_sentiment_score(sentence);
    if (score > 0) {
      printf("Positive sentiment: %d\n", score);
    } else if (score < 0) {
      printf("Negative sentiment: %d\n", score);
    } else {
      printf("Neutral sentiment: %d\n", score);
    }
  }

  int main() {
    char sentence[MAX_LENGTH];

    printf("Enter a sentence: ");
    scanf("%s", sentence);

    print_sentiment_score(sentence);

    return 0;
  }