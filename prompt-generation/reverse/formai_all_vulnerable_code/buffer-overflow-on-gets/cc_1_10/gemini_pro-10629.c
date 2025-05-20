//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

// Define a struct to hold a word and its sentiment
typedef struct {
  char word[MAX_LEN];
  int sentiment;
} Word;

// Define a struct to hold a list of words
typedef struct {
  Word words[MAX_WORDS];
  int num_words;
} WordList;

// Define a dictionary of words and their sentiments
WordList dictionary = {
  .words = {
    {"bad", -1},
    {"good", 1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3}
  },
  .num_words = 5
};

// Function to get the sentiment of a word
int get_sentiment(char *word) {
  for (int i = 0; i < dictionary.num_words; i++) {
    if (strcmp(word, dictionary.words[i].word) == 0) {
      return dictionary.words[i].sentiment;
    }
  }

  // If the word is not found in the dictionary, return 0
  return 0;
}

// Function to analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
  // Split the sentence into words
  char *words[MAX_WORDS];
  char *word = strtok(sentence, " ");
  int num_words = 0;
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment of each word
  int sentiments[MAX_WORDS];
  for (int i = 0; i < num_words; i++) {
    sentiments[i] = get_sentiment(words[i]);
  }

  // Calculate the overall sentiment of the sentence
  int overall_sentiment = 0;
  for (int i = 0; i < num_words; i++) {
    overall_sentiment += sentiments[i];
  }

  return overall_sentiment;
}

int main() {
  // Get the sentence from the user
  char sentence[MAX_LEN];
  printf("Enter a sentence: ");
  gets(sentence);

  // Analyze the sentiment of the sentence
  int sentiment = analyze_sentiment(sentence);

  // Print the sentiment of the sentence
  if (sentiment > 0) {
    printf("The sentence has a positive sentiment.\n");
  } else if (sentiment < 0) {
    printf("The sentence has a negative sentiment.\n");
  } else {
    printf("The sentence has a neutral sentiment.\n");
  }

  return 0;
}