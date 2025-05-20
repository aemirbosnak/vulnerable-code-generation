//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

int main() {
  // The wasteland's lexicon
  Word lexicon[MAX_WORDS];
  int num_words = 0;

  // The scavenger's satchel of words
  char words[10000];
  gets(words);

  // Tokenize the wasteland's lexicon
  char *token = strtok(words, " ");
  while (token != NULL) {
    // Check if the word is already in the lexicon
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(token, lexicon[i].word) == 0) {
        lexicon[i].count++;
        found = 1;
        break;
      }
    }

    // If the word is not in the lexicon, add it
    if (!found) {
      strcpy(lexicon[num_words].word, token);
      lexicon[num_words].count = 1;
      num_words++;
    }

    // Continue scavenging for words
    token = strtok(NULL, " ");
  }

  // Display the wasteland's lexicon
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", lexicon[i].word, lexicon[i].count);
  }

  return 0;
}