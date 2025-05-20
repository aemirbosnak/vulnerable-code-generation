//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store word and its frequency
typedef struct WordFreq {
  char *word;
  int freq;
} WordFreq;

// Compare function for qsort
int cmp(const void *a, const void *b) {
  const WordFreq *w1 = (WordFreq *)a;
  const WordFreq *w2 = (WordFreq *)b;
  return strcmp(w1->word, w2->word);
}

int main() {
  // Initialize variables
  const int MAX_WORDS = 1000;
  char text[50000];
  char *words[MAX_WORDS];
  int wordCount[MAX_WORDS];

  // Gather the text from the user's whimsy
  printf("Oh, traveler, tell us thy tale! (Enter your text below)\n");
  scanf("%[^\n]s", text);

  // Tokenize the text into an array of words
  int numWords = 0;
  char *token = strtok(text, " ,.:;!?");
  while (token != NULL) {
    words[numWords++] = strdup(token);
    token = strtok(NULL, " ,.:;!?");
  }

  // Count the frequencies of each word
  memset(wordCount, 0, sizeof(int) * MAX_WORDS);
  for (int i = 0; i < numWords; i++) {
    char *curWord = words[i];
    for (int j = 0; j < numWords; j++) {
      if (strcmp(curWord, words[j]) == 0) {
        wordCount[i]++;
      }
    }
  }

  // Create an array of WordFreq structures
  WordFreq wordFreqs[numWords];
  for (int i = 0; i < numWords; i++) {
    wordFreqs[i].word = words[i];
    wordFreqs[i].freq = wordCount[i];
  }

  // Sort the array of WordFreq structures
  qsort(wordFreqs, numWords, sizeof(WordFreq), cmp);

  // Display the word frequencies
  printf("\nBehold, the tapestry of words, unraveling their secrets:\n");
  for (int i = 0; i < numWords; i++) {
    printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].freq);
  }

  // Free allocated memory
  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }

  return 0;
}