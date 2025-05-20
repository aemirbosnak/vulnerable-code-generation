//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// This function takes a sentence and returns a score indicating its sentiment.
// The score can be positive, negative, or neutral.
int sentiment_analysis(char *sentence) {
  // Tokenize the sentence into words.
  char *words[MAX_SENTENCE_LENGTH];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment score of the sentence.
  int score = 0;
  for (int i = 0; i < num_words; i++) {
    // Check if the word is in the positive word list.
    if (strcmp(words[i], "happy") == 0) {
      score++;
    } else if (strcmp(words[i], "joyful") == 0) {
      score++;
    } else if (strcmp(words[i], "excited") == 0) {
      score++;
    } else if (strcmp(words[i], "optimistic") == 0) {
      score++;
    } else if (strcmp(words[i], "hopeful") == 0) {
      score++;
    }

    // Check if the word is in the negative word list.
    else if (strcmp(words[i], "sad") == 0) {
      score--;
    } else if (strcmp(words[i], "depressed") == 0) {
      score--;
    } else if (strcmp(words[i], "angry") == 0) {
      score--;
    } else if (strcmp(words[i], "pessimistic") == 0) {
      score--;
    } else if (strcmp(words[i], "hopeless") == 0) {
      score--;
    }
  }

  return score;
}

int main() {
  // Get the sentence from the user.
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  gets(sentence);

  // Perform sentiment analysis on the sentence.
  int score = sentiment_analysis(sentence);

  // Print the sentiment score.
  if (score > 0) {
    printf("The sentence is positive.\n");
  } else if (score < 0) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}