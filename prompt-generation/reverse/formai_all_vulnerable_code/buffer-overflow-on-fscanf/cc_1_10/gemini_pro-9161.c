//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_WORDS 10000

// Create a node for the trie
typedef struct trie_node {
  char letter;
  int is_word;
  struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *trie_create_node(char letter) {
  trie_node *node = malloc(sizeof(trie_node));
  node->letter = letter;
  node->is_word = 0;
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  return node;
}

// Insert a word into the trie
void trie_insert(trie_node **root, char *word) {
  if (*root == NULL) {
    *root = trie_create_node(word[0]);
  }
  trie_node *current_node = *root;
  int i = 1;
  while (word[i] != '\0') {
    int index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      current_node->children[index] = trie_create_node(word[i]);
    }
    current_node = current_node->children[index];
    i++;
  }
  current_node->is_word = 1;
}

// Check if a word is in the trie
int trie_search(trie_node *root, char *word) {
  if (root == NULL) {
    return 0;
  }
  trie_node *current_node = root;
  int i = 0;
  while (word[i] != '\0') {
    int index = word[i] - 'a';
    if (current_node->children[index] == NULL) {
      return 0;
    }
    current_node = current_node->children[index];
    i++;
  }
  return current_node->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node **root, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    trie_insert(root, word);
  }
  fclose(file);
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
  return trie_search(root, word);
}

// Suggest corrections for a misspelled word
void suggest_corrections(trie_node *root, char *word) {
  // TODO: Implement this function
}

// Print the trie
void print_trie(trie_node *root) {
  if (root == NULL) {
    return;
  }
  printf("%c", root->letter);
  if (root->is_word) {
    printf(" (word)");
  }
  printf("\n");
  for (int i = 0; i < 26; i++) {
    print_trie(root->children[i]);
  }
}

// Free the trie
void free_trie(trie_node *root) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < 26; i++) {
    free_trie(root->children[i]);
  }
  free(root);
}

int main() {
  // Create the trie
  trie_node *root = NULL;

  // Load the dictionary into the trie
  load_dictionary(&root, "dictionary.txt");

  // Check the spelling of a word
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check the spelling: ");
  scanf("%s", word);
  int is_correct = check_spelling(root, word);
  if (is_correct) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is spelled incorrectly.\n");
    // Suggest corrections for the misspelled word
    suggest_corrections(root, word);
  }

  // Print the trie
  printf("The trie:\n");
  print_trie(root);

  // Free the trie
  free_trie(root);

  return 0;
}