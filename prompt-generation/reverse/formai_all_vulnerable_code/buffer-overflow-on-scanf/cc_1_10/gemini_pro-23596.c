//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
const int positive_scores[] = {1, 2, 3, 4, 5};

const char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};
const int negative_scores[] = {-1, -2, -3, -4, -5};

// Get the sentiment score for a given word
int get_sentiment_score(const char *word) {
  // Iterate over the positive words and check if the word matches
  for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      return positive_scores[i];
    }
  }

  // Iterate over the negative words and check if the word matches
  for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
    if (strcmp(word, negative_words[i]) == 0) {
      return negative_scores[i];
    }
  }

  // If the word is not found in either list, return 0
  return 0;
}

// Get the sentiment score for a given sentence
int get_sentence_sentiment_score(const char *sentence) {
  // Split the sentence into words
  char *words[100];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment score for each word and sum them up
  int sentiment_score = 0;
  for (int i = 0; i < num_words; i++) {
    sentiment_score += get_sentiment_score(words[i]);
  }

  return sentiment_score;
}

// Get the sentiment of a given sentence
char *get_sentence_sentiment(const char *sentence) {
  // Get the sentiment score for the sentence
  int sentiment_score = get_sentence_sentiment_score(sentence);

  // Return the sentiment as a string
  if (sentiment_score > 0) {
    return "positive";
  } else if (sentiment_score < 0) {
    return "negative";
  } else {
    return "neutral";
  }
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Get the sentiment of the sentence
  char *sentiment = get_sentence_sentiment(sentence);

  // Print the sentiment
  printf("The sentiment of the sentence is: %s\n", sentiment);

  return 0;
}