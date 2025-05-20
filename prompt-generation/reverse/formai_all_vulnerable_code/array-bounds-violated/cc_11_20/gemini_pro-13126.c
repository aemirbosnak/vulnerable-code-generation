//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A global variable to store the summary
char summary[1024];

// A function to summarize a given text
void summarize(char *text) {
  // Split the text into sentences
  char *sentences[100];
  int numSentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[numSentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Calculate the score of each sentence
  int scores[numSentences];
  for (int i = 0; i < numSentences; i++) {
    scores[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      // Check if the word is a keyword
      if (strcmp(word, "the") == 0 || strcmp(word, "a") == 0 || strcmp(word, "an") == 0 ||
          strcmp(word, "is") == 0 || strcmp(word, "are") == 0 || strcmp(word, "was") == 0 ||
          strcmp(word, "were") == 0 || strcmp(word, "be") == 0 || strcmp(word, "been") == 0 ||
          strcmp(word, "and") == 0 || strcmp(word, "or") == 0 || strcmp(word, "but") == 0 ||
          strcmp(word, "so") == 0 || strcmp(word, "for") == 0 || strcmp(word, "of") == 0 ||
          strcmp(word, "to") == 0 || strcmp(word, "in") == 0 || strcmp(word, "on") == 0 ||
          strcmp(word, "at") == 0 || strcmp(word, "with") == 0 || strcmp(word, "as") == 0 ||
          strcmp(word, "by") == 0 || strcmp(word, "from") == 0 || strcmp(word, "than") == 0 ||
          strcmp(word, "that") == 0) {
        // If the word is a keyword, decrement the score
        scores[i]--;
      } else {
        // If the word is not a keyword, increment the score
        scores[i]++;
      }
      word = strtok(NULL, " ");
    }
  }

  // Find the sentence with the highest score
  int maxScore = scores[0];
  int maxScoreIndex = 0;
  for (int i = 1; i < numSentences; i++) {
    if (scores[i] > maxScore) {
      maxScore = scores[i];
      maxScoreIndex = i;
    }
  }

  // Copy the sentence with the highest score to the summary
  strcpy(summary, sentences[maxScoreIndex]);
}

// A function to print the summary
void printSummary() {
  printf("Summary: %s", summary);
}

// The main function
int main() {
  // Get the text from the user
  char text[1024];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  summarize(text);

  // Print the summary
  printSummary();

  return 0;
}