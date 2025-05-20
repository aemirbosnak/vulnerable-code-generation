//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 1000

// Create a struct to store a word and its frequency
typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} Word;

// Create a struct to store the dictionary
typedef struct {
  Word words[MAX_DICTIONARY_SIZE];
  int size;
} Dictionary;

// Create a new dictionary
Dictionary* create_dictionary() {
  Dictionary* dictionary = malloc(sizeof(Dictionary));
  dictionary->size = 0;
  return dictionary;
}

// Add a word to the dictionary
void add_word_to_dictionary(Dictionary* dictionary, char* word) {
  // Check if the word is already in the dictionary
  for (int i = 0; i < dictionary->size; i++) {
    if (strcmp(dictionary->words[i].word, word) == 0) {
      dictionary->words[i].frequency++;
      return;
    }
  }

  // If the word is not in the dictionary, add it
  strcpy(dictionary->words[dictionary->size].word, word);
  dictionary->words[dictionary->size].frequency = 1;
  dictionary->size++;
}

// Load the dictionary from a file
void load_dictionary(Dictionary* dictionary, char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening dictionary file\n");
    return;
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file)) {
    // Remove the newline character from the line
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    add_word_to_dictionary(dictionary, line);
  }

  fclose(file);
}

// Check if a word is in the dictionary
int is_word_in_dictionary(Dictionary* dictionary, char* word) {
  for (int i = 0; i < dictionary->size; i++) {
    if (strcmp(dictionary->words[i].word, word) == 0) {
      return 1;
    }
  }

  return 0;
}

// Check the spelling of a word
int check_spelling(Dictionary* dictionary, char* word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is in the dictionary
  if (is_word_in_dictionary(dictionary, word)) {
    return 1;
  } else {
    return 0;
  }
}

// Print the dictionary
void print_dictionary(Dictionary* dictionary) {
  for (int i = 0; i < dictionary->size; i++) {
    printf("%s (%d)\n", dictionary->words[i].word, dictionary->words[i].frequency);
  }
}

// Free the memory allocated for the dictionary
void free_dictionary(Dictionary* dictionary) {
  free(dictionary);
}

int main() {
  // Create a new dictionary
  Dictionary* dictionary = create_dictionary();

  // Load the dictionary from a file
  load_dictionary(dictionary, "romeo_and_juliet.txt");

  // Print the dictionary
  print_dictionary(dictionary);

  // Check the spelling of a word
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check the spelling: ");
  scanf("%s", word);

  if (check_spelling(dictionary, word)) {
    printf("The word is spelled correctly\n");
  } else {
    printf("The word is spelled incorrectly\n");
  }

  // Free the memory allocated for the dictionary
  free_dictionary(dictionary);

  return 0;
}