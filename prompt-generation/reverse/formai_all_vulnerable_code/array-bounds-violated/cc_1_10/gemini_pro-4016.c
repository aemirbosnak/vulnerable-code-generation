//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 32
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

Word dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

int main() {
  // Load the dictionary
  FILE *dictionaryFile = fopen("dictionary.txt", "r");
  if (dictionaryFile == NULL) {
    printf("Error: Could not open the dictionary file.\n");
    return EXIT_FAILURE;
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, dictionaryFile) != NULL) {
    // Remove the newline character from the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    strcpy(dictionary[dictionarySize].word, line);
    dictionary[dictionarySize].count = 0;
    dictionarySize++;
  }

  fclose(dictionaryFile);

  // Get the text to spell check
  printf("Enter the text to spell check:\n");
  char text[10000];
  fgets(text, 10000, stdin);

  // Split the text into words
  char *words[1000];
  int wordCount = 0;
  char *word = strtok(text, " ");
  while (word != NULL) {
    words[wordCount] = word;
    wordCount++;
    word = strtok(NULL, " ");
  }

  // Spell check the words
  for (int i = 0; i < wordCount; i++) {
    // Convert the word to lowercase
    for (int j = 0; j < strlen(words[i]); j++) {
      words[i][j] = tolower(words[i][j]);
    }

    // Check if the word is in the dictionary
    int found = 0;
    for (int j = 0; j < dictionarySize; j++) {
      if (strcmp(words[i], dictionary[j].word) == 0) {
        found = 1;
        break;
      }
    }

    // If the word is not in the dictionary, print it
    if (!found) {
      printf("%s\n", words[i]);
    }
  }

  return EXIT_SUCCESS;
}