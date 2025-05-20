//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: calm
// Spell Checker Program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a word is a valid word
int is_valid_word(char *word, char **dictionary, int dict_size) {
  for (int i = 0; i < dict_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a word is a misspelling
int is_misspelling(char *word, char **dictionary, int dict_size) {
  int misspelling = 0;
  for (int i = 0; i < strlen(word); i++) {
    if (!isalpha(word[i])) {
      misspelling = 1;
      break;
    }
  }
  if (!misspelling && !is_valid_word(word, dictionary, dict_size)) {
    misspelling = 1;
  }
  return misspelling;
}

// Main function
int main() {
  // Dictionary of valid words
  char *dictionary[] = {"hello", "world", "goodbye", "cruel", "world"};
  int dict_size = sizeof(dictionary) / sizeof(char*);

  // Input sentence
  char sentence[100];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Check if each word in the sentence is a valid word
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    if (is_misspelling(token, dictionary, dict_size)) {
      printf("Misspelling: %s\n", token);
    }
    token = strtok(NULL, " ");
  }

  return 0;
}