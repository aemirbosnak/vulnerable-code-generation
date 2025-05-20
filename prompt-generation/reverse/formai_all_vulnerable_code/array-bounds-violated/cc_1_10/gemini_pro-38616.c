//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionary_size = 0;

int load_dictionary(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file)) {
    // Remove the newline character from the line.
    line[strlen(line) - 1] = '\0';

    // Copy the word into the dictionary.
    strcpy(dictionary[dictionary_size].word, line);

    // Increment the word count.
    dictionary_size++;
  }

  fclose(file);

  return 0;
}

int check_spelling(const char *word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <dictionary_file>\n", argv[0]);
    return 1;
  }

  // Load the dictionary into memory.
  if (load_dictionary(argv[1]) != 0) {
    printf("Error loading dictionary.\n");
    return 1;
  }

  // Get the word to be checked from the user.
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check: ");
  scanf("%s", word);

  // Check the spelling of the word.
  int is_spelled_correctly = check_spelling(word);

  // Print the result.
  if (is_spelled_correctly) {
    printf("The word '%s' is spelled correctly.\n", word);
  } else {
    printf("The word '%s' is not spelled correctly.\n", word);
  }

  return 0;
}