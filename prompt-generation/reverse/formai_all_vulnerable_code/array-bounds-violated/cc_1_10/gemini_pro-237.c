//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

// Declare the dictionary
char *dictionary[MAX_WORDS];

// Load the dictionary from a file
int load_dictionary(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  int count = 0;
  char line[MAX_WORD_LEN + 1];
  while (fgets(line, MAX_WORD_LEN + 1, fp) != NULL) {
    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Convert the line to lowercase
    for (int i = 0; i < strlen(line); i++) {
      line[i] = tolower(line[i]);
    }

    // Add the line to the dictionary
    dictionary[count++] = strdup(line);
  }

  fclose(fp);

  return count;
}

// Check if a word is in the dictionary
int is_in_dictionary(const char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (dictionary[i] == NULL) {
      return 0;
    }

    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Check the spelling of a word
int check_spelling(const char *word) {
  // Convert the word to lowercase
  char lower_word[MAX_WORD_LEN + 1];
  for (int i = 0; i < strlen(word); i++) {
    lower_word[i] = tolower(word[i]);
  }
  lower_word[strlen(word)] = '\0';

  // Check if the word is in the dictionary
  if (is_in_dictionary(lower_word)) {
    return 1;
  } else {
    return 0;
  }
}

// Main function
int main(int argc, char **argv) {
  // Load the dictionary
  int num_words = load_dictionary("dict.txt");
  if (num_words == -1) {
    fprintf(stderr, "Error loading dictionary\n");
    return EXIT_FAILURE;
  }

  // Get the word to check from the user
  char word[MAX_WORD_LEN + 1];
  printf("Enter a word to check: ");
  scanf("%s", word);

  // Check the spelling of the word
  if (check_spelling(word)) {
    printf("The word '%s' is spelled correctly.\n", word);
  } else {
    printf("The word '%s' is spelled incorrectly.\n", word);
  }

  // Free the memory allocated for the dictionary
  for (int i = 0; i < MAX_WORDS; i++) {
    if (dictionary[i] != NULL) {
      free(dictionary[i]);
    }
  }

  return EXIT_SUCCESS;
}