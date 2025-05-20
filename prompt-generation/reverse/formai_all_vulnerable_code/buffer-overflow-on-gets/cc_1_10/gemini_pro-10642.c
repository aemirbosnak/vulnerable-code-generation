//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store the words and their associated sentiment scores
typedef struct {
  char *word;
  int score;
} Word;

// Define an array of words and their associated sentiment scores
Word words[] = {
  {"love", 5},
  {"hate", -5},
  {"happy", 3},
  {"sad", -3},
  {"good", 2},
  {"bad", -2}
};

// Define the maximum number of words in a sentence
#define MAX_WORDS 100

// Function to analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
  // Tokenize the sentence into individual words
  char *tokens[MAX_WORDS];
  int num_tokens = tokenize(sentence, tokens, MAX_WORDS);

  // Initialize the sentiment score to 0
  int score = 0;

  // Iterate over the tokens and add the sentiment score for each word
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < (sizeof(words) / sizeof(Word)); j++) {
      if (strcmp(tokens[i], words[j].word) == 0) {
        score += words[j].score;
        break;
      }
    }
  }

  // Return the sentiment score
  return score;
}

// Function to tokenize a sentence into individual words
int tokenize(char *sentence, char *tokens[], int max_tokens) {
  // Initialize the number of tokens to 0
  int num_tokens = 0;

  // Tokenize the sentence using strtok()
  char *token = strtok(sentence, " ");
  while (token != NULL && num_tokens < max_tokens) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Return the number of tokens
  return num_tokens;
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Analyze the sentiment of the sentence
  int score = analyze_sentiment(sentence);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", score);

  return 0;
}