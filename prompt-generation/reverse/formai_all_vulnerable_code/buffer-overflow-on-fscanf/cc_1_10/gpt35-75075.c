//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 30
#define DICTIONARY_SIZE 20000

char *dictionary[DICTIONARY_SIZE];
int word_count = 0;

void load_dictionary(void);
int spell_check(char *word);

int main(void) {
  char input[WORD_LENGTH];
  int result;

  load_dictionary();

  // Prompt for user input
  printf("Enter a word to spell check: ");
  scanf("%s", input);

  // Check if the word is spelled correctly
  result = spell_check(input);

  // Print the result
  if (result) {
    printf("%s is spelled correctly.\n", input);
  } else {
    printf("%s is misspelled.\n", input);
  }

  return 0;
}

void load_dictionary(void) {
  FILE *dictionary_file;
  char word[WORD_LENGTH];

  // Open the dictionary file
  dictionary_file = fopen("dictionary.txt", "r");

  // Read words from the file and add them to the dictionary array
  while (fscanf(dictionary_file, "%s", word) != EOF) {
    // Allocate memory for the word
    dictionary[word_count] = (char *)malloc(strlen(word) + 1);

    // Copy the word to the new memory location
    strcpy(dictionary[word_count], word);

    // Increment the word count
    word_count++;
  }

  // Close the file
  fclose(dictionary_file);
}

int spell_check(char *word) {
  int i;

  for (i = 0; i < word_count; i++) {
    if (strcmp(dictionary[i], word) == 0) {
      // The word is in the dictionary
      return 1;
    }
  }

  // The word is not in the dictionary
  return 0;
}