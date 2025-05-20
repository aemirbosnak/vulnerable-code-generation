//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _trie_node {
  struct _trie_node *children[26];
  int is_word;
} trie_node;

trie_node *create_trie_node() {
  trie_node *node = (trie_node *)malloc(sizeof(trie_node));
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  node->is_word = 0;
  return node;
}

void insert_word(trie_node *root, char *word) {
  trie_node *current = root;
  while (*word) {
    int index = tolower(*word) - 'a';
    if (!current->children[index]) {
      current->children[index] = create_trie_node();
    }
    current = current->children[index];
    word++;
  }
  current->is_word = 1;
}

int search_word(trie_node *root, char *word) {
  trie_node *current = root;
  while (*word) {
    int index = tolower(*word) - 'a';
    if (!current->children[index]) {
      return 0;
    }
    current = current->children[index];
    word++;
  }
  return current->is_word;
}

int main() {
  char dictionary[100000][21];
  int num_words = 0;
  FILE *fp = fopen("dictionary.txt", "r");
  if (!fp) {
    printf("Error opening dictionary file\n");
    return 1;
  }
  while (fscanf(fp, "%s", dictionary[num_words++]) != EOF);
  fclose(fp);

  trie_node *root = create_trie_node();
  for (int i = 0; i < num_words; i++) {
    insert_word(root, dictionary[i]);
  }

  char input[101];
  while (1) {
    printf("Enter a word (or q to quit): ");
    scanf("%s", input);
    if (strcmp(input, "q") == 0) {
      break;
    }
    int found = search_word(root, input);
    printf("%s is %sa word in the dictionary\n", input, found ? "" : "not ");
  }

  return 0;
}