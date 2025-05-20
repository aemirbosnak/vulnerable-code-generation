//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the sentiment scores for each word
typedef struct {
  char *word;
  int score;
} WordScore;

// Initialize the word scores array
WordScore wordScores[] = {
  {"amazing", 5},
  {"great", 4},
  {"good", 3},
  {"okay", 2},
  {"bad", 1},
  {"terrible", 0}
};

// Get the sentiment score for a given word
int getWordScore(char *word) {
  for (int i = 0; i < sizeof(wordScores) / sizeof(WordScore); i++) {
    if (strcmp(word, wordScores[i].word) == 0) {
      return wordScores[i].score;
    }
  }

  // If the word is not found in the array, return 0
  return 0;
}

// Analyze the sentiment of a given sentence
int analyzeSentiment(char *sentence) {
  // Split the sentence into words
  char *words[100];
  int numWords = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the total sentiment score for the sentence
  int totalScore = 0;
  for (int i = 0; i < numWords; i++) {
    totalScore += getWordScore(words[i]);
  }

  // Return the total sentiment score
  return totalScore;
}

// Main function
int main() {
  // Get the input sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Analyze the sentiment of the sentence
  int sentimentScore = analyzeSentiment(sentence);

  // Print the sentiment score
  printf("Sentiment score: %d\n", sentimentScore);

  return 0;
}