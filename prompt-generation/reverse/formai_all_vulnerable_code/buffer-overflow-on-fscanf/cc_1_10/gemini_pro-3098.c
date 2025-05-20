//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
// Alien Language Translator v1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ALIEN_WORD_LENGTH 100
#define MAX_ENGLISH_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

// Data structures
typedef struct {
  char alien_word[MAX_ALIEN_WORD_LENGTH];
  char english_word[MAX_ENGLISH_WORD_LENGTH];
} dictionary_entry;

// Function prototypes
int load_dictionary(dictionary_entry *dictionary, char *filename);
void print_dictionary(dictionary_entry *dictionary, int size);
void translate_alien_word(dictionary_entry *dictionary, int size, char *alien_word);
void translate_english_word(dictionary_entry *dictionary, int size, char *english_word);

// Main function
int main(int argc, char *argv[]) {
  // Check if the user provided a dictionary file
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Load the dictionary from the file
  dictionary_entry dictionary[MAX_DICTIONARY_SIZE];
  int dictionary_size = load_dictionary(dictionary, argv[1]);
  if (dictionary_size == -1) {
    fprintf(stderr, "Error loading dictionary file\n");
    return EXIT_FAILURE;
  }

  // Print the dictionary
  // print_dictionary(dictionary, dictionary_size);

  // Get the alien word to translate
  char alien_word[MAX_ALIEN_WORD_LENGTH];
  printf("Enter the alien word to translate: ");
  scanf("%s", alien_word);

  // Translate the alien word
  translate_alien_word(dictionary, dictionary_size, alien_word);

  // Get the English word to translate
  char english_word[MAX_ENGLISH_WORD_LENGTH];
  printf("Enter the English word to translate: ");
  scanf("%s", english_word);

  // Translate the English word
  translate_english_word(dictionary, dictionary_size, english_word);

  return EXIT_SUCCESS;
}

// Function to load the dictionary from a file
int load_dictionary(dictionary_entry *dictionary, char *filename) {
  // Open the dictionary file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  // Read the dictionary entries
  int i = 0;
  while (fscanf(fp, "%s %s", dictionary[i].alien_word, dictionary[i].english_word) != EOF) {
    i++;
  }

  // Close the dictionary file
  fclose(fp);

  return i;
}

// Function to print the dictionary
void print_dictionary(dictionary_entry *dictionary, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s %s\n", dictionary[i].alien_word, dictionary[i].english_word);
  }
}

// Function to translate an alien word
void translate_alien_word(dictionary_entry *dictionary, int size, char *alien_word) {
  // Search for the alien word in the dictionary
  for (int i = 0; i < size; i++) {
    if (strcmp(dictionary[i].alien_word, alien_word) == 0) {
      // Print the English translation
      printf("English translation: %s\n", dictionary[i].english_word);
      return;
    }
  }

  // The alien word was not found in the dictionary
  printf("Alien word not found in dictionary\n");
}

// Function to translate an English word
void translate_english_word(dictionary_entry *dictionary, int size, char *english_word) {
  // Search for the English word in the dictionary
  for (int i = 0; i < size; i++) {
    if (strcmp(dictionary[i].english_word, english_word) == 0) {
      // Print the Alien translation
      printf("Alien translation: %s\n", dictionary[i].alien_word);
      return;
    }
  }

  // The English word was not found in the dictionary
  printf("English word not found in dictionary\n");
}