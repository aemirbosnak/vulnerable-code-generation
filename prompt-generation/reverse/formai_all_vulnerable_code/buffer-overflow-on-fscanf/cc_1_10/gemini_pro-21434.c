//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// The dictionary of words
char *dictionary[MAX_WORDS];

// The number of words in the dictionary
int num_words = 0;

// The input text
char *text;

// The number of characters in the input text
int text_length = 0;

// The misspelled words
char *misspelled_words[MAX_WORDS];

// The number of misspelled words
int num_misspelled_words = 0;

// Function to load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening dictionary file '%s'\n", filename);
    exit(1);
  }

  // Read the words from the file
  while (fscanf(file, "%s", dictionary[num_words]) != EOF) {
    num_words++;
  }

  fclose(file);
}

// Function to load the input text from a file
void load_text(char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening text file '%s'\n", filename);
    exit(1);
  }

  // Get the length of the file
  fseek(file, 0, SEEK_END);
  text_length = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the text
  text = malloc(text_length + 1);

  // Read the text from the file
  fread(text, 1, text_length, file);

  fclose(file);
}

// Function to check the spelling of a word
int check_spelling(char *word) {
  for (int i = 0; i < num_words; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Function to find the misspelled words in the input text
void find_misspelled_words() {
  char *word = strtok(text, " ");

  while (word != NULL) {
    if (!check_spelling(word)) {
      misspelled_words[num_misspelled_words] = strdup(word);
      num_misspelled_words++;
    }

    word = strtok(NULL, " ");
  }
}

// Function to print the misspelled words
void print_misspelled_words() {
  printf("Misspelled words:\n");

  for (int i = 0; i < num_misspelled_words; i++) {
    printf("%s\n", misspelled_words[i]);
  }
}

// Function to free the memory allocated for the misspelled words
void free_misspelled_words() {
  for (int i = 0; i < num_misspelled_words; i++) {
    free(misspelled_words[i]);
  }
}

int main() {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Load the input text
  load_text("text.txt");

  // Find the misspelled words
  find_misspelled_words();

  // Print the misspelled words
  print_misspelled_words();

  // Free the memory allocated for the misspelled words
  free_misspelled_words();

  return 0;
}