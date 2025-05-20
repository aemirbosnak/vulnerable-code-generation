//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

int compareWords(const void *a, const void *b) {
  Word *wa = (Word *)a;
  Word *wb = (Word *)b;
  return strcmp(wa->word, wb->word);
}

int main() {
  // Load the dictionary into an array of words
  FILE *dictFile = fopen("dictionary.txt", "r");
  if (dictFile == NULL) {
    printf("Error opening dictionary file\n");
    return 1;
  }

  Word dictionary[MAX_WORDS];
  int numWords = 0;
  while (fscanf(dictFile, "%s", dictionary[numWords].word) != EOF) {
    dictionary[numWords].count = 0;
    numWords++;
  }
  fclose(dictFile);

  // Sort the dictionary
  qsort(dictionary, numWords, sizeof(Word), compareWords);

  // Read the text file to be checked for spelling
  FILE *textFile = fopen("text.txt", "r");
  if (textFile == NULL) {
    printf("Error opening text file\n");
    return 1;
  }

  char text[10000];
  fread(text, 1, 10000, textFile);
  fclose(textFile);

  // Tokenize the text and check each word for spelling
  char *token = strtok(text, " ,.-!?\n");
  while (token != NULL) {
    // Convert the token to lowercase
    for (int i = 0; token[i] != '\0'; i++) {
      token[i] = tolower(token[i]);
    }

    // Search for the word in the dictionary
    Word *result = bsearch(token, dictionary, numWords, sizeof(Word),
                           compareWords);

    // If the word is not found, print it out
    if (result == NULL) {
      printf("Unknown word: %s\n", token);
    } else {
      // Increment the count of the word in the dictionary
      result->count++;
    }

    // Get the next token
    token = strtok(NULL, " ,.-!?\n");
  }

  // Print out the words in the dictionary sorted by count
  qsort(dictionary, numWords, sizeof(Word),
         compareWords); // Sort by word
  for (int i = 0; i < numWords; i++) {
    if (dictionary[i].count > 0) {
      printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
  }

  return 0;
}