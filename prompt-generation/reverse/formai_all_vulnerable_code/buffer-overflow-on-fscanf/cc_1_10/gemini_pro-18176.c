//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

// Global variables
char *words[MAX_WORDS];
int word_count = 0;

// Function to add a word to the dictionary
void add_word(char *word) {
  if (word_count == MAX_WORDS) {
    printf("Error: Dictionary is full.\n");
    return;
  }

  words[word_count] = strdup(word);
  word_count++;
}

// Function to check if a word is in the dictionary
int is_word(char *word) {
  for (int i = 0; i < word_count; i++) {
    if (strcmp(word, words[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Function to load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open dictionary file.\n");
    return;
  }

  char word[MAX_WORD_LEN];
  while (fscanf(fp, "%s", word) != EOF) {
    add_word(word);
  }

  fclose(fp);
}

// Function to check if a message is spam
int is_spam(char *message) {
  // Tokenize the message into words
  char *token = strtok(message, " ");
  while (token != NULL) {
    // Check if the word is in the dictionary
    if (!is_word(token)) {
      return 1; // Spam!
    }

    token = strtok(NULL, " ");
  }

  return 0; // Not spam
}

// Main function
int main(int argc, char **argv) {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Check if the message is spam
  if (is_spam("This is a spam message.")) {
    printf("Spam!\n");
  } else {
    printf("Not spam.\n");
  }

  return 0;
}