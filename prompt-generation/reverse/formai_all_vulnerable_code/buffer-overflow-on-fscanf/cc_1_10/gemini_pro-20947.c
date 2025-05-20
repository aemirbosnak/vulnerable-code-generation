//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *word;
  struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->word = strdup(word);
  new_node->next = head;
  head = new_node;
}

int search(char *word) {
  node_t *current = head;
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <dictionary>\n", argv[0]);
    return 1;
  }

  FILE *dictionary = fopen(argv[1], "r");
  if (dictionary == NULL) {
    fprintf(stderr, "Could not open dictionary file: %s\n", argv[1]);
    return 1;
  }

  char word[100];
  while (fscanf(dictionary, "%s", word) != EOF) {
    insert(word);
  }

  fclose(dictionary);

  while (1) {
    printf("Enter a word to check, or '.' to quit: ");
    scanf("%s", word);
    if (strcmp(word, ".") == 0) {
      break;
    }

    int found = search(word);
    if (found) {
      printf("%s is a word.\n", word);
    } else {
      printf("%s is not a word.\n", word);
    }
  }

  return 0;
}