//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[20] = {
  -1,  // "bad"
  1,   // "good"
  -2,  // "terrible"
  2,   // "wonderful"
  -3,  // "horrible"
  3,   // "amazing"
  -4,  // "awful"
  4,   // "excellent"
  -5,  // "dreadful"
  5,   // "brilliant"
  0    // "neutral"
};

// Get the sentiment score for a word
int get_sentiment_score(char *word) {
  for (int i = 0; i < 20; i++) {
    if (strcmp(word, sentiment_scores[i]) == 0) {
      return i;
    }
  }

  return 0;
}

// Get the sentiment score for a sentence
int get_sentence_sentiment_score(char *sentence) {
  char *words[100];
  int num_words = 0;

  // Split the sentence into words
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }

  // Get the sentiment score for each word and sum them up
  int total_score = 0;
  for (int i = 0; i < num_words; i++) {
    total_score += get_sentiment_score(words[i]);
  }

  return total_score;
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Get the sentiment score for the sentence
  int sentiment_score = get_sentence_sentiment_score(sentence);

  // Print the sentiment score
  printf("Sentiment score: %d\n", sentiment_score);

  return 0;
}