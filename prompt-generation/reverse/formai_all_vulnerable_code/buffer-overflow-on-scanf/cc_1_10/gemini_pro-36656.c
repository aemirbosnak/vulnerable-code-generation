//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the sentiment scores for each word
#define POSITIVE_SCORE 1
#define NEGATIVE_SCORE -1
#define NEUTRAL_SCORE 0

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 100

// Create a dictionary of words and their sentiment scores
char *dictionary[][2] = {
  {"good", "1"},
  {"bad", "-1"},
  {"happy", "1"},
  {"sad", "-1"},
  {"love", "1"},
  {"hate", "-1"},
  {"beautiful", "1"},
  {"ugly", "-1"},
  {"amazing", "1"},
  {"terrible", "-1"}
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
  // Iterate over the dictionary to find the word
  for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
    if (strcmp(word, dictionary[i][0]) == 0) {
      // Return the sentiment score for the word
      return atoi(dictionary[i][1]);
    }
  }

  // If the word is not found in the dictionary, return 0
  return NEUTRAL_SCORE;
}

// Get the sentiment score for a given sentence
int get_sentence_sentiment_score(char *sentence) {
  // Tokenize the sentence into words
  char *words[MAX_WORDS_IN_SENTENCE];
  int num_words = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment score for each word in the sentence
  int sentiment_score = 0;
  for (int i = 0; i < num_words; i++) {
    sentiment_score += get_sentiment_score(words[i]);
  }

  // Return the sentiment score for the sentence
  return sentiment_score;
}

// Get the sentiment of a given sentence
char *get_sentiment(char *sentence) {
  // Get the sentiment score for the sentence
  int sentiment_score = get_sentence_sentiment_score(sentence);

  // Return the sentiment of the sentence
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
  char *sentiment = get_sentiment(sentence);

  // Print the sentiment of the sentence
  printf("The sentiment of the sentence is: %s\n", sentiment);

  return 0;
}