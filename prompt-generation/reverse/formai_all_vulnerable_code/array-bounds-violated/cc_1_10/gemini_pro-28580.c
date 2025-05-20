//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000 // Maximum number of words in the dictionary
#define MAX_WORD_LENGTH 20 // Maximum length of a word in the dictionary

// Structure to store a word and its frequency
typedef struct word_freq {
  char word[MAX_WORD_LENGTH + 1]; // Word
  int freq; // Frequency of the word
} word_freq;

// Structure to store the dictionary
typedef struct dictionary {
  word_freq words[MAX_WORDS]; // Array of words and their frequencies
  int num_words; // Number of words in the dictionary
} dictionary;

// Function to compare two words
int compare_words(const void* a, const void* b) {
  word_freq* wa = (word_freq*)a;
  word_freq* wb = (word_freq*)b;
  return strcmp(wa->word, wb->word);
}

// Function to load the dictionary from a file
int load_dictionary(dictionary* dict, const char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1; // Error opening the file
  }

  int num_words = 0;
  char line[MAX_WORD_LENGTH + 1];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Convert the word to lowercase
    for (int i = 0; line[i] != '\0'; i++) {
      line[i] = tolower(line[i]);
    }

    // Add the word to the dictionary
    strcpy(dict->words[num_words].word, line);
    dict->words[num_words].freq = 0;
    num_words++;
  }

  fclose(fp);

  dict->num_words = num_words;
  return 0; // Success
}

// Function to spell check a word
int spell_check(dictionary* dict, const char* word) {
  // Convert the word to lowercase
  char lower_word[MAX_WORD_LENGTH + 1];
  for (int i = 0; word[i] != '\0'; i++) {
    lower_word[i] = tolower(word[i]);
  }
  lower_word[strlen(word)] = '\0';

  // Binary search for the word in the dictionary
  word_freq key;
  strcpy(key.word, lower_word);
  word_freq* result = bsearch(&key, dict->words, dict->num_words, sizeof(word_freq), compare_words);

  // Return the frequency of the word (0 if not found)
  if (result == NULL) {
    return 0;
  } else {
    return result->freq;
  }
}

// Function to check if a word is misspelled
int is_misspelled(dictionary* dict, const char* word) {
  return spell_check(dict, word) == 0;
}

// Function to print the misspelled words in a sentence
void print_misspelled_words(dictionary* dict, const char* sentence) {
  // Tokenize the sentence
  char* tokens[MAX_WORDS];
  int num_tokens = 0;
  char* token = strtok(sentence, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Check each token for misspellings
  printf("Misspelled words: ");
  for (int i = 0; i < num_tokens; i++) {
    if (is_misspelled(dict, tokens[i])) {
      printf("%s ", tokens[i]);
    }
  }
  printf("\n");
}

int main() {
  // Load the dictionary
  dictionary dict;
  if (load_dictionary(&dict, "dictionary.txt") != 0) {
    fprintf(stderr, "Error loading the dictionary!\n");
    return 1;
  }

  // Get the sentence from the user
  char sentence[1000];
  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  // Print the misspelled words
  print_misspelled_words(&dict, sentence);

  return 0;
}