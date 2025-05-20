//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

/* Returns the sentiment score for a given sentence */
int analyzeSentiment(char sentence[]) {
  int score = 0;

  // List of positive and negative words
  char positiveWords[5][20] = {"happy", "love", "great", "awesome", "amazing"};
  char negativeWords[5][20] = {"hate", "angry", "sad", "depressing", "terrible"};

  // Tokenize the sentence
  char *word = strtok(sentence, " ");

  // Iterate over each word in the sentence
  while (word != NULL) {
    // Check if the word is in the list of positive or negative words
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, positiveWords[i]) == 0) {
        score++;
      } else if (strcmp(word, negativeWords[i]) == 0) {
        score--;
      }
    }
    word = strtok(NULL, " ");
  }

  return score;
}

/* Main function */
int main() {
  char sentence[100];

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  // Remove newline character from input string
  if (sentence[strlen(sentence) - 1] == '\n') {
    sentence[strlen(sentence) - 1] = '\0';
  }

  int sentimentScore = analyzeSentiment(sentence);

  if (sentimentScore > 0) {
    printf("Positive sentiment detected.\n");
  } else if (sentimentScore < 0) {
    printf("Negative sentiment detected.\n");
  } else {
    printf("Neutral sentiment detected.\n");
  }

  return 0;
}