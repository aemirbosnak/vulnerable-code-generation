//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the sentiment values
#define SENTIMENT_POSITIVE 1
#define SENTIMENT_NEGATIVE -1
#define SENTIMENT_NEUTRAL 0

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the list of positive words
char *positive_words[] = {"good", "great", "excellent", "superb", "awesome", "fantastic", "marvelous", "wonderful", "terrific", "splendid"};

// Define the list of negative words
char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful", "atrocious", "abysmal", "deplorable", "lamentable", "pitiful"};

// Define the function to get the sentiment of a word
int get_sentiment_of_word(char *word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is in the list of positive words
  for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      return SENTIMENT_POSITIVE;
    }
  }

  // Check if the word is in the list of negative words
  for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
    if (strcmp(word, negative_words[i]) == 0) {
      return SENTIMENT_NEGATIVE;
    }
  }

  // The word is not in either list, so return neutral sentiment
  return SENTIMENT_NEUTRAL;
}

// Define the function to get the sentiment of a sentence
int get_sentiment_of_sentence(char *sentence) {
  // Tokenize the sentence into words
  char *words[MAX_WORD_LENGTH];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Get the sentiment of each word
  int sentiments[num_words];
  for (int i = 0; i < num_words; i++) {
    sentiments[i] = get_sentiment_of_word(words[i]);
  }

  // Calculate the overall sentiment of the sentence
  int sentiment = 0;
  for (int i = 0; i < num_words; i++) {
    sentiment += sentiments[i];
  }

  // Return the overall sentiment
  return sentiment;
}

// Define the main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Get the sentiment of the sentence
  int sentiment = get_sentiment_of_sentence(sentence);

  // Print the sentiment of the sentence
  if (sentiment == SENTIMENT_POSITIVE) {
    printf("The sentence is positive.\n");
  } else if (sentiment == SENTIMENT_NEGATIVE) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}