//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Create a hash table to store the dictionary
typedef struct node {
  char *word;
  struct node *next;
} node;

node *hash_table[26];

// Hash function to convert a word to an index in the hash table
int hash(char *word) {
  return tolower(word[0]) - 'a';
}

// Insert a word into the hash table
void insert(char *word) {
  int index = hash(word);
  node *new_node = malloc(sizeof(node));
  new_node->word = strdup(word);
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

// Check if a word is in the hash table
int find(char *word) {
  int index = hash(word);
  node *current = hash_table[index];
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// Load the dictionary into the hash table
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening dictionary file: %s\n", filename);
    exit(1);
  }
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert(word);
  }
  fclose(file);
}

// Check the spelling of a word
int check_spelling(char *word) {
  return find(word);
}

// Get a word from the user
char *get_word() {
  char *word = malloc(MAX_WORD_LENGTH);
  printf("Enter a word: ");
  scanf("%s", word);
  return word;
}

// Print the results of the spell check
void print_results(char *word, int result) {
  if (result == 1) {
    printf("%s is spelled correctly.\n", word);
  } else {
    printf("%s is spelled incorrectly.\n", word);
  }
}

// Main function
int main() {
  // Load the dictionary into the hash table
  load_dictionary("dictionary.txt");

  // Get a word from the user
  char *word = get_word();

  // Check the spelling of the word
  int result = check_spelling(word);

  // Print the results of the spell check
  print_results(word, result);

  // Free the allocated memory
  free(word);

  return 0;
}