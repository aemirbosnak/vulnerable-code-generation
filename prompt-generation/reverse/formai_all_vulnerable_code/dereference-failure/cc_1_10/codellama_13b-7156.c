//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
// WordFrequencyCounter.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to store word and frequency
typedef struct {
  char *word;
  int frequency;
} WordFrequency;

// Function to compare two WordFrequency structs
int compareWordFrequencies(const void *a, const void *b) {
  const WordFrequency *wf1 = (const WordFrequency *) a;
  const WordFrequency *wf2 = (const WordFrequency *) b;
  return wf1->frequency - wf2->frequency;
}

// Function to count the frequency of each word in a sentence
int countWordFrequency(char *sentence) {
  int i, j, wordCount = 0;
  char *word;
  WordFrequency *wordFrequencies = malloc(sizeof(WordFrequency) * 1000);
  char *token = strtok(sentence, " ");

  while (token != NULL) {
    word = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(word, token);
    wordFrequencies[wordCount].word = word;
    wordFrequencies[wordCount].frequency = 0;
    for (i = 0; i < wordCount; i++) {
      if (strcmp(wordFrequencies[i].word, word) == 0) {
        wordFrequencies[i].frequency++;
        break;
      }
    }
    if (i == wordCount) {
      wordFrequencies[wordCount].frequency++;
      wordCount++;
    }
    token = strtok(NULL, " ");
  }

  // Sort the word frequencies by frequency
  qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWordFrequencies);

  // Print the word frequencies
  for (i = 0; i < wordCount; i++) {
    printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
  }

  // Free the memory
  for (i = 0; i < wordCount; i++) {
    free(wordFrequencies[i].word);
  }
  free(wordFrequencies);

  return 0;
}

// Test function
int main() {
  char sentence[] = "The quick brown fox jumps over the lazy dog";
  countWordFrequency(sentence);
  return 0;
}