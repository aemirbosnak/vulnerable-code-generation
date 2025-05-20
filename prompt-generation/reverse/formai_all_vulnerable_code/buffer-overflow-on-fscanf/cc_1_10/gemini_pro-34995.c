//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the dictionary
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Create a struct to represent a word in the dictionary
typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} Word;

// Create an array of words to represent the dictionary
Word dictionary[MAX_WORDS];

// Read the dictionary from a file
void read_dictionary(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while (fscanf(file, "%s", dictionary[i].word) != EOF) {
    dictionary[i].frequency = 0;
    i++;
  }

  fclose(file);
}

// Check if a word is in the dictionary
int is_in_dictionary(const char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return 1;
    }
  }

  return 0;
}

// Check if a word is spelled correctly
int is_spelled_correctly(const char *word) {
  if (is_in_dictionary(word)) {
    return 1;
  }

  // Check for common spelling errors
  char lowercase_word[MAX_WORD_LENGTH];
  strcpy(lowercase_word, word);
  for (int i = 0; i < strlen(word); i++) {
    lowercase_word[i] = tolower(lowercase_word[i]);
  }

  if (is_in_dictionary(lowercase_word)) {
    return 1;
  }

  return 0;
}

// Get the suggested spellings for a word
char **get_suggested_spellings(const char *word) {
  char **suggested_spellings = malloc(sizeof(char *) * MAX_WORDS);
  int num_suggested_spellings = 0;

  // Check for common spelling errors
  char lowercase_word[MAX_WORD_LENGTH];
  strcpy(lowercase_word, word);
  for (int i = 0; i < strlen(word); i++) {
    lowercase_word[i] = tolower(lowercase_word[i]);
  }

  if (is_in_dictionary(lowercase_word)) {
    suggested_spellings[num_suggested_spellings++] = strdup(lowercase_word);
  }

  // Check for transposed letters
  for (int i = 0; i < strlen(word) - 1; i++) {
    char transposed_word[MAX_WORD_LENGTH];
    strcpy(transposed_word, word);
    char temp = transposed_word[i];
    transposed_word[i] = transposed_word[i + 1];
    transposed_word[i + 1] = temp;

    if (is_in_dictionary(transposed_word)) {
      suggested_spellings[num_suggested_spellings++] = strdup(transposed_word);
    }
  }

  // Check for missing letters
  for (int i = 0; i < strlen(word); i++) {
    char missing_letter_word[MAX_WORD_LENGTH];
    strcpy(missing_letter_word, word);
    missing_letter_word[i] = '\0';

    if (is_in_dictionary(missing_letter_word)) {
      suggested_spellings[num_suggested_spellings++] = strdup(missing_letter_word);
    }
  }

  // Check for extra letters
  for (int i = 0; i < strlen(word); i++) {
    char extra_letter_word[MAX_WORD_LENGTH];
    strcpy(extra_letter_word, word);
    extra_letter_word[i] = '\0';
    strcat(extra_letter_word, &word[i + 1]);

    if (is_in_dictionary(extra_letter_word)) {
      suggested_spellings[num_suggested_spellings++] = strdup(extra_letter_word);
    }
  }

  // Return the suggested spellings
  return suggested_spellings;
}

// Print the suggested spellings for a word
void print_suggested_spellings(const char *word, char **suggested_spellings) {
  printf("Suggested spellings for \"%s\":\n", word);
  for (int i = 0; i < MAX_WORDS; i++) {
    if (suggested_spellings[i] != NULL) {
      printf("  %s\n", suggested_spellings[i]);
    }
  }
}

// Free the suggested spellings
void free_suggested_spellings(char **suggested_spellings) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (suggested_spellings[i] != NULL) {
      free(suggested_spellings[i]);
    }
  }

  free(suggested_spellings);
}

int main() {
  // Read the dictionary from a file
  read_dictionary("dictionary.txt");

  // Get the word to check
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check: ");
  scanf("%s", word);

  // Check if the word is spelled correctly
  if (is_spelled_correctly(word)) {
    printf("%s is spelled correctly.\n", word);
  } else {
    printf("%s is not spelled correctly.\n", word);

    // Get the suggested spellings for the word
    char **suggested_spellings = get_suggested_spellings(word);

    // Print the suggested spellings
    print_suggested_spellings(word, suggested_spellings);

    // Free the suggested spellings
    free_suggested_spellings(suggested_spellings);
  }

  return 0;
}